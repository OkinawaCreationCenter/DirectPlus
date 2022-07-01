<style>
.stock-banner {
	background: url('/directplus_ent/server/images/stock_1000x180.jpg') no-repeat;
	background-size: 100% 100%;
	color: #fff;
	padding: 0 15px;
	box-sizing: border-box;
}
.stock-banner__row {
	display: flex;
	justify-content: space-between;
}
/* 1行目 */
.stock-banner__row:first-child > * {
	flex-basis: 50%;
	flex-grow: 0;
	flex-shrink: 0;
}
.stock-banner__row:first-child {
	padding: 20px 0 0;
}
.stock-banner__row:first-child > .col1 {
	text-align: center;
	display: flex;
	align-items: center;
	justify-content: center;
	font-size: 22px;
	font-weight: bold;
}
.stock-banner__row:first-child > .col1 span {
	font-size: 44px;
}
.stock-banner__row:first-child > .col2 {
	display: flex;
	align-items: center;
	justify-content: center;
	font-size: 24px;
	font-weight: bold;
	line-height: 1.2;
	padding: 10px 0;
}
.stock-banner__row:first-child > .col2 span {
	font-size: 15px;
}
/* 最終行 */
.stock-banner__row:last-child {
	padding: 20px 0;
}
.stock-banner__row:last-child > * {
	flex: 1;
	flex-grow: 1;
	flex-shrink: 0;
}
.stock-banner__row:last-child > .col1 {
	font-size: 12px;
}
.stock-banner__row:last-child > .col2 .btn {
	background: rgba(0, 0, 0, 0.4);
	color: #fff;
	transition: background 0.5s;
	font-size: 14px;
	font-weight: bold;
	margin: 0 0 0 15px;
}
.stock-banner__row:last-child > .col2 .btn:hover {
	background: rgba(0, 0, 0, 0.6);
	transition: background 0.5s;
}
@media (min-width: 1000px) and (max-width: 1200px) {
	.stock-banner {
		width: calc(100vw - 220px);
	}
}
@media (min-width: 768px) {
	.stock-banner__row:first-child > .col1 {
		border-right: 1px solid #fff;
	}
}
@media (min-width: 768px) {
	.stock-banner__row:last-child > .col1 {
		flex-basis: calc(100% - 350px);
	}
	.stock-banner__row:last-child > .col2 {
		flex-basis: 350px;
		text-align: right;
	}
}
@media (max-width: 767px) {
	.stock-banner {
		background: url('/directplus_ent/server/images/stock_1000x1000.jpg') no-repeat;
		background-size: 100% 100%;
	}
	.stock-banner__row {
		flex-direction: column;
	}
	.stock-banner__row:first-child > .col1 {
		font-size: 20px;
	}
	.stock-banner__row:first-child > .col1 span {
		font-size: 35px;
	}
	.stock-banner__row:first-child > .col2 {
		font-size: 22px;
		text-align: center;
		padding: 0 0 15px;
	}
	.stock-banner__row:first-child > .col2 span {
		font-size: 15px;
	}
	.stock-banner__row:last-child {
		align-items: center;
		padding: 0 0 20px;
	}
	.stock-banner__row:last-child > .col1 {
		order: 2;
		font-size: 10px;
		margin-top: 15px;
	}
	.stock-banner__row:last-child > .col2 {
		order: 1;
		font-size: 13px;
	}
	.stock-banner__row:last-child > .col2 .btn {
		margin: 0 auto;
	}
}
@media (max-width: 414px) {
	.stock-banner__row:last-child > .col2 {
		width: 100%;
	}
	.stock-banner__row:last-child > .col2 .btn {
		padding-left: 0;
		padding-right: 0;
		display: block;
		font-size: 12px;
		max-width: 290px;
	}
}
@media (max-width: 375px) {
	.stock-banner {
		padding: 0 10px;
	}
}
</style>
<div class="stock-banner mb40">
	<div class="stock-banner__row">
		<div class="col1">
			<div>
				最短<span>5営業日</span>で納品
			</div>
		</div>
		<div class="col2">
			<div>
				<span>毎週更新！</span><br>
				いま5営業日で納品可能な<br>
				サーバー製品はこちら
			</div>
		</div>
	</div>
	<div class="stock-banner__row">
		<div class="col1">
			<p class="indent-1">
				※弊社需要予測に基づいて在庫を準備しております。
			</p>
			<p class="indent-1">
				※在庫状況についてのお問い合わせはHPE DirectPlusコールセンターへご相談ください。
			</p>
		</div>
		<div class="col2">
			<a href="/directplus_ent/server/delivery.html" class="btn btn-secondary" role="button">
				在庫大増量中！お早めにご注文ください
			</a>
		</div>
	</div>
</div>
