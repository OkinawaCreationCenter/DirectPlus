/**
 * �g�p���ɂ��h���C���̕ύX
 */
function changeDomain(){

 	var mode = $("#DevelopmentMode").val();
 	var domain = "";
	if(mode == "PRO") {
		// �{�ԗp�h���C��
		domain = "h20547.www2.hp.com";
		
	} else if (mode == "ITG") {
		// ITG�p�h���C��
		domain = "dpion01.atlanta.hp.com";

	} else if (mode == "DEV") {
		// DEV�p�h���C��
		domain = "dpdon1.atlanta.hp.com";
	} else{
		// �w�肪�Ȃ��ꍇ�͖{�ԗp�h���C��
		domain = "h20547.www2.hp.com";
	}

	return domain;
}


/**
 * ��r�����N�����\��
 */
$(document).ready(function(){
	
	// ��ʃ��[�h���ɔ�r�J�[�g��\������
	loadCompareCart();
	
	// �����\���Ŋe��r�{�^���Ƀ��j�[�N��ID��U�蕪����
	for(var i = 0; $("a[name=compareAdd]").length > i; i++) {
		$("a[name=compareAdd]")[i].id = "add" + i
		$("a[name=compareAdd]").children('img')[i].id = "imgadd" + i
	}
	
	// ImgID�̑��݊m�F���s���AImgID�����݂���ꍇ�A�{�^�����u��r�ς݁v�ɕύX����
	var imgIdCookie = getImgID();
	if(typeof imgIdCookie != "undefined" && imgIdCookie != "") {
		imgIdCookie = imgIdCookie.replace("=", "");
		document.getElementById(imgIdCookie).src="/directplus/system/images/btn_spec_comp_green1_on.gif";
	}
	
	var d = new $.Deferred();
	
	//�ϐ����`
	var formData = $("#productCompareForm");
	var fomDataArray = formData.serializeArray();
	var domain = changeDomain();
	var url = "http://" + domain + "/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ProductCompare-Active";
	
	//CSessionID���擾
	var sid = getCSessionID();
	
	// .COM�y�[�W�pCategoryName
	var name = "CCategoryName";
	
	// ���s�����N�b�L�[�̎擾�i�ǂݍ��݁j
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
	
	// CategoryName�����݂���ꍇ��URL�ɕt�^����
	var cateName = "";
	if (typeof cookie_value != "undefined") {
		cateName = "&CategoryName=" + cookie_value;
	}
	
	// CSessionID�����݂���ꍇ��URL�ɕt�^����
	if (typeof sid != "undefined" && sid != "") {
		url = url + ";sid=" + sid;
	}
	
	$("#compareLinkLabel")
		.load(
			 url + "?DotComFlag=true" + cateName
			, null
			, function(){
				// �w�b�_�[�摜������l/�@�l�𔻕ʂ��A.COM�y�[�W�����\�����̔�r�����N�J�ڐ�����肷��
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
 * ��r�J�[�g�\��
 */
function loadCompareCart(){

	var domain = changeDomain();

	// ��r�J�[�g�\��URL
	var linkUrl = "http://" + domain + "/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ProductCompare-View;";
	// CSessionID���擾����
	var sid = getCSessionID();
	
	// CSessionID�̑��݊m�F���s���A���݂���ꍇ��URL�ɕt�^����
	if (typeof sid != "undefined") {
		linkUrl = linkUrl + ";sid=" + sid;
	}

	// .COM�y�[�W�pCategoryName
	var name = "CCategoryName";

	// ���s�����N�b�L�[�̎擾�i�ǂݍ��݁j
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
	
	// CategoryName�����݂���ꍇ��CategoryName������������
	if (typeof cookie_value != "undefined") {
		document.getElementById("CategoryName").value = cookie_value
	}
	
	var d = new $.Deferred();
	var formData = $("#productCompareForm");
	var fomDataArray=formData.serializeArray();

	// �񓯊��������ɂ����ڂɑJ�ڂ����ۂ̃X�e�[�^�X��ǉ�
	fomDataArray.push({name: 'AjaxFlg', value: "true"});
	
	$("#compareCart")
		.load(
			linkUrl + "?DotComFlag=true"
			, fomDataArray
			, function(){
				// ��r�J�[�g�ɓ�������Ă��鐻�i�^�C�v�����r�����N�J�ڐ�����肷��
				var compareCartClasses = $('#compareCart').find('div');
				var pcTransFlg = 0;
				if(compareCartClasses.length > 0) {
					for(var i = 0; i < compareCartClasses.length; i++) {
						// PC����������Ă��Ȃ��ꍇ�A�v�����^�[��r�y�[�W�ɑJ�ڂ���
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

				// �w�b�_�[�摜������l/�@�l�𔻕ʂ��A.��r�J�[�g�̑J�ڐ�����肷��
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

				// compareCartBody�̑��݃`�F�b�N
				if($("#compareCartBody").size() == 0 && $("#compareCart").size() > 0){
					$("#compareCart").css("display", "none");
				}
				d.resolve();
			}
		);
	return d.promise();
}


/**
 * ��r�J�[�g�ǉ����̃����N���쐬(.COM�y�[�W�p)
 * 
 */
 function createCompareLinkByDoteCom(str, imgId) {
 
	// ��r�ς݂̏ꍇ�A�������s��Ȃ�
	var imgsrc = document.getElementById("img" + imgId).src;
	if(imgsrc.indexOf('btn_com_insert.gif') == -1) {
		return false;
	}

 	// �p�����[�^���J���}��؂�ŕ�������
 	var params = str.split(',');
 	
 	// URL�ɕt�^����p�����[�^
 	var baseId = "";
 	var seriId = "";
 	var campaignId = ""
 	
 	// Form��CategoryName�����肷��l
 	var site = "";
 	var category = "";
 	
 	// URL�̍쐬�p�^�[�������肷��
 	// ���i�L�[��SeriID & BaseID�̏ꍇ:1
 	// ���i�L�[��CampaginID�̏ꍇ:2
 	var urlPattern = "2";
 	for(var i = 0; params.length > i ; i++){
 		var arr = params[i].split('=');
 		
 		// �p�����[�^�[�ݒ蕔
 		if(arr[0] == "SeriesID") {
 			urlPattern = "1";
 			seriId = arr[1];
 		} else if(arr[0] == "BaseID") {
 			urlPattern = "1";
 			baseId = arr[1];
 		} else if (arr[0] == "CampaignID") {
 			campaginId = arr[1];
 		}
 		
 		// CategoryName�ݒ蕔
 		if(arr[0] == "Site") {
 			site = arr[1];
 		} else if(arr[0] == "Category") {
 			category = arr[1];
 		}
 	}
 	
	// CategoryName����pipeline�����肷��
	var viewBasketPipeline = "";
	if(site == "Consumer") {
		viewBasketPipeline = "Consumer";
	} else if(site == "Business") {
		viewBasketPipeline = "Business";
	}
 	
 	// �h���C���̐ݒ�
 	var domain = changeDomain();
	
	// ����cookieUrl,basketUrl�̍쐬
 	var cartUrl = "http://" + domain + "/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ProductCompare-View";
 	var linkUrl = "http://" + domain + "/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ProductCompare-Active";
 	
 	if(urlPattern == "2") {
 	
 		// Usage�pcookieUrl,basketUrl�̍쐬
 		var cookieUrl = "http://" + domain + "/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ProductCompare-StartDotCom?CampaignCode=" + campaginId;
 		var basketUrl = "http://" + domain + "/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ViewBasketFor"+ viewBasketPipeline + "-DirectCartAdd?CampaignCode=" + campaginId;
		
 	} else {
 	
 		// Spec�pcookieUrl,basketUrl�̍쐬
 		var cookieUrl = "http://" + domain + "/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ProductCompare-StartDotCom?WebCategoryID=" + seriId + "&BaseID=" + baseId + "&ProductName=fromDotCom";
 		var basketUrl = "http://" + domain + "/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ViewBasketFor"+ viewBasketPipeline + "-ProductCompareSpecAdd?WebCategoryID=" + seriId + "&BaseID=" + baseId + "&ProductName=fromDotCom";
 	
 	}
 	
 	// productCompareForm��CategoryName������������
 	var categoryName = setCategoryName(site, category);
 	
	// ��r�J�[�g�ǉ������̊֐��̌Ăяo��
	addCompareCartByDotCom(
	'productCompareForm',
	cookieUrl,
	cartUrl,
	linkUrl,
	imgId);
 }

/**
 * CategoryName�����肷��
 */
function setCategoryName(site, category){

	// CategoryName
	var categoryName = "";
	var siteCateName = "";

	// CategoryName�̑O�������i�T�C�g��ʕ����j�����肷��
	if(site == "Consumer") {
		siteCateName = "DPC";
	} else if(site == "Business") {
		siteCateName = "DPB"
	}

	// category��Workstation�̏ꍇ�AW��w�ɕϊ�
	if(category == "Workstation") {
		category = "workstation"
	}

	categoryName = siteCateName + category;
	
	document.getElementById("CategoryName").value = categoryName;
	
	return categoryName;
}


/**
 * ��r�J�[�g�ǉ�����(.COM�y�[�W�p)
 * 
 */
function addCompareCartByDotCom(targetForm, cookieUrl, cartUrl, linkUrl, imgId) {
	
	// ��r�y�[�W��ʃE�B���h�E�ŕ\������
	openComparePage(cookieUrl, imgId);
	
	// CSessionID�̑��݊m�F���s��
	var sid = getCSessionID();
	
	var formData = $("#" + targetForm);
	var fomDataArray=formData.serializeArray();
	
	// �G���[�t���O��ݒ肷��
	var errorFlg = false;
	
	go()
	.then(
		// cookie����
		function()
		{
			
			// CSessionID�����݂���ꍇ��URL�ɕt�^����
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
						// �G���[��ISML�̏ꍇ�Aflg��ύX
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
		// cookie�Ǎ�(��r�J�[�g�\��)
		function()
		{
			var d = new $.Deferred();
			
			// URL��sid��t�^����
			cartUrl = cartUrl + ";sid=" + sid;
			
			// cookie�����̏�������hidden�l���擾
			fomDataArray=formData.serializeArray();
			
			// �擾�ł��Ȃ��l��SET���Ȃ���
			fomDataArray.push({name: 'ProductCompareStatus', value: $("#ProductCompareStatus").val()});
			fomDataArray.push({name: 'ProductCompareLineItemKey', value: $("#ProductCompareLineItemKey").val()});
			// �񓯊��������ɂ����ڂɑJ�ڂ����ۂ̃X�e�[�^�X��ǉ�
			fomDataArray.push({name: 'AjaxFlg', value: "true"});
			
			$("#compareCart")
				.load(
					cartUrl + "?DotComFlag=true"
					, fomDataArray
					, function(){
						// �G���[��ISML�̏ꍇ�Aflg��ύX
						if(0 < $("#ErrorFlg").size()){
							errorFlg=true;
						}
						d.resolve();
					}
				);
			return d.promise();
		}
	).then(
	    // ��r�����N�X�V
		function()
		{
			var d = new $.Deferred();
			
			// URL��sid��t�^����
			linkUrl = linkUrl + ";sid=" + sid;
			
			$("#compareLinkLabel")
				.load(
					linkUrl + "?DotComFlag=true"
					, fomDataArray
					, function(){
						// �G���[��ISML�̏ꍇ�Aflg��ύX
						if(0 < $("#ErrorFlg").size()){
							errorFlg=true;
						}
						d.resolve();
					}
				);
			return d.promise();	
		}
	);
	
	// ���񂾂������[�h
	if(sid == "") {
		setTimeout("location.reload()",5000);
	}
}


/** 
 * ��ɐi��
 * 
 */
function go() {
	var d = new $.Deferred();
	d.resolve();
	return d.promise();
}


/** 
 * ��r�J�[�g�ǉ�/�폜�����̃X�e�[�^�X�`�F�b�N
 * 
 */
function isProductCompareStatus(status)
{
	if ("CountErr" == status) 
	{
		alert("��r�ꗗ�ŕ\���ł��鐔�͍ő�10���i���ł��B");
		return false;
	} 
	else if ("ConfigError" == status)  
	{
		alert("���̐��i�͔�r�ł��܂���B");
		return false;
	}
	else if ("ExecErr" == status)  
	{
		alert("�������ł��B");
		return false;
	}
	return true;
}


/** 
 * .COM�y�[�W�pSessionID���擾����
 * 
 */
function getCSessionID() {

	// .COM�y�[�W�pSessionID��
	var name = "CSessionID";
	var cookie_value = "";

	// ���s�����N�b�L�[�̎擾�i�ǂݍ��݁j
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
 * imgID���擾����
 * 
 */
function getImgID() {

	// ImgID��
	var name = "ImgID";
	var cookie_value = "";

	// ���s�����N�b�L�[�̎擾�i�ǂݍ��݁j
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
 * ��r�y�[�W��ʃE�B���h�E�ŕ\��
 */
function openComparePage(cookieUrl, imgId) {

	// ��r�{�^���؂�ւ�
	document.getElementById("img" + imgId).src="/directplus/system/images/btn_spec_comp_green1_on.gif";

	// �ʃE�B���h�E�ŊJ����r�y�[�W��URL
	var splitUrl = cookieUrl.split("?");
	var domain = changeDomain();
	var pageUrl = "http://" + domain +"/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ProductCompare-OpenComparePageForDotCom?" + splitUrl[1] + "&OpenComparePageFlg=1";

	// ImgID�̑��݊m�F���s���AImgID�����݂���ꍇ�AURL�ɕt�^����
	var imgIdCookie = getImgID();
	if(typeof imgIdCookie == "undefined" || imgIdCookie == "") {
		pageUrl = pageUrl + "&ImgID=img" + imgId;
	}

	// CSessionID���擾����
	var sid = getCSessionID();

	// CSessionID�̑��݊m�F���s���ACSessionID�����݂���ꍇ�AURL�ɕt�^����
	if(typeof sid != "undefined" && sid != "") {
		var splitPageUrl = pageUrl.split("?");
		pageUrl = splitPageUrl[0] + ";sid=" + sid + "?" + splitPageUrl[1];
	}

	//��r�y�[�W��ʃE�B���h�E�ŊJ��
	document.productCompareForm.target = "comparePage";
	document.productCompareForm.method = "post";
	document.productCompareForm.action = pageUrl;
	document.productCompareForm.submit();

}


/** 
 * ��r�J�[�g�N���[�Y
 * 
 */
function cartClose(){
	document.getElementById("compareCartBody").style.display="none";
}
