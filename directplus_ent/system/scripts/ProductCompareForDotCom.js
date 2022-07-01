/**
 * 使用環境によるドメインの変更
 */
function changeDomain(){

 	var mode = $("#DevelopmentMode").val();
 	var domain = "";
	if(mode == "PRO") {
		// 本番用ドメイン
		domain = "h20547.www2.hp.com";
		
	} else if (mode == "ITG") {
		// ITG用ドメイン
		domain = "dpion01.atlanta.hp.com";

	} else if (mode == "DEV") {
		// DEV用ドメイン
		domain = "dpdon1.atlanta.hp.com";
	} else{
		// 指定がない場合は本番用ドメイン
		domain = "h20547.www2.hp.com";
	}

	return domain;
}


/**
 * 比較リンク初期表示
 */
$(document).ready(function(){
	
	// 画面ロード時に比較カートを表示する
	loadCompareCart();
	
	// 初期表示で各比較ボタンにユニークなIDを振り分ける
	for(var i = 0; $("a[name=compareAdd]").length > i; i++) {
		$("a[name=compareAdd]")[i].id = "add" + i
		$("a[name=compareAdd]").children('img')[i].id = "imgadd" + i
	}
	
	// ImgIDの存在確認を行い、ImgIDが存在する場合、ボタンを「比較済み」に変更する
	var imgIdCookie = getImgID();
	if(typeof imgIdCookie != "undefined" && imgIdCookie != "") {
		imgIdCookie = imgIdCookie.replace("=", "");
		document.getElementById(imgIdCookie).src="/directplus/system/images/btn_spec_comp_green1_on.gif";
	}
	
	var d = new $.Deferred();
	
	//変数を定義
	var formData = $("#productCompareForm");
	var fomDataArray = formData.serializeArray();
	var domain = changeDomain();
	var url = "http://" + domain + "/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ProductCompare-Active";
	
	//CSessionIDを取得
	var sid = getCSessionID();
	
	// .COMページ用CategoryName
	var name = "CCategoryName";
	
	// 発行したクッキーの取得（読み込み）
	if (document.cookie) {
		var cookies = document.cookie.split("; ");
		for (var i = 0; i < cookies.length; i++) {
			var str = cookies[i].split("=");
			if (str[0] == name) {
				var cookie_value = unescape(str[1]);
				break;
			}
		}
	}
	
	// CategoryNameが存在する場合はURLに付与する
	var cateName = "";
	if (typeof cookie_value != "undefined") {
		cateName = "&CategoryName=" + cookie_value;
	}
	
	// CSessionIDが存在する場合はURLに付与する
	if (typeof sid != "undefined" && sid != "") {
		url = url + ";sid=" + sid;
	}
	
	$("#compareLinkLabel")
		.load(
			 url + "?DotComFlag=true" + cateName
			, null
			, function(){
				// ヘッダー画像名から個人/法人を判別し、.COMページ初期表示時の比較リンク遷移先を決定する
				var headerImgs = $('#header').find('img');
				for(var i = 0;  i < headerImgs.length; i++) {
					if(headerImgs[i].src.indexOf('nvtop_business_title22050.gif') > 0) {
						var compareLinkUrl = $("#compareLinkBody").children('a')[0].href;
						compareLinkUrl = compareLinkUrl.replace("ViewConsumer", "ViewBusiness");
						$("#compareLinkBody a").attr("href", compareLinkUrl)
					}
				}
				d.resolve();
			}
		);
	
	return d.promise();

});

/**
 * 比較カート表示
 */
