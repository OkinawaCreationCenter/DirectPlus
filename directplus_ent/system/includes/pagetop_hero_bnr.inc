<style>
.heroBnrArea {
	display:flex;
	margin-bottom:30px;
}
.heroBnrArea .heroBnr:first-child {
	margin-right:5px;
	width:50%;
}
.heroBnrArea .heroBnr:last-child {
	margin-left:5px;
	width:50%;
}
@media only screen and (max-width:999px){
	.heroBnrArea {
		display:block;
	}
	.heroBnrArea .heroBnr:first-child {
		margin-right:0;
		margin-bottom:10px;
		width:100%;
	}
	.heroBnrArea .heroBnr:last-child {
		margin-left:0;
		width:100%;
	}
}
.heroBnr {
	border: 1px solid #CCC;
	background-repeat: no-repeat;
	position: relative;
	display:block;
}
/*a.heroBnr {
	color: #FFF;
}*/
@media only screen and (max-width:999px){
	.heroBnr {
		background-size:cover
	}
}
.heroBnrInr {
	width: 100%;
	height: 100%;
	padding: 20px;
	box-sizing: border-box;
}
@media only screen and (max-width:999px){
	.heroBnrInr {
		padding: 15px;
	}
}
.heroBnrTtl {
	font-weight: bold;
	font-size: 30px;
	line-height: 1;
	margin-bottom: 10px;
}
.heroBnrTxt {
	line-height:1.6;
	font-size:20px;
	font-weight:bold;
	margin-top: 30px;
}
.heroBnrTxt > p {
	font-size:15px;
	/*margin-top: 20px;*/
}
@media only screen and (max-width:999px){
	.heroBnrTxt {
		line-height:1;
		margin-top: 20px;
	}
	.heroBnrTxt > p {
		font-size:16px;
	}
}
.heroBnrBtn {
	position: absolute;
	bottom: 20px;
	right: 30px;
}
@media only screen and (max-width:999px){
	.heroBnrBtn {
		position: relative;
		bottom: auto;
		right: auto;
		text-align:center;
	}
}

