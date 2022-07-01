<style>
.heroBnrArea, 
.heroBnrArea * {
	box-sizing: border-box;
}
.heroBnrAreaHeader {
	font-size: 36px;
	font-weight: bold;
	line-height: 1;
	margin-bottom: 10px;
	text-align: center;
}
@media (max-width:414px) {
	.heroBnrAreaHeader {
		font-size: 28px;
	}
}
.heroBnrArea {
	display:flex;
	margin-bottom:30px;
}
.heroBnrArea > * {
	flex: 1 1 50%;
}
.heroBnrArea > *:first-child:last-child {
	flex: 1 1 100%;
}
/*.heroBnrArea .heroBnr:first-child {
	margin-right:5px;
	width:50%;
}
.heroBnrArea .heroBnr:last-child {
	margin-left:5px;
	width:50%;
}*/
@media only screen and (min-width:1000px){
	.heroBnrArea > *:not(:last-child) {
		margin-right:10px;
	}
}
@media only screen and (max-width:999px){
	.heroBnrArea {
		display:block;
	}
	.heroBnrArea > * {
		margin-right:0;
		margin-left:0;
		width:100%;
	}
	.heroBnrArea > *:not(:last-child) {
		margin-bottom:10px;
	}
}
.heroBnr {
	border: 1px solid #CCC;
	background-repeat: no-repeat;
	position: relative;
	display:block;
}
a.heroBnr {
	color: #000;
}
@media only screen and (max-width:999px){
	.heroBnr {
		background-size:cover
	}
}
.heroBnrInr {
	width: 800px;
	height: 90px;
	box-sizing: border-box;
	margin: 20px 20px 20px 360px
}
@media only screen and (max-width:999px){
	.heroBnrInr {
		width: 100%;
		height: 100%;
		padding: 15px;
		margin: 0;
	}
}
.heroBnrTtl {
	font-weight: bold;
	font-size: 30px;
	line-height: 1;
	margin-bottom: 10px;
}
@media only screen and (max-width:999px){
	.heroBnrTtl {
		font-size: 28px;
		line-height: 1.2;
	}
}
.heroBnrTxt {
	line-height:1.4;
	font-size:18px;
	font-weight:bold;
}
.heroBnrTxt > span {
	font-size:15px;
}
@media only screen and (max-width:999px){
	.heroBnrTxt {
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
	background-image: url('/directplus_ent/images/banners/bnr_img_800x350_amazongift.jpg');
	/*background-position: right top;*/
}
/*.heroBnrAmazongift .heroBnrInr {
	background: linear-gradient(90deg, rgba(0,0,0,1) 0%, rgba(0,0,0,1) 20%, rgba(0,0,0,0) 90%);
}
@media only screen and (max-width:999px){
	.heroBnrAmazongift .heroBnrInr {
		background: linear-gradient(180deg, rgba(0,0,0,.8) 0%, rgba(0,0,0,0.2) 100%);
	}
}*/

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
.heroShareNo1 {
	border: 4px solid #CCC;
	box-sizing: border-box;
	padding:15px 15px 10px;
}
.heroShareNo1Inr {
	background-image: url(/directplus_ent/images/bnr_share_no1.png);
	background-size: 85px;
	background-repeat: no-repeat;
	padding-left:100px;
}
@media only screen and (max-width:999px){
	.heroShareNo1Inr {
		background-size: 60px;
		padding-left: 75px;
		min-height: 105px;
	}
}

/* ITの準備はお早めにキャンペーンバナー */
.heroBnrItasap {
	background-image: url('/directplus_ent/images/banners/bnr_800x350_it_asap_campaign.jpg');
}
.col2 .heroBnrItasap {
	background-size: 50%;
	background-position: 100% -40px;
}
.col2 .heroBnrItasap .heroBnrInr {
	background: linear-gradient(90deg, rgba(24,23,20,1) 0%, rgba(24,23,20,1) 55%, rgba(24,23,20,0) 75%);
	padding: 15px;
}
.col2 .heroBnrItasap .heroBnrTtl {
	font-size: 27px;
	line-height: 1.41;
	margin-bottom: 5px;
}
.col2 .heroBnrItasap .heroBnrSubTtl {
	font-size: 20px;
	line-height: 1.41;
	margin-bottom: 14px;
}
.col2 .heroBnrItasap .heroBnrTxt {
	font-size: 15px;
	font-weight: normal;
	margin-bottom: 13px;
}
@media only screen and (min-width:1000px){
	.col2 .heroBnrItasap {
		background-size: cover;
		background-position: 0 0;
	}
	.col2 .heroBnrItasap .heroBnrInr {
		background: linear-gradient(180deg, rgba(24,23,20,0.7) 0%, rgba(24,23,20,0.7) 20%, rgba(24,23,20,0) 35%);
	}
	.col2 .heroBnrItasap .heroBnrBtn {
		bottom: 15px;
		right: 15px;
	}
}
@media only screen and (max-width:999px){
	.col2 .heroBnrItasap {
		background-size: 75%;
		background-position: 100% 0;
	}
	.col2 .heroBnrItasap .heroBnrInr {
		background: linear-gradient(90deg, rgba(24,23,20,1) 0%, rgba(24,23,20,1) 30%, rgba(24,23,20,0) 60%);
	}
	.col2 .heroBnrItasap .heroBnrTxt {
		margin-bottom: 0;
	}
}
@media only screen and (max-width:768px){
	.col2 .heroBnrItasap {
		background-size: cover;
	}
	.col2 .heroBnrItasap .heroBnrInr {
		background: linear-gradient(180deg, rgba(24,23,20,1) 0%, rgba(24,23,20,0.5) 35%, rgba(24,23,20,0) 45%);
	}
}
@media only screen and (max-width:414px){
	.col2 .heroBnrItasap {
		background-size: cover;
		background-position: 60% 0;
	}
	.col2 .heroBnrItasap .heroBnrInr {
		background: linear-gradient(180deg, rgba(24,23,20,1) 0%, rgba(24,23,20,0.2) 35%, rgba(24,23,20,0) 100%);
	}
	.col2 .heroBnrItasap .heroBnrTtl {
		font-size: 24px;
	}
}
@media only screen and (max-width:375px){
	.col2 .heroBnrItasap .heroBnrTtl {
		font-size: 22px;
	}
	.col2 .heroBnrItasap .heroBnrSubTtl {
		font-size: 18px;
	}
}
@media only screen and (max-width:320px){
	.col2 .heroBnrItasap .heroBnrSubTtl {
		font-size: 17px;
	}
	.col2 .heroBnrItasap .heroBnrTxt {
		font-size: 14px;
	}
}
/* お困りごとはぜひ
   HPE DirectPlusコールセンターにご相談くださいバナー */
/*.col2*/ .heroBnrCallCenter {
	color: #000;
	background-image: url(/directplus_ent/images/banners/bnr_fiscal_year.jpg);
	background-size: 30%;
	background-repeat: no-repeat;
	background-position: 0 calc(100% - 15px);
}
/*.col2*/ .heroBnrCallCenter .heroBnrInr {
	padding: 15px;
}
/*.col2*/ .heroBnrCallCenter .heroBnrTtl {
	font-size: 24.5px;
	line-height: 1.41;
	margin-bottom: 8px;
}
/*.col2*/ .heroBnrCallCenter .heroBnrTxt {
	font-size: 15px;
	font-weight: normal;
	/*text-align: right;*/
}
/*.col2*/ .heroBnrCallCenter .heroBnrBtn {
	bottom: 15px;
	right: 15px;
}
@media only screen and (max-width:999px){
	/*.col2*/ .heroBnrCallCenter {
		padding-top: 110px;
		background-size: 320px;
		background-position: 0 15px;
	}
	/*.col2*/ .heroBnrCallCenter .heroBnrInr {
		padding: 0 15px;
	}
	/*.col2*/ .heroBnrCallCenter .heroBnrTxt {
		margin-bottom: 15px;
		text-align: left;
	}
	/*.col2*/ .heroBnrCallCenter .heroBnrBtn {
		right: initial;
	}
}
@media only screen and (max-width:414px){
	/*.col2*/ .heroBnrCallCenter .heroBnrTtl {
		font-size: 22px;
	}
	/*.col2*/ .heroBnrCallCenter .heroBnrTxt {
		font-size: 14px;
	}
}
@media only screen and (max-width:375px){
	/*.col2*/ .heroBnrCallCenter {
		padding-top: 95px;
		background-size: 270px;
	}
}
@media only screen and (max-width:414px){
	/*.col2*/ .heroBnrCallCenter .heroBnrTtl {
		font-size: 21px;
	}
}





.heroShareNo1Txt{
	font-size:16px;
	margin-bottom:5px;
	line-height:1.6;
}
@media only screen and (max-width:999px){
	.heroShareNo1Txt{
		margin-bottom:10px;
		font-size:14px;
	}
}
@media only screen and (max-width:767px){
	.heroShareNo1Txt{
		font-size:12px;
	}
}
.heroShareNo1Ttl {
	font-weight:bold;
	margin-bottom:10px;
}
.heroShareNo1TtlPc {
	display: flex;
}
.heroShareNo1TtlPc .heroShareNo1TtlPcRight {
	font-size:28px;
}
.heroShareNo1TtlPc .heroShareNo1TtlPcRight span {
	font-size:60px;
}
.heroShareNo1TtlSp {
	display:none;
}
@media only screen and (max-width:999px){
	.heroShareNo1TtlPc {
		display:none;
	}
	.heroShareNo1TtlSp {
		display:block;
	}
}
.heroShareNo1TtlServer {
	margin-bottom:10px;	
}
.heroShareNo1TtlServer,
.heroShareNo1TtlStorage {
	font-size: 22px;
	line-height:1.2;
	/*position:relative;
	padding-right: 150px;*/
}
.heroShareNo1TtlPc .heroShareNo1TtlServer span,
.heroShareNo1TtlPc .heroShareNo1TtlStorage span  {
	font-size:18px;
}
@media only screen and (max-width:999px){
	.heroShareNo1TtlSp .heroShareNo1TtlServer,
	.heroShareNo1TtlSp .heroShareNo1TtlStorage {
		font-size: 22px;
	}
}
@media only screen and (max-width:767px){
	.heroShareNo1TtlSp .heroShareNo1TtlServer,
	.heroShareNo1TtlSp .heroShareNo1TtlStorage {
		font-size: 16px;
	}
}
.heroShareNo1Note {
	font-size: 10px;
	/*padding-left: 3em;
    text-indent: -3em;*/
	line-height: 1.4;
}

.heroBnrCombi {
	display:flex;
	align-items: center;
	justify-content: space-between;
	border: 1px solid #CCC;
	position: relative;
	width: 100%;
	min-height: 170px;
}
.heroBnrCombi > *:first-child {
	margin-right: 20px;
}
.heroBnrCombi .heroBnrColBnr {
	flex: 1 1 auto;
	height: 100%;
	display: flex;
	align-items: center;
}
.heroBnrCombi .heroBnrColBnr img {
	width: 100%;
	height: auto;
}
.heroBnrCombi .heroBnrColTxt {
	flex: 1 1 auto;
}
.heroBnrCombi .heroBnrTtl {
	font-weight: bold;
	font-size: 24px;
	line-height: 1.4;
	margin-bottom: 15px;
}
.heroBnrCombi .heroBnrTxt {
	line-height: 1.4;
	font-size: 18px;
	font-weight: normal;
}
.heroBnrCombi .heroBnrTxtCombi {
	display:flex;
	justify-content: space-between;
}
.heroBnrCombi .heroBnrTxtCombi > * {
	flex: 1 1 auto;
}
.heroBnrCombi .heroBnrBtn {
	text-align: right;
	position: relative;
	bottom: auto;
	right: auto;
}
.heroBnrCombi .heroBnrBtn .btn {
	padding-left: 0;
	padding-right: 0;
	min-width: 240px;
}
@media only screen and (min-width:1000px){
	.heroBnrArea > *:not(:last-child) {
		margin-right: 10px;
	}
	.heroBnrCombi .heroBnrColBnr {
		width: 33.3%;
	}
	.heroBnrCombi .heroBnrColTxt {
		width: 66.7%;
		padding: 20px 20px 20px 0;
	}
	.heroBnrCombi .heroBnrTxtCombi {
		align-items: center;
	}
	.heroBnrCombi .heroBnrTxtCombi > *:not(:last-child) {
		margin-right: 10px;
	}
	.heroBnrCombi .heroBnrBtn.abs {
		position: absolute;
		bottom: 20px;
		right: 20px;
	}
}
@media only screen and (max-width:999px){
	.heroBnrCombi {
		flex-direction: column;
		align-items: flex-start;
		justify-content: space-between;
		padding: 20px 0;
	}
	.heroBnrCombi > * {
		width: 100%;
	}
	.heroBnrCombi > *:first-child {
		margin: 0 0 20px;
	}
	.heroBnrCombi .heroBnrColBnr img {
		width: 75%;
	}
	.heroBnrCombi .heroBnrColTxt {
		padding: 0 20px 0 20px;
	}
	.heroBnrCombi .heroBnrTxtCombi {
		flex-direction: column;
	}
	.heroBnrCombi .heroBnrTxtCombi > *:first-child {
		margin: 0 0 10px;
	}
	.heroBnrCombi .heroBnrTtl {
		font-size: 18px;
		margin-bottom: 5px;
	}
	.heroBnrCombi .heroBnrTxt {
		font-size: 14px;
	}
	.heroBnrCombi .heroBnrBtn {
		text-align: center;
	}
}
@media only screen and (max-width:414px){
	.heroBnrCombi .heroBnrColBnr img {
		width: 95%;
	}
}
@media only screen and (min-width:1000px){
	.col2 .heroBnrCombi.fiscal {
		flex-direction: column;
	}
	.col2 .heroBnrCombi.fiscal .heroBnrColBnr {
		width: auto;
		max-width: 100%;
		margin-right: 0;
	}
	.col2 .heroBnrCombi.fiscal .heroBnrColBnr img {
		width: 47%;
	}
	.col2 .heroBnrCombi.fiscal .heroBnrColTxt {
		width: 100%;
		padding: 15px;
	}
	.col2 .heroBnrCombi.fiscal .heroBnrTtl {
		font-size: 30px;
		line-height: 1;
		margin-bottom: 10px;
	}
	.col2 .heroBnrCombi.fiscal .heroBnrTtl span {
		font-size: 16px;
	}
	.col2 .heroBnrCombi.fiscal .heroBnrTxt {
		font-size: 15px;
	}
}
</style>

<!--<div class="contentBox heroBnrAreaHeader">
	ITの準備はお早めに
</div>-->

<!--<div class="contentBox heroBnrArea col2">
	<a href="/directplus_ent/campaign/?ref=herobnr0004" class="heroBnr heroBnrItasap">
		<div class="heroBnrInr">
			<p class="heroBnrTtl">
				年度末までのチャンス<br>
				人気のサーバー、ストレージが30%OFF
			</p>
			<p class="heroBnrSubTtl">
				ITの準備はお早めにキャンペーン
			</p>
			<div class="heroBnrTxt">
				2022年3月31日（木）お申込み分まで
			</div>
			<div class="heroBnrBtn">
				<span class="btn btn-secondary alpha">詳細はこちら</span>
			</div>
		</div>
	</a>-->

	<div class="contentBox heroBnrArea">
	<a href="/directplus_ent/server/delivery.html?ref=herobnr0003" class="heroBnr heroBnrCallCenter">
		<div class="heroBnrInr">
			<p class="heroBnrTtl">
				<span class="disp_ib">お困りごとはぜひ</span>HPE DirectPlus<span class="disp_ib">コールセンターに</span><span class="disp_ib">ご相談ください</span>
			</p>
			<div class="heroBnrTxt mt20">
				最短5営業日で納品できるサーバーを<br class="br320">随時掲載中
			</div>
			<div class="heroBnrBtn">
				<span class="btn btn-secondary">お早めにご注文ください</span>
			</div>
		</div>
	</a>
	<!--<a href="/directplus_ent/server/delivery.html?ref=herobnr0003" class="heroBnrCombi fiscal">
		<div class="heroBnrColBnr">
			<img src="/directplus_ent/images/banners/bnr_fiscal_year.jpg" width="1440" height="375" alt="">
		</div>
		<div class="heroBnrColTxt">
			<p class="heroBnrTtl">年度末に向けてITの準備はお早めに！<br class="spHide"><span>お困りごとはぜひHPE DirectPlusコールセンターにご相談ください</span></p>
			<div class="heroBnrTxtCombi">
					<div class="heroBnrTxt">
					最短5営業日で納品できる<br class="spHide">サーバーを随時掲載中
				</div>
				<div class="heroBnrBtn">
					<span class="btn btn-secondary mt0">お早めにご注文ください</span>
				</div>
			</div>
		</div>
	</a>-->
</div>
	
<!--<div class="contentBox heroBnrArea">
	
	<a href="/directplus_ent/promotion/amazongift/?ref=herobnr0001" class="heroBnr heroBnrAmazongift">
		<div class="heroBnrInr">
			<p class="heroBnrTtl">お見積でもらえる、ギフト券がもらえる</p>
			<div class="heroBnrTxt">
				HPE DirectPlusでお見積、抽選で100名様に1,000円分のAmazonギフト券プレゼント<br>
				<span>2021年10月29日（金）17:00<br class="spHide">お申込み分まで</span>
			</div>
			<div class="heroBnrBtn">
				<span class="btn btn-secondary alpha">詳細・応募フォームはこちら</span>
			</div>
		</div>
	</a>
	
	<a href="/directplus_ent/campaign/?ref=herobnr0002" class="heroBnr heroBnrDxouen">
		<div class="heroBnrInr">
			<p class="heroBnrTtl">DX応援キャンペーン</p>
			<div class="heroBnrTxt">
				お客様のデジタルトランスフォーメーションを応援する、<br class="spHide">期間限定特別価格<br>
				<span>2021年10月29日（金）お申込み分まで</span>
			</div>
			<div class="heroBnrBtn">
				<span class="btn btn-secondary alpha">詳細はこちら</span>
			</div>
		</div>
	</a>
	
</div>-->
	
	<!--<div class="heroBnr heroShareNo1">
		<div class="heroShareNo1Inr">
			<p class="heroShareNo1Txt">皆様のご愛顧に感謝申し上げます</p>
			<div class="heroShareNo1Ttl">
				<div class="heroShareNo1TtlPc">
					<div class="heroShareNo1TtlPcLeft">
						<p class="heroShareNo1TtlServer">国内x86サーバー市場<br><span>出荷台数 2四半期連続</span></p>
						<p class="heroShareNo1TtlStorage">国内NAS市場<br><span>出荷台数 7四半期連続</span></p>
					</div>
					<div class="heroShareNo1TtlPcRight">
						<p>シェア<span>No.1</span></p>
					</div>
				</div>
				<div class="heroShareNo1TtlSp">
					<p class="heroShareNo1TtlServer">国内x86サーバー市場 <br class="spHide">出荷台数 2四半期連続 シェアNo.1</p>
					<p class="heroShareNo1TtlStorage">国内NAS市場 <br class="spHide">出荷台数 7四半期連続 シェアNo.1</p>
				</div>
			</div>
		</div>
		<div class="heroShareNo1Note">
			出典：IDC Quarterly Server Tracker 2021Q1(Share by Company, Product Category: x86 OS: Windows,Linux,Unix)<br>
			IDC Worldwide Quarterly Enterprise Storage Systems Tracker - 2021Q1(Share by Company, Installation NAS)
		</div>
	</div>-->
	