function loadCompareCart(){

	var domain = changeDomain();

	// 比較カート表示URL
	var linkUrl = "http://" + domain + "/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ProductCompare-View;";
	// CSessionIDを取得する
	var sid = getCSessionID();
	
	// CSessionIDの存在確認を行い、存在する場合はURLに付与する
	if (typeof sid != "undefined") {
		linkUrl = linkUrl + ";sid=" + sid;
	}

	// .COMページ用CategoryName
	var name = "CCategoryName";

	// 発行したクッキーの取得（読み込み）
	if (document.cookie) {
		var cookies = document.cookie.split("; ");
		for (var i = 0; i < cookies.length; i++) {
			var str = cookies[i].split("=");
			if (str[0] == name) {
				var cookie_value = unescape(str[1]);
				break;
			}
		}
	}
	
	// CategoryNameが存在する場合はCategoryNameを書き換える
	if (typeof cookie_value != "undefined") {
		document.getElementById("CategoryName").value = cookie_value
	}
	
	var d = new $.Deferred();
	var formData = $("#productCompareForm");
	var fomDataArray=formData.serializeArray();

	// 非同期処理時にご愛顧に遷移した際のステータスを追加
	fomDataArray.push({name: 'AjaxFlg', value: "true"});
	
	$("#compareCart")
		.load(
			linkUrl + "?DotComFlag=true"
			, fomDataArray
			, function(){
				// 比較カートに投入されている製品タイプから比較リンク遷移先を決定する
				var compareCartClasses = $('#compareCart').find('div');
				var pcTransFlg = 0;
				if(compareCartClasses.length > 0) {
					for(var i = 0; i < compareCartClasses.length; i++) {
						// PCが投入されていない場合、プリンター比較ページに遷移する
						if(compareCartClasses[i].className == ('compBox_pc')) {
							pcTransFlg = 1;
						}
					}
					if(pcTransFlg != 1 && compareCartClasses.hasClass("compBox_printer")) {
						var compareLinkUrl = $("#compareLinkBody").children('a')[0].href;
						compareLinkUrl = compareLinkUrl.replace("CompareType=1", "CompareType=2");
						$("#compareLinkBody a").attr("href", compareLinkUrl)
					}
				}

				// ヘッダー画像名から個人/法人を判別し、.比較カートの遷移先を決定する
				var headerImgs = $('#header').find('img');
				var compareCartUrl = "";
				for(var j = 0;  j < headerImgs.length; j++) {
					if(headerImgs[j].src.indexOf('nvtop_business_title22050.gif') > 0) {
						var compareCartUrls = $("#compareCart").find('a');
						for(var k = 0; k < compareCartUrls.length; k++) {
							compareCartUrl = compareCartUrls[k].href.replace("ViewConsumer", "ViewBusiness");
							$("#compareCart").find('a')[k].href = compareCartUrl;
						}
					}
				}

				// compareCartBodyの存在チェック
				if($("#compareCartBody").size() == 0 && $("#compareCart").size() > 0){
					$("#compareCart").css("display", "none");
				}
				d.resolve();
			}
		);
	return d.promise();
}


/**
 * 比較カート追加時のリンクを作成(.COMページ用)
 * 
 */
 function createCompareLinkByDoteCom(str, imgId) {
 
	// 比較済みの場合、処理を行わない
	var imgsrc = document.getElementById("img" + imgId).src;
	if(imgsrc.indexOf('btn_com_insert.gif') == -1) {
		return false;
	}

 	// パラメータをカンマ区切りで分割する
 	var params = str.split(',');
 	
 	// URLに付与するパラメータ
 	var baseId = "";
 	var seriId = "";
 	var campaignId = ""
 	
 	// FormのCategoryNameを決定する値
 	var site = "";
 	var category = "";
 	
 	// URLの作成パターンを決定する
 	// 製品キーがSeriID & BaseIDの場合:1
 	// 製品キーがCampaginIDの場合:2
 	var urlPattern = "2";
 	for(var i = 0; params.length > i ; i++){
 		var arr = params[i].split('=');
 		
 		// パラメーター設定部
 		if(arr[0] == "SeriesID") {
 			urlPattern = "1";
 			seriId = arr[1];
 		} else if(arr[0] == "BaseID") {
 			urlPattern = "1";
 			baseId = arr[1];
 		} else if (arr[0] == "CampaignID") {
 			campaginId = arr[1];
 		}
 		
 		// CategoryName設定部
 		if(arr[0] == "Site") {
 			site = arr[1];
 		} else if(arr[0] == "Category") {
 			category = arr[1];
 		}
 	}
 	
	// CategoryNameからpipelineを決定する
	var viewBasketPipeline = "";
	if(site == "Consumer") {
		viewBasketPipeline = "Consumer";
	} else if(site == "Business") {
		viewBasketPipeline = "Business";
	}
 	
 	// ドメインの設定
 	var domain = changeDomain();
	
	// 共通cookieUrl,basketUrlの作成
 	var cartUrl = "http://" + domain + "/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ProductCompare-View";
 	var linkUrl = "http://" + domain + "/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ProductCompare-Active";
 	
 	if(urlPattern == "2") {
 	
 		// Usage用cookieUrl,basketUrlの作成
 		var cookieUrl = "http://" + domain + "/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ProductCompare-StartDotCom?CampaignCode=" + campaginId;
 		var basketUrl = "http://" + domain + "/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ViewBasketFor"+ viewBasketPipeline + "-DirectCartAdd?CampaignCode=" + campaginId;
		
 	} else {
 	
 		// Spec用cookieUrl,basketUrlの作成
 		var cookieUrl = "http://" + domain + "/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ProductCompare-StartDotCom?WebCategoryID=" + seriId + "&BaseID=" + baseId + "&ProductName=fromDotCom";
 		var basketUrl = "http://" + domain + "/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ViewBasketFor"+ viewBasketPipeline + "-ProductCompareSpecAdd?WebCategoryID=" + seriId + "&BaseID=" + baseId + "&ProductName=fromDotCom";
 	
 	}
 	
 	// productCompareFormのCategoryNameを書き換える
 	var categoryName = setCategoryName(site, category);
 	
	// 比較カート追加処理の関数の呼び出し
	addCompareCartByDotCom(
	'productCompareForm',
	cookieUrl,
	cartUrl,
	linkUrl,
	imgId);
 }

