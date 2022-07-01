<%@ CodePage = 65001 %><%
  Option Explicit
  Response.Buffer = True

  Dim sHtml, sHtmlHead, sHtmlNavi
  Dim oXml
  Dim sXPath
  Dim sResultCount, sIndexIconName

  ' エスケープ文字列
  Dim safeSearchStr, safeSearchStr2
  Dim strDate, iSearchFlg

  Dim sCatHdDsp

  Set oXml = Server.CreateObject("Msxml2.DOMDocument.6.0")
  oXml.async = False
  oXml.load(Server.MapPath("prosele_data.xml"))

  Call Main

  Set oXml = Nothing
'----------------------------------------------------------------
' ■メイン
'----------------------------------------------------------------
Sub Main
  Dim Count
  Dim aQry



'GETパラメータがあれば上書き
  If TextEscape(Request.QueryString("productnumber"))<>"" Then
    safeSearchStr = TextEscape(Request.QueryString("productnumber"))
    strDate = Year(Now) & Right("0" & Month(Now), 2) & Right("0" & Day(Now), 2)
    iSearchFlg = 1
  Else
    safeSearchStr = ""
    iSearchFlg = 0
  End If

  safeSearchStr2=""

  If iSearchFlg = 1 Then
    safeSearchStr2 = fConvStr(safeSearchStr)
    safeSearchStr2 = UCase(safeSearchStr2)

