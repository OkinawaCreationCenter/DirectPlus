
//$(function(){
//$("#topBanner > ul").tabs({fx:{opacity: "toggle"}}).tabs("rotate", 4000, true);
//});

$(function(){
	var stab = 0;
	$("#topBanner > ul").tabs({
		selected: stab,
		fx:{
			opacity: "toggle",
		}
	})
	.tabs("rotate", 4000, true);
});


$(function() {
	var offset = $("#sidebar").offset();
	var topPadding = 35;
	$(window).scroll(function() {
		if ($(window).scrollTop() > offset.top) {
			$("#sidebar").stop().animate({
				marginTop: $(window).scrollTop() - offset.top + topPadding
			});
		} else {
			$("#sidebar").stop().animate({
				marginTop: 0
			});
		};
	});
});
		