/**
 * CategoryNameを決定する
 */
function setCategoryName(site, category){

	// CategoryName
	var categoryName = "";
	var siteCateName = "";

	// CategoryNameの前方部分（サイト種別部分）を決定する
	if(site == "Consumer") {
		siteCateName = "DPC";
	} else if(site == "Business") {
		siteCateName = "DPB"
	}

	// categoryがWorkstationの場合、Wをwに変換
	if(category == "Workstation") {
		category = "workstation"
	}

	categoryName = siteCateName + category;
	
	document.getElementById("CategoryName").value = categoryName;
	
	return categoryName;
}


/**
 * 比較カート追加処理(.COMページ用)
 * 
 */
function addCompareCartByDotCom(targetForm, cookieUrl, cartUrl, linkUrl, imgId) {
	
	// 比較ページを別ウィンドウで表示する
	openComparePage(cookieUrl, imgId);
	
	// CSessionIDの存在確認を行う
	var sid = getCSessionID();
	
	var formData = $("#" + targetForm);
	var fomDataArray=formData.serializeArray();
	
	// エラーフラグを設定する
	var errorFlg = false;
	
	go()
	.then(
		// cookie書込
		function()
		{
			
			// CSessionIDが存在する場合はURLに付与する
			if (typeof sid != "undefined" && sid != "") {
				var splitCookieUrl = cookieUrl.split("?");
				cookieUrl = splitCookieUrl[0] + ";sid=" + sid + "?" + splitCookieUrl[1];
			}
			
			var d = new $.Deferred();
			
			$("#RetProductCompareStatus")
				.load(
					cookieUrl + "&DotComFlag=true"
					, fomDataArray
					, function()
					{
						// エラーのISMLの場合、flgを変更
						if(0 < $("#ErrorFlg").size()){
							errorFlg=true;
						}
						if (isProductCompareStatus($("#ProductCompareStatus").val())) 
						{
							d.resolve();
						} else {
							d.reject();
						}
					}
				);
			return d.promise();
		}
	).then(
		// cookie読込(比較カート表示)
		function()
		{
			var d = new $.Deferred();
			
			// URLにsidを付与する
			cartUrl = cartUrl + ";sid=" + sid;
			
			// cookie書込の処理結果hidden値を取得
			fomDataArray=formData.serializeArray();
			
			// 取得できない値をSETしなおす
			fomDataArray.push({name: 'ProductCompareStatus', value: $("#ProductCompareStatus").val()});
			fomDataArray.push({name: 'ProductCompareLineItemKey', value: $("#ProductCompareLineItemKey").val()});
			// 非同期処理時にご愛顧に遷移した際のステータスを追加
			fomDataArray.push({name: 'AjaxFlg', value: "true"});
			
			$("#compareCart")
				.load(
					cartUrl + "?DotComFlag=true"
					, fomDataArray
					, function(){
						// エラーのISMLの場合、flgを変更
						if(0 < $("#ErrorFlg").size()){
							errorFlg=true;
						}
						d.resolve();
					}
				);
			return d.promise();
		}
	).then(
	    // 比較リンク更新
		function()
		{
			var d = new $.Deferred();
			
			// URLにsidを付与する
			linkUrl = linkUrl + ";sid=" + sid;
			
			$("#compareLinkLabel")
				.load(
					linkUrl + "?DotComFlag=true"
					, fomDataArray
					, function(){
						// エラーのISMLの場合、flgを変更
						if(0 < $("#ErrorFlg").size()){
							errorFlg=true;
						}
						d.resolve();
					}
				);
			return d.promise();	
		}
	);
	
	// 初回だけリロード
	if(sid == "") {
		setTimeout("location.reload()",5000);
	}
}