'    ' キーワード検索対応
'    If safeSearchStr2 <> "" Then
'      aQry = Split(safeSearchStr2)
'      Dim buf(), idx, tmpTxt
'      idx = 0
'      ReDim buf(UBound(aQry))
'      For idx = 0 To UBound(aQry)
'        tmpTxt = "[contains(translate(@productnumber,'ABCDEFGHIJKLMNOPQRSTUVWXYZ','abcdefghijklmnopqrstuvwxyz'),translate('###QRY###','ABCDEFGHIJKLMNOPQRSTUVWXYZ','abcdefghijklmnopqrstuvwxyz'))]"
'        tmpTxt = Replace(tmpTxt, "###QRY###", aQry(idx))
'        buf(idx) = tmpTxt
'      Next
'      sXPath = "//case" & join(buf, vbCrLf)
'    End If
    sXPath = "//case[@productnumber =""" & safeSearchStr2 & """]"

    sXPath = sXPath & "[@startdate <= """ & strDate & """]" & "[@enddate >= """ & strDate & """]"


    Call fSearch
  End If

End Sub

Function TextEscape(strTest)
	TextEscape = Server.HTMLEncode(strTest)
	TextEscape = Replace(TextEscape,"'","")
	TextEscape = Replace(TextEscape,"　"," ")
End Function



'----------------------------------------------------------------
' ■検索メイン
'----------------------------------------------------------------
Sub fSearch
  Dim oProdNodes
  Set oProdNodes = oXml.SelectNodes(sXpath)
  sResultCount = oProdNodes.Length
  If sResultCount > 0 Then
      sHtmlHead = "<div class=""mb10""><h3 class=""bold f20"">検索結果</h3><p>検索の結果&nbsp;<span class=""bold"">" & sResultCount & "件</span>&nbsp;見つかりました</p></div><div>" & vbCrLf
  End If
  Call fSearchSub(oProdNodes)
End Sub

'----------------------------------------------------------------
' ■検索サブ (検索結果一覧作成)
'----------------------------------------------------------------
Function fSearchSub(oTestNodes)
  Dim tmpRepTxt
  Dim nNodeCount
  Dim oTestNode, oXSL
  Dim ihandleFlg
  nNodeCount = oTestNodes.Length

  Set oTestNodes = oXml.SelectNodes(sXpath)
  If oTestNodes.Length = 0 Then
    sHtml = "<div class=""mb10""><h3 class=""bold f20"">検索結果</h3></div><p>該当しません。HPE プロダクトセレクションに記載の製品番号をご確認のうえ再度ご入力ください。</p>"
  Else
    if safeSearchStr = "" Then
      sHtmlHead = ""
    End If
  End If


  Dim buf(), idx, tmpTxt

  idx = 0
  ReDim buf(oTestNodes.Length)

  For Each oTestNode In oTestNodes

    tmpTxt = "<div class=""searchResultProduct cfx""><div class=""lft""><img src=""###IMGURL###"" width=""100""></div><div class=""rgt""><p class=""bold f18"">###NAME###</p><p>###TEXT###</p><div class=""searchResultProductBtn""><a href=""###URL###"" target=""_blank"" role=""button"" class=""btn btn-secondary"" target=""_blank"">カスタマイズ・お見積</a></div></div></div>"

    If oTestNode.getAttribute("handling")="0" Then
      tmpTxt = "<div class=""mb10""><h3 class=""bold f20"">検索結果</h3></div><p>お探しの製品番号はHPE DirectPlusでの取り扱いはございません。</p>"
      ihandleFlg = 0
    Else

      ihandleFlg = 1

      'URL
      tmpRepTxt = ""
      If oTestNode.getAttribute("url")<>"" Then
        tmpRepTxt = oTestNode.getAttribute("url")
      End If
      tmpTxt = Replace(tmpTxt, "###URL###", tmpRepTxt)

      'IMGURL
      tmpRepTxt = ""
      If oTestNode.getAttribute("img")<>"" Then
        tmpRepTxt = oTestNode.getAttribute("img")
      End If
      tmpTxt = Replace(tmpTxt, "###IMGURL###", tmpRepTxt)

      'NAME
      tmpRepTxt = ""
      If oTestNode.getAttribute("modelname")<>"" Then
        tmpRepTxt = oTestNode.getAttribute("modelname")
        tmpRepTxt = Replace(tmpRepTxt, vbLf, "<BR>")
      End If
      tmpTxt = Replace(tmpTxt, "###NAME###", tmpRepTxt)

      'TEXT
      tmpRepTxt = ""
      If oTestNode.getAttribute("text")<>"" Then
        tmpRepTxt = oTestNode.getAttribute("text")
        tmpRepTxt = Replace(tmpRepTxt, vbLf, "</p><p>")
      End If
      tmpTxt = Replace(tmpTxt, "###TEXT###", tmpRepTxt)

    End If

    buf(idx) = tmpTxt
    idx = idx + 1
    tmpTxt = ""

  Next

  If oTestNodes.Length > 0 Then
    sHtml = join(buf, vbCrLf)
    If ihandleFlg = 1 Then
      sHtml = sHtmlHead & sHtml & "</div>"
    End If
  End If

End Function


'----------------------------------------------------------------
' ■全角英数記号 → 半角変換
'----------------------------------------------------------------
Function fConvStr(sTestStr)
  Dim sDbWords, sSbWords
  Dim i, j, sStrBuf

  fConvStr = ""
  sDbWords = "０１２３４５６７８９" &_
             "ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯＰＱＲＳＴＵＶＷＸＹＺ" &_
             "ａｂｃｄｅｆｇｈｉｊｋｌｍｎｏｐｑｒｓｔｕｖｗｘｙｚ" &_
             "　！＃＄％＆（）＊＋，－．／：；＜＝＞" &_
             "？＠［￥］＾＿｀｛｜｝￣。「」、・゛゜" &_
             "‒–—―−"
  sSbWords = "0123456789" &_
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ" &_
             "abcdefghijklmnopqrstuvwxyz" &_
             " !#$%&()*+,-./:;<=>?@[\]^_`{|}~｡｢｣､ ﾞﾟ" &_
             "-----"

  If Len(sTestStr) > 0 Then
    Dim buf(), idx, tmpTxt
    idx = 0
    ReDim buf(Len(sTestStr)+1)
    For idx = 1 to Len(sTestStr)
      sStrBuf = Mid(sTestStr, idx, 1)
      If InStr(sDbWords, sStrBuf) <> 0 Then
        buf(idx) = Mid(sSbWords, InStr(sDbWords, sStrBuf), 1)
      Else
        buf(idx) = sStrBuf
      End If
    Next
    fConvStr = join(buf, "")
  Else
    fConvStr = sTestStr
  End If
End Function


'----------------------------------------------------------------
' ■ chkStrがtargetStrの時responseStrをResponse.writeする
'----------------------------------------------------------------
Function fChkStrResponse(chkStr,targetStr,responseStr)
  If chkStr = targetStr Then
    Response.write(responseStr)
  End If
End Function

Function CNone(str)
	CNone = str
	If str = "" Then CNone = "none"
End Function

'----------------------------------------------------------------
%>
<script runat="server" language="JScript">
  function fUnicodeUnescape(s) {
    return unescape(s);
  }
  function fUnicodeEscape(s) {
    return escape(s);
  }
</script>

<!DOCTYPE html>
<!--#include virtual="/directplus_ent/system/includes/dpb_lang.inc" --><head>
	<!--#include virtual="/directplus_ent/system/includes/dpb_meta_charset_responsive.inc" -->
	<title>HPE プロダクトセレクションから選ぶ | <!--#include virtual="/comm/include/directplus_name.inc" --> オンラインストア<!--#include virtual="/comm/include/company_name_title_utf8.inc" --></title>
	<meta name="keywords" content="オンラインストア, 通販, ダイレクトプラス, directplus, <!--#include virtual="/comm/include/directplus_name.inc" -->, サーバー, server, hpサーバー, ストレージ, ネットワーク, HPE, TM200"/>
	
<meta name="description" content="<!--#include virtual="/comm/include/company_name_body2_utf8.inc" -->が運営する公式オンラインストアです。サーバー、ストレージ、ネットワーク、ソフトウェアなど、製品選定からお見積、購入までフルにバックアップします。公式オンラインストア限定のキャンペーン実施中"/>
	
	<meta name="bu" content="tsg">
	<meta name="sub_bu" content="TSG.Servers">
	<meta name="lifecycle" content="presales.selection"/>
	<meta name="segment" content="Commercial.SMB">
	<meta name="company_code" content="hpe">
	<meta name="target_country" content="jp">
	<meta name="web_section_id" content="R11974">
	<meta name="hp_design_version" content="hpexpnontridion">
	<meta name="user_profile" content="Consumer">
	<meta name="page_content" content="Products">
	<meta name="robots" content="index,follow,noarchive">
	<meta name="date" content="2018-07-19">

	<!--#include virtual="/directplus_ent/system/includes/dpb_meta_responsive.inc" -->
	
	<!--#include virtual="/directplus_ent/system/includes/dpb_caas-header-footer_responsive.inc" -->
<style>
.form-input, .form-input-disabled, .form-input-error, .form-textarea, .form-textarea.disabled, .form-textarea.error {
    display: inline-block;
    height: 43px;
    line-height: 22px;
    padding: 0 8px;
    font-size: 16px;
    color: #767676;
    background: #fff;
    border: 2px solid #949494;
    vertical-align: top;
	margin-top:15px;
	box-sizing:border-box;
	max-width:400px;
	width:100%;
}
.searchFormArea {
	width:830px;
	margin:0 auto;
}
.searchFormArea a.btn {
	margin-left:15px;
}
@media only screen and (max-width:999px){
	.searchFormArea {
		width:100%
	}
	.searchFormArea .form-input,
	.searchFormArea .form-input-disabled,
	.searchFormArea .form-input-error,
	.searchFormArea .form-textarea,
	.searchFormArea .form-textarea.disabled,
	.searchFormArea .form-textarea.error {
		max-width:100%;
	}
	.searchFormArea a.btn {
		margin:0 auto;
		display:block;
		max-width:200px;
		margin-top:15px;
	}
}
.searchResultProduct {
	margin-bottom:20px;
	padding-bottom:20px;
	border-bottom:1px solid #CCC;
	display:table;
	width:100%;
}
.searchResultProduct .lft, .searchResultProduct .rgt {
	display:table-cell;
	vertical-align:middle;
}
.searchResultProduct .lft {
	width:100px;
}
.searchResultProduct .rgt {
	width:900px;
	padding-left:20px;
}
@media only screen and (max-width:999px){
	.searchResultProduct {
		display:block;
	}
	.searchResultProduct .lft, .searchResultProduct .rgt {
		display:block;
		width:100%;
	}
	.searchResultProduct .lft {
		margin-bottom:20px;
	}
	.searchResultProduct .rgt {
		padding-left:0;
	}
	.searchResultProduct .lft img {
		margin:0 auto;
	}
	.searchResultProductBtn {
		text-align:center;
	}
}
</style>
<script language="JavaScript">
function search_func() {
	if (document.getElementById("WORD").value.length > 0) {
		strWord = document.getElementById("WORD").value;
		repWord1 = strWord.toUpperCase();
		repWord2 = repWord1.replace(/‒/g,"-").replace(/–/g,"-").replace(/—/g,"-").replace(/―/g,"-").replace(/−/g,"-");
		document.getElementById("WORD").value = repWord2;
		location.href = "/directplus_ent/server/search/index.asp?productnumber=" + repWord2 ;
	}
}

function clear_func() {
	jQuery("#reslut_area").empty();
	jQuery("#WORD").val('');
}

</script>
</head>
<body>

<div id="page" class="page">
	<!--#include virtual="/directplus_ent/system/includes/dpb_totop_target_responsive.inc" -->
	<!-- START CaaS header -->
	<div id="header"></div>
	<!-- END CaaS header -->
	
	<div id="content" class="content">
	
		<!--#include virtual="/directplus_ent/system/includes/dpb_sub_header_responsive.inc" -->
		
		<!--#include virtual="/directplus_ent/system/includes/dpb_sub_navigation_responsive.inc" -->
		
		<div class="bgGry mb40">
			<div class="contentBox">
				<div class="breadcrumb">
					<ul>
						<li><a href="/directplus_ent/">TOP</a></li>
						<li><a href="/directplus_ent/server/">サーバー</a></li>
						<li>HPE プロダクトセレクションから選ぶ</li>
					</ul>
				</div>
			</div>
		</div>
		<!--#include virtual="/directplus_ent/system/includes/pagetop_hero_bnr.inc" -->
		<div class="contentBox">
			<div class="cfx">
				<h2 class="f28 mb20 bold">HPE プロダクトセレクションから選ぶ</h2>
			</div>
			<div class="contentsWithLeftNavi">
				<div class="rightCnt">
					<div class="mb40">
						<div class="column20-80 cfx mb20">
							<h3 class="bold f20 mb10">製品番号から、簡単検索・お見積</h3>
							<div class="clm1">
								<a href="https://www.hpe.com/jp/ja/doc/general-catalog.html" target="_blank"><img src="images/prosele_20220111.png" width="100" class="m0auto" alt="HPE プロダクトセレクション (日本ヒューレット・パッカード 総合製品カタログ)"></a>
							</div>
							<div class="clm2">
								<p class="mb20">
									日本HPEの総合製品カタログ「HPE プロダクトセレクション」に掲載されている<!--#include virtual="/comm/include/directplus_name.inc" -->取り扱い製品 (サーバーのみ) につきまして、本ページにて記載の製品番号から、CTOのベースモデルを一発で検索・お見積することができます。また、プロセッサー、メモリやディスク、OSプリインストールなどお好みにカスタマイズしてお見積いただくことが可能です。
								</p>
								<a href="https://www.hpe.com/jp/ja/doc/general-catalog.html" target="_blank"><span class="cta-link"><em class="icon-arrow-circle-right"></em>HPE プロダクトセレクションはこちら</span></a>
							</div>
						</div>
						
						<div class="hpe-accordion mb20">
							<div class="accordion-panel">
								<div class="accordion-panel-header">
									<a href="javascript:void(0);" class="accordion-toggle icon-toggle-circle-open">こんな時に</a>
								</div>
								<div class="accordion-panel-body">
									<ul class="listC">
										<li>HPE プロダクトセレクションを見ながら<!--#include virtual="/comm/include/directplus_name.inc" -->を使いたい</li>
										<li>カタログモデル同等の見積がすぐにほしい</li>
										<li>カタログモデルをベースにカスタマイズしたい</li>
									</ul>
								</div>
							</div>
							<div class="accordion-panel">
								<div class="accordion-panel-header">
									<a href="javascript:void(0);" class="accordion-toggle icon-toggle-circle-open">使い方</a>
								</div>
								<div class="accordion-panel-body">
									<p class="mb10">本ページは以下のように、HPE プロダクトセレクションとあわせてご活用ください。</p>
									<p class="indent-1">①「<a href="https://www.hpe.com/jp/ja/doc/general-catalog.html" target="_blank" class="tertiary-link">HPE プロダクトセレクション</a>」内で「HPE DirectPlus取り扱い製品」の掲載を確認する<br>目印はこちら</p>
									<img src="images/howtouse01.png" width="275" class="ml15 mb20" alt="">
									<p class="indent-1">②製品仕様内の「製品番号」を確認する<br>仕様表のこちらです</p>
									<img src="images/howtouse02.png" width="275" class="ml15 mb20" alt="">
									<p>③本ページの検索フォームに「製品番号」を入力する</p>
								</div>
							</div>
							<div class="accordion-panel accordionPanel03">
								<div class="accordion-panel-header">
									<a href="javascript:void(0);" class="accordion-toggle icon-toggle-circle-open">検索結果</a>
								</div>
								<div class="accordion-panel-body">
									<p class="mb10">「製品番号」で検索すると、以下のような結果が表示されます。</p>
									<p class="indent-1 mb5">①Green Selectモデル：HPE Green Select標準構成カタログモデルと同等の基本オプションにお勧めのオプションを<span class="bold f16">あらかじめセット！</span>さらに推奨オプションでカスタマイズも可能です。</p>
									<p class="indent-1 mb5">②オプ得モデル：<span class="bold f16">お好みにカスタマイズ</span>してお見積いただくことが可能です。「オプ得モデル」とは、プロセッサー、メモリ、ディスクドライブその他のカスタマイズオプションを通常価格の30%OFF相当でお求めいただける、<!--#include virtual="/comm/include/directplus_name.inc" -->ならではの特典です。</p>
									<p class="indent-1">③通常フルカスタマイズCTOモデル：<span class="bold f16">お好みにカスタマイズ</span>してお見積いただくことが可能です。</p>
								</div>
							</div>
							<div class="accordion-panel">
								<div class="accordion-panel-header">
									<a href="javascript:void(0);" class="accordion-toggle icon-toggle-circle-open">注意事項</a>
								</div>
								<div class="accordion-panel-body">
									<ul class="listC">
										<li>HPE プロダクトセレクション掲載の※<!--#include virtual="/comm/include/directplus_name.inc" -->取り扱い製品 (サーバーのみ) のカタログモデル同等のCTOのベースモデル構成を表示します。（MicroServerを除く）</li>
										<li>検索結果は<!--#include virtual="/comm/include/directplus_name.inc" -->で取り扱いのあるモデルが表示されます。</li>
										<li><!--#include virtual="/comm/include/directplus_name.inc" -->でお見積いただいた場合は、<!--#include virtual="/comm/include/directplus_name.inc" -->用の構成IDが発行されます。構成IDをダイレクトパートナーにお渡しいただけるのでとっても便利です。</li>
									</ul>
								</div>
							</div>
						</div>
					</div>
					
					<!-- 検索フォーム -->
					<div class="mb40" id="pnSearchForm">
						<h3 class="bold f24 alignCtr">製品番号検索</h3>
						<div class="searchFormArea">
							<form name="SearchForm" id="SearchForm" action="index.asp" method="post">
								<input value="<%=safeSearchStr2 %>" data-placeholder="" type="text" class="form-input js_color_change pre-active" title="キーワード" id="WORD" name="WORD"><p class="f12 mt5 pcHide">入力例：873830-291</p><!--
								--><a role="button" rel="" onClick="javascript:search_func()" tabindex="250" href="javascript:void(0)" class="btn btn-secondary">検索</a><!--
								--><a role="button" rel="" onClick="javascript:clear_func()" tabindex="250" href="javascript:void(0)" class="btn btn-tertiary">クリア</a>
							</form>
							<p class="f12 mt5 spHide">入力例：P06793-291、Q8T71A</p>
						</div>
					</div>
					<!-- 検索フォームここまで -->
					
					<!-- 検索結果ここから -->
					<div class="mb40" id="reslut_area">
						<%=sHtml %>
					</div>
					<!-- 検索結果ここまで -->
					
					<!--#include virtual="/directplus_ent/system/includes/dpb_totop_responsive.inc" -->
					
				</div><!-- End Right contents -->
				
				<div class="leftNav">
					<!--#include virtual="/directplus_ent/system/includes/dpb_leftnavi_server_responsive.inc" -->
					<!--#include virtual="/directplus_ent/system/includes/dpb_leftnavi_products_category_responsive.inc" -->
					<!--#include virtual="/directplus_ent/system/includes/dpb_leftnavi_customer_support_responsive.inc" -->
				</div><!-- End Left navigation -->
				
			</div>
		</div><!--End Contents with right navigation-->
		
		<div class="contentBox">
			<!--#include virtual="/directplus_ent/system/includes/dpb_foot_intel_responsive.inc" -->
		</div>
		
		<!--#include virtual="/directplus_ent/system/includes/dpb_merit_responsive.inc" -->
		<div id="ContactUs">
		<!--#include virtual="/directplus_ent/system/includes/dpb_contact_us_responsive.inc" -->
		</div>
		<div class="contentBox">
			<!--#include virtual="/directplus_ent/system/includes/dpb_foot_link_responsive.inc" -->
			<!--#include virtual="/directplus_ent/system/includes/dpb_footnote_responsive.inc" -->
		</div><!-- End Sub footer -->
		
	</div>
	
	<!-- START CaaS footer -->
	<div id="footer"></div>
	<!-- END CaaS footer -->
	
</div>
<!--#include virtual="/directplus_ent/system/includes/dpb_foot_js.inc" -->
<script>
$(window).on('load',function(){
	if(getQueryVariable('productnumber')) {
		
		//アコーディオン「検索結果」は検索前はデフォルトで表示、検索後は非表示
		/*if($('.hpe-accordion').hasClass('accordion-expanded')){
			$('.hpe-accordion').removeClass('accordion-expanded');
		}
		if($('.accordionPanel03 .accordion-panel-header a').hasClass('open')){
			$('.accordionPanel03 .accordion-panel-header a').removeClass('open');
			$('.accordionPanel03 .accordion-panel-body').hide();
		}*/
		
		
		var target = $("#pnSearchForm");
		var speed = 500;
		var position = target.offset().top;
		$('html, body').animate({scrollTop:position}, speed, "swing");
	} else {
		$('.hpe-accordion').addClass('accordion-expanded');
		$('.accordionPanel03 .accordion-panel-header a').addClass('open');
		$('.accordionPanel03 .accordion-panel-body').show();
	}

	function getQueryVariable(variable) {
		var query = window.location.search.substring(1);
		var vars = query.split("&");
		for (var i=0;i<vars.length;i++) {
			var pair = vars[i].split("=");
			if (pair[0] == variable) {
				return pair[1];
			}
		}
		return(false);
	}
});
</script>
<script>
var s_hp_apj_pageName = "hpe directplus プロセレから選ぶ";
</script>

<!--#include virtual="/directplus_ent/include/n_dp_default.txt" -->
</body>
</html>