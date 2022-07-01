<style>
.stock-banner {
	background: url('/directplus_ent/server/images/stock_1000x180.jpg') no-repeat;
	background-size: 100% 100%;
	color: #fff;
	padding: 15px;
	box-sizing: border-box;
	display: flex;
	align-items: center;
	justify-content: space-between;
}
.stock-banner__txt {
	font-size: 20px;
	font-weight: bold;
	line-height: 1.41;
}
.stock-banner__btn .btn {
	background: rgba(0, 0, 0, 0.4);
	color: #fff;
	transition: background 0.5s;
	font-size: 14px;
	font-weight: bold;
	margin: 0 0 0 15px;
}
.stock-banner__btn .btn:hover {
	background: rgba(0, 0, 0, 0.6);
	transition: background 0.5s;
}
@media (min-width: 1000px) and (max-width: 1200px) {
	.stock-banner {
		width: calc(100vw - 220px);
	}
}
@media (min-width: 768px) {
	.stock-banner__txt {
		flex-basis: calc(100% - 350px);
	}
	.stock-banner__btn {
		flex-basis: 350px;
		text-align: right;
	}
}
@media (max-width: 767px) {
	.stock-banner {
		background: url('/directplus_ent/server/images/stock_1000x1000.jpg') no-repeat;
		background-size: cover;
		flex-direction: column;
	}
	.stock-banner__txt {
		padding: 20px 0 15px;
	}
	.stock-banner__btn {
		text-align: center;
		padding: 0 0 20px;
	}
	.stock-banner__btn .btn {
		margin: 0;
		padding: 10px;
	}
}
@media (max-width: 414px) {
	.stock-banner__txt {
		width: 100%;
	}
	.stock-banner__btn .btn {
		display: block;
		font-size: 12px;
		width: 100%;
		max-width: 290px;
	}
}
@media (max-width: 375px) {
	.stock-banner {
		padding: 0 10px;
	}
}
</style>
<div class="stock-banner mb30">
	<div class="stock-banner__txt">
		「いま5営業日で納品可能なサーバー製品」はこちら（毎週更新）
	</div>
	<div class="stock-banner__btn">
		<a href="/directplus_ent/server/delivery.html" class="btn btn-secondary" role="button">
			お早めにご注文ください
		</a>
	</div>
</div>