/** 
 * 先に進む
 * 
 */
function go() {
	var d = new $.Deferred();
	d.resolve();
	return d.promise();
}


/** 
 * 比較カート追加/削除処理のステータスチェック
 * 
 */
function isProductCompareStatus(status)
{
	if ("CountErr" == status) 
	{
		alert("比較一覧で表示できる数は最大10製品迄です。");
		return false;
	} 
	else if ("ConfigError" == status)  
	{
		alert("この製品は比較できません。");
		return false;
	}
	else if ("ExecErr" == status)  
	{
		alert("処理中です。");
		return false;
	}
	return true;
}


/** 
 * .COMページ用SessionIDを取得する
 * 
 */
function getCSessionID() {

	// .COMページ用SessionID名
	var name = "CSessionID";
	var cookie_value = "";

	// 発行したクッキーの取得（読み込み）
	if (document.cookie) {
		var cookies = document.cookie.split("; ");
		for (var i = 0; i < cookies.length; i++) {
			var str = cookies[i].split("=");
			if (str[0] == name) {
				var cookie_value = unescape(str[1] + "=");
				break;
			}
		}
	}
	
	if(cookie_value != "") {
		cookie_value = cookie_value.replace("\"", "");
	}
	
	return cookie_value;
}


/** 
 * imgIDを取得する
 * 
 */
function getImgID() {

	// ImgID名
	var name = "ImgID";
	var cookie_value = "";

	// 発行したクッキーの取得（読み込み）
	if (document.cookie) {
		var cookies = document.cookie.split("; ");
		for (var i = 0; i < cookies.length; i++) {
			var str = cookies[i].split("=");
			if (str[0] == name) {
				var cookie_value = unescape(str[1] + "=");
				break;
			}
		}
	}
	
	if(cookie_value != "") {
		cookie_value = cookie_value.replace("\"", "");
	}
	
	return cookie_value;
}


/**
 * 比較ページを別ウィンドウで表示
 */
function openComparePage(cookieUrl, imgId) {

	// 比較ボタン切り替え
	document.getElementById("img" + imgId).src="/directplus/system/images/btn_spec_comp_green1_on.gif";

	// 別ウィンドウで開く比較ページのURL
	var splitUrl = cookieUrl.split("?");
	var domain = changeDomain();
	var pageUrl = "http://" + domain +"/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ProductCompare-OpenComparePageForDotCom?" + splitUrl[1] + "&OpenComparePageFlg=1";

	// ImgIDの存在確認を行い、ImgIDが存在する場合、URLに付与する
	var imgIdCookie = getImgID();
	if(typeof imgIdCookie == "undefined" || imgIdCookie == "") {
		pageUrl = pageUrl + "&ImgID=img" + imgId;
	}

	// CSessionIDを取得する
	var sid = getCSessionID();

	// CSessionIDの存在確認を行い、CSessionIDが存在する場合、URLに付与する
	if(typeof sid != "undefined" && sid != "") {
		var splitPageUrl = pageUrl.split("?");
		pageUrl = splitPageUrl[0] + ";sid=" + sid + "?" + splitPageUrl[1];
	}

	//比較ページを別ウィンドウで開く
	document.productCompareForm.target = "comparePage";
	document.productCompareForm.method = "post";
	document.productCompareForm.action = pageUrl;
	document.productCompareForm.submit();

}


/** 
 * 比較カートクローズ
 * 
 */
function cartClose(){
	document.getElementById("compareCartBody").style.display="none";
}