/* Amazonギフト券バナー */
.heroBnr.heroBnrAmazongift{
	background-image: url('/directplus_ent/images/banners/bnr_1000x350_amazongift2022.jpg');
	background-size: 150%;
	background-position: right bottom;
}
.heroBnrAmazongift .heroBnrInr {
	background: linear-gradient(90deg, #eee 0,rgba(255,255,255,0.5) 100%); /* 徐々に透明にする */
	/*background: linear-gradient(90deg, rgba(1,0,0,0) 0%, rgba(1,0,0,0) 20%, rgba(0,0,0,0) 90%);*/
}
@media only screen and (max-width:999px){
	.heroBnr.heroBnrAmazongift{
		background-size: cover;
	}
	.heroBnrAmazongift .heroBnrInr {
		background: linear-gradient(180deg, #fff 0%, rgba(255,255,255,0) 100%);
	}
	.heroBnrInr .column60-40 > .clm1 {
		margin-bottom: 0;
	}
}

/* DX応援キャンペーンバナー */
.heroBnr.heroBnrDxouen{
	background-image: url('/directplus_ent/images/banners/bnr_800x350_dx_campaign.jpg');
	background-size:cover;
}
.heroBnrDxouen .heroBnrInr {
	background: linear-gradient(90deg, rgba(0,0,0,.5) 0%, rgba(0,0,0,.5) 20%, rgba(0,0,0,0) 90%);
}
@media only screen and (max-width:999px){
	.heroBnrDxouen .heroBnrInr {
		background: linear-gradient(180deg, rgba(0,0,0,.6) 0%, rgba(0,0,0,0.2) 100%);
	}
}

/* シェアNo.1 */

/*.pie {
	display: flex;
	justify-content: center;
	align-items: center;
	margin-right: auto;
	margin-left: auto;
	width: 120px;
	height: 120px;
	font-size: 26px;
	font-weight: 700;
	background-image: radial-gradient(#fff 60%, transparent 31%), conic-gradient(#00B388 0% 24.8%,#fff 24.8% 26%, #d9d9d9 26% 98%,#fff 98% 100%);
	border-radius: 50%;
}*/

/*.pieTxt {
	float: right;
	margin-right: 20px;
	font-size: 20px;
	color: #00B388;
	font-weight:bold;
}*/
.heroBnr.heroShareNo1{
	background-image: url('/directplus_ent/images/banners/bnr_share_no1_800x350.png');
	background-size: 75%;
	background-position: right bottom;
}
.heroShareNo1 {
	border: 2px solid #CCC;
	box-sizing: border-box;
	/*padding:15px 15px 10px;*/
}
.heroShareNo1Inr {
	box-sizing: border-box;
	display: flex;
	margin: 10px;
}
@media (min-width: 1000px) {
	.heroShareNo1Inr > *:first-child {
		width: 73%;
	}
	/*.heroShareNo1Inr > *:last-child {
		width: 27%;
	}*/
}
@media only screen and (max-width:999px){
	.heroBnr.heroShareNo1{
		background-size: 55%;
	}
		.heroShareNo1Inr {
		flex-direction: column;
	}
	.heroShareNo1Inr:not(*[class*="fix"]) > * {
		max-width: 100%;
		flex-shrink: 0;
	}
}
@media only screen and (max-width:767px){
	.heroBnr.heroShareNo1{
		background-size: 60%;
	}
}
.heroShareNo1Txt{
	font-size:16px;
	margin-bottom:5px;
	line-height:1.6;
}
.heroShareNo1Ttl {
	font-size:16px;
	font-weight:bold;
	margin-bottom:10px;
}
@media only screen and (max-width:999px){
	.heroShareNo1Txt{
		/*margin-bottom:10px;*/
		font-size:20px;
	}
	.heroShareNo1Ttl {
		font-size:20px;
	}
}
/*@media only screen and (max-width:767px){
	.heroShareNo1Txt{
		font-size:12px;
	}
}*/

.heroShareNo1TtlPc {
	display: flex;
	height: 90px;
}
.heroShareNo1TtlPc .heroShareNo1TtlPcLeft img {
	width:50px;
}
.heroShareNo1TtlPc .heroShareNo1TtlPcCenter {
	font-size:60px;
	margin-left: 20px;
	font-weight:bold;
}
.heroShareNo1TtlPc .heroShareNo1TtlPcRight {
	border: 4px solid #7ff9e2;
	box-sizing: border-box;
	padding: 10px;
	margin-left: 40px;
	height: 50px;
}
/*.heroShareNo1TtlSp {
	display:none;
}*/
/*@media only screen and (max-width:999px){
	.heroShareNo1TtlPc {
		display:none;
	}
	.heroShareNo1TtlSp {
		display:block;
	}
}*/
.heroShareNo1Note {
	font-size: 10px;
	/*padding-left: 3em;
    text-indent: -3em;*/
	line-height: 1.4;
	margin: 10px;
}
</style>

<div class="contentBox heroBnrArea">
	<a href="/directplus_ent/promotion/amazongift/?ref=herobnr0005" class="heroBnr heroBnrAmazongift">
		<!--<img src="/directplus_ent/images/banners/bnr_amazongift2022_1000x340.jpg" width="100%">-->
		<div class="heroBnrInr">
			<p class="heroBnrTtl">お見積でもらえる、ギフト券がもらえる</p>
			<div class="heroBnrTxt">
				抽選で100名様に2000円分のAmazonギフト券プレゼント<br class="spHide"><span class="disp_ib">作成されたお見積の数だけ応募可能</span>
			</div>
			<div class="column60-40">
				<div class="clm1 heroBnrTxt"><p>2022年7月29日（金）17:00お申込み分まで</p></div>
				<div class="clm2">
					<div class="heroBnrBtn">
						<span class="btn btn-secondary alpha">詳細はこちら</span>
					</div>
				</div>
			</div>
		</div>
	</a>
	
	<div class="heroBnr heroShareNo1">
		<!--<img src="/directplus_ent/images/banners/bnr_share_no1_1000x340.jpg" width="100%">-->
		<div class="heroShareNo1Inr">
			<div class="clm1">
				<p class="heroShareNo1Txt">皆様のご愛顧に感謝申し上げます</p>
				<p class="heroShareNo1Ttl">国内Windows Server搭載サーバー出荷台数 年間シェア</p>
				<div class="heroShareNo1TtlPc">
					<div class="heroShareNo1TtlPcLeft">
						<img src="/directplus_ent/images/bnr_share_no1.png">
					</div>
					<div class="heroShareNo1TtlPcCenter">No.1</div>
					<!--<div class="heroShareNo1TtlPcRight">4台に1台がHPE*</div>-->
				</div>
			</div>
			<!--<div class="clm2">
				<div class="pieTxt">HPE</span></div>
				<div class="pie">24.8<span class="f15">%</span></div>
			</div>-->
		</div>
		<div class="heroShareNo1Note">
			出典:「IDC Quarterly Server Tracker 2022Q1 (Share by Company)」OS: Windows<br>
			* 2021年通年/国内Windows Server搭載サーバー 出荷台数のうち
		</div>
	</div>

	<!--<a href="/directplus_ent/promotion/amazongift/?ref=herobnr0001" class="heroBnr heroBnrAmazongift">
		<div class="heroBnrInr">
			<p class="heroBnrTtl">お見積でもらえる、ギフト券がもらえる</p>
			<div class="heroBnrTxt">
				HPE DirectPlusでお見積、抽選で100名様に1,000円分のAmazonギフト券プレゼント<br>
				<span>2021年6月30日（水）17:00<br class="spHide">お申込み分まで</span>
			</div>
			<div class="heroBnrBtn">
				<span class="btn btn-secondary alpha">詳細・応募フォームはこちら</span>
			</div>
		</div>
	</a>-->
</div>
