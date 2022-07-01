<style>
.Bnr {
	border: 1px solid #CCC;
	background-repeat: no-repeat;
	position: relative;
	display:block;
}
.Bnr.NasNo1{
	background-image: url('/directplus_ent/images/banners/bnr_nas_no1.svg');
	background-size: 55%;
	background-position: 80%;
}
.NasNo1 {
	border: 2px solid #CCC;
	box-sizing: border-box;
}
.NasNo1Inr {
	box-sizing: border-box;
	display: flex;
	margin: 10px;
}

@media only screen and (max-width:999px){
	.Bnr.NasNo1{
		background-size: 40%;
	}
		.NasNo1Inr {
		flex-direction: column;
	}
	.NasNo1Inr:not(*[class*="fix"]) > * {
		max-width: 100%;
		flex-shrink: 0;
	}
}

@media only screen and (max-width:664px){
	.Bnr.NasNo1{
		background-size: 50%;
		background-position: 90% 60%;
	}
}

.NasNo1Txt{
	font-size:20px;
	font-weight:bold;
	margin-bottom:5px;
	line-height:1.6;
}
.NasNo1Ttl {
	font-size:14px;
	margin-bottom:10px;
}
@media only screen and (max-width:999px){
	.NasNo1Txt{
		font-size:20px;
	}
	.NasNo1Ttl {
		font-size:20px;
	}
}
.NasNo1TtlPc {
	display: flex;
	height: 90px;
}
.NasNo1TtlPc .NasNo1TtlPcLeft img {
	width:50px;
	margin-left: 50px;	
}
.NasNo1TtlPc .NasNo1TtlPcCenter {
	font-size:60px;
	margin-left: 20px;
	font-weight:bold;
}
.NasNo1TtlPc .NasNo1TtlPcRight {
	border: 4px solid #7ff9e2;
	box-sizing: border-box;
	padding: 10px;
	margin-left: 40px;
	height: 50px;
}
.NasNo1Note {
	font-size: 10px;
	line-height: 1.4;
	margin: 10px;
}
</style>
<div class="pagesList mb40">
				<div class="group consider">
					<div class="groupHeader">
						検討する
					</div>
					<div class="groupColumn">
						<div class="clm1">
							<ul>
								<li>
									<a href="/directplus_ent/beginner/?ref=dplustopconsider1" class="linkWithArrow">
										はじめての方へ
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="/directplus_ent/promotion/merit/?ref=dplustopconsider2" class="linkWithArrow">
										HPE DirectPlusで購入するメリット
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="/directplus_ent/server/advice.html?ref=dplustopconsider3" class="linkWithArrow">
										サーバー「導入前のアドバイス」
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="/directplus_ent/casestudy/?ref=dplustopconsider4" class="linkWithArrow">
										お客様導入事例
										<span class="arrow">→</span>
									</a>
								</li>
							</ul>
						</div>
						<div class="clm2">
							<ul>
								<li>
									<a href="/directplus_ent/server/features.html?ref=dplustopconsider5" class="linkWithArrow">
										最新テクノロジー解説
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="https://www.hpe.com/jp/ja/doc.html?ref=dplustopconsider6" class="linkWithArrow" target="_blank">
										製品カタログ
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="/events/seminars/?ref=dplustopconsider7" class="linkWithArrow" target="_blank">
										イベント/セミナー
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="#whatsnew" class="linkWithArrow">
										新着情報
										<span class="arrow">→</span>
									</a>
								</li>
							</ul>
						</div>
					</div>
				</div>
				
				<div class="group select">
					<div class="groupHeader">
						選定する
					</div>
					<div class="groupColumn">
						<div class="clm1">
							<ul>
								<li>
									<a href="/directplus_ent/server/?ref=dplustopselect1" class="linkWithArrow">
										サーバー
										<span class="arrow">→</span>
									</a>
									<ul class="listC">
										<li>
											<a href="/directplus_ent/server/?ref=dplustopselect2" class="linkWithArrow">
												HPE ProLiant
												<span class="arrow">→</span>
											</a>
										</li>
									</ul>
								</li>
								<li>
									<a href="/directplus_ent/storage/?ref=dplustopselect3" class="linkWithArrow">
										ストレージ
										<span class="arrow">→</span>
									</a>
									<ul class="listC">
										<li>
											<a href="/directplus_ent/storage/?hash=StoreEasy&ref=dplustopselect4" class="linkWithArrow">
												HPE StoreEasy
												<span class="arrow">→</span>
											</a>
										</li>
										<li>
											<a href="/directplus_ent/storage/?hash=MSA&ref=dplustopselect5" class="linkWithArrow">
												HPE MSA
												<span class="arrow">→</span>
											</a>
										</li>
										<li>
											<a href="/directplus_ent/storage/?hash=LTO&ref=dplustopselect6" class="linkWithArrow">
												HPE StoreEver / HPE RDX
												<span class="arrow">→</span>
											</a>
										</li>
									</ul>
								</li>
								<li>
									<a href="/directplus_ent/network/?ref=dplustopselect7" class="linkWithArrow">
										ネットワーク
										<span class="arrow">→</span>
									</a>
									<ul class="listC">
										<li>
											<a href="/directplus_ent/network/?ref=dplustopselect8" class="linkWithArrow">
												HPE Aruba
												<span class="arrow">→</span>
											</a>
										</li>
									</ul>
								</li>
								<li>
									<a href="/directplus_ent/supportservice/?ref=dplustopselect9" class="linkWithArrow">
										サポートサービス
										<span class="arrow">→</span>
									</a>
									<ul class="listC">
										<li>
											<a href="/directplus_ent/supportservice/?ref=dplustopselect10" class="linkWithArrow">
												HPE Pointnext Tech Care
												<span class="arrow">→</span>
											</a>
										</li>
									</ul>
								</li>
								<li>
									<a href="<!--#include virtual="/directplus_ent/include/intershop_domain.inc" -->/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/BrowseCatalogForBusiness-Start?CategoryName=DPBOption_e&ref=dplustopselect11" class="linkWithArrow">
										オプション
										<span class="arrow">→</span>
									</a>
								</li>
							</ul>
						</div>
						<div class="clm2">
							<ul>
								<li>
									<a href="/directplus_ent/campaign/?ref=dplustopselect12" class="linkWithArrow">
										キャンペーン
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="/directplus_ent/whatsnew/?hash=NewProducts&ref=dplustopselect13" class="linkWithArrow">
										新製品情報
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="/directplus_ent/server/purpose/file.html?ref=dplustopselect14" class="linkWithArrow">
										用途で選ぶ
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="/directplus_ent/server/search/index.asp?ref=dplustopselect15" class="linkWithArrow">
										HPEプロダクトセレクションから選ぶ
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="https://www.hpe.com/jp/ja/doc/server-system.html?ref=dplustopselect16" class="linkWithArrow" target="_blank">
										システム構成図
										<span class="arrow">→</span>
									</a>
								</li>
							</ul>
							<div class="Bnr NasNo1 mt10">
								<div class="NasNo1Inr">
									<div class="clm1">
										<p class="NasNo1Txt">国内NAS市場 工場出荷台数 2021年シェアNo.1</p>
										<p class="NasNo1Ttl">皆様のご愛顧に感謝申し上げます</p>
										<div class="NasNo1TtlPc">
											<div class="NasNo1TtlPcLeft">
												<img src="/directplus_ent/images/bnr_share_no1.png">
											</div>
										</div>
									</div>
								</div>
								<div class="NasNo1Note">
									出典：IDC Worldwide Quarterly Enterprise Storage Systems Tracker - 2021Q4(Share by Company, Installation NAS)
								</div>
							</div>
						</div>
					</div>
				</div>
				
				<div class="group quote">
					<div class="groupHeader">
						お見積・ご注文をする
					</div>
					<div class="groupColumn">
						<div class="clm1">
							<ul>
								<li>
									<a href="/directplus_ent/guide/?ref=dplustopquote1" class="linkWithArrow">
										お見積・ご注文の方法（ご利用ガイド）
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="/directplus_ent/promotion/convenient/?ref=dplustopquote2" class="linkWithArrow">
										お見積を保存するとここが便利
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="/directplus_ent/callcenter/?ref=dplustopquote3" class="linkWithArrow">
										コールセンターでお見積・ご注文
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="/directplus_ent/salessupport/?ref=dplustopquote4" class="linkWithArrow">
										販売パートナー様がお見積・ご注文
										<span class="arrow">→</span>
									</a>
								</li>
							</ul>
						</div>
						<div class="clm2">
							<ul>
								<li>
									<a href="/directplus_ent/guide/delivery/delivery02.html?ref=dplustopquote5" class="linkWithArrow">
										納期について
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="/directplus_ent/server/delivery.html?ref=dplustopquote6" class="linkWithArrow">
										いま5営業日で納品できるサーバー
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="<!--#include virtual="/directplus_ent/include/intershop_domain.inc" -->/is-bin/INTERSHOP.enfinity/WFS/Directplus-Customer-Site/ja_JP/-/JPY/ViewBasketForBusiness-View?ref=dplustopquote7" class="linkWithArrow">
										ショッピングカート
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="/directplus_ent/members/?ref=dplustopquote8" class="linkWithArrow">
										会員メニュー
										<span class="arrow">→</span>
									</a>
								</li>
							</ul>
						</div>
					</div>
				</div>
				
				<div class="group contact">
					<div class="groupHeader">
						お問い合わせする
					</div>
					<div class="groupColumn">
						<div class="clm1">
							<ul>
								<li>
									<a href="/directplus_ent/contact/?ref=dplustopcontact1" class="linkWithArrow">
										お問い合わせ一覧
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="/directplus_ent/callcenter/?ref=dplustopcontact2" class="linkWithArrow">
										お悩みの際はお気軽にコールセンターへ
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="/directplus_ent/salessupport/?hash=directpartner&ref=dplustopcontact3" class="linkWithArrow">
										ダイレクトパートナー一覧
										<span class="arrow">→</span>
									</a>
								</li>
							</ul>
						</div>
						<div class="clm2">
							<ul>
								<li>
									<a href="/directplus_ent/guide/?ref=dplustopcontact4" class="linkWithArrow">
										ご利用ガイド
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="/directplus_ent/faq/?ref=dplustopcontact5" class="linkWithArrow">
										よくあるご質問
										<span class="arrow">→</span>
									</a>
								</li>
								<li>
									<a href="https://support.hpe.com/connect/s/?language=ja&ref=dplustopcontact6" class="linkWithArrow" target="_blank">
										製品マニュアル、ドライバ
										<span class="arrow">→</span>
									</a>
								</li>
							</ul>
						</div>
					</div>
				</div>
			</div><!-- End Pages List -->
