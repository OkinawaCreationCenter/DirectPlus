<style>
.bnr_video_guide {
	display: inline-flex;
	align-items: center;
	justify-content: space-between;
	padding: 15px;
}
.bnr_video_guide > * {
	flex: 1 1 auto;
	white-space: nowrap;
}
.bnr_video_guide > .clm1 {
	display: flex;
	align-items: flex-end;
	justify-content: space-between;
	min-width: calc(53px + 66px + 56px + 50px + 45px);
	margin-right: 40px;
}
.bnr_video_guide > .clm2 > *:not(:last-child) {
	margin-bottom: 10px;
}
@media (max-width: 767px) {
	.bnr_video_guide {
		display: flex;
		flex-direction: column;
		align-items: center;
		justify-content: center;
		width: 100%;
	}
	.bnr_video_guide > .clm1 {
		margin: 0 0 15px;
	}
}
@media (max-width: 414px) {
	.bnr_video_guide > .clm2 {
		width: 100%;
	}
}
@media (max-width: 374px) {
	.bnr_video_guide > .clm1 {
		min-width: unset;
		width: 100%;
	}
}
</style>
<a class="bnr_video_guide gryBdr1px hasLinkWithArrow" href="/directplus_ent/guide/video/">
	<div class="clm1">
		<img src="/directplus_ent/guide/video/images/icon_01.png" alt="" width="53" height="66"><img src="/directplus_ent/guide/video/images/icon_02.png" alt="" width="66" height="59"><img src="/directplus_ent/guide/video/images/icon_03.png" alt="" width="56" height="59"><img src="/directplus_ent/guide/video/images/icon_04.png" alt="" width="50" height="66">
	</div>
	<div class="clm2 lhMid">
		<div class="f16 bold">
			動画で解説 <br class="br374"><!--#include virtual="/comm/include/directplus_name.inc" --> ご利用ガイド
		</div>
		<div class="alignRgt">
			<span class="linkWithArrow">
				動画版ご利用ガイドはこちら
				<span class="arrow">→</span>
			</span>
		</div>
	</div>
</a>
