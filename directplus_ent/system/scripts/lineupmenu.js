
$(function(){
$("#featured > ul").tabs({fx:{opacity: "toggle"}}).tabs("rotate", 4000, true);
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
		
$(function (){
$(".contents:gt(0)").css("display","none");

$("#tab li").click(function() {
var num = $("#tab li").index(this);
$("#tab li").removeClass("now");
$(this).addClass("now");

$(".contents").css("display","none");
$(".contents").eq(num).css("display","block");
});
});

jQuery(function($){
        function equalHeight(group) {
            tallest = 0;
            group.each(function() {
                thisHeight = $(this).height();
                if(thisHeight > tallest){
                    tallest = thisHeight;
                }
            });
			
            group.height(tallest);
        }
      
        $(document).ready(function() {
           //.hoge-singleを付与された要素同士の高さを揃える
            equalHeight($(".clumn_midashi"));
            equalHeight($(".clumn1"));
            equalHeight($(".clumn2"));
            equalHeight($(".clumn3"));
            equalHeight($(".clumn4"));
            equalHeight($(".clumn5"));
            equalHeight($(".clumn6"));
            equalHeight($(".clumn7"));
            equalHeight($(".clumn8"));
            equalHeight($(".clumn9"));
            equalHeight($(".clumn10"));
            equalHeight($(".clumn11"));
            equalHeight($(".clumn12"));
            equalHeight($(".clumn13"));
            equalHeight($(".clumn14"));
            equalHeight($(".clumn15"));
            equalHeight($(".clumn16"));
            equalHeight($(".clumn17"));
            equalHeight($(".clumn18"));
            equalHeight($(".clumn19"));
            equalHeight($(".clumn20"));
        });
    });

$(function(){
	var box = $('.tab-box');
	var tabList = $('.tab-list').find('li');
	box.hide();
	tabList.click(function(){
		var tabIndex = tabList.index(this);
		box.hide().eq(tabIndex).show();
	    
		$('a[href=#]').click(function(e){e.preventDefault();
		})  
	});
});


/*製品ラインアップ*/
$('.wo_navi_select').mouseover(function(e){
		if($(this).html() == "製品ラインアップ") {
			$('#lineup_navigation').show();
			}
		else {
			$('#lineup_navigation').hide();
		}
});
$('.wo_navi_select').click(function(){
		if($(this).html() == "製品ラインアップ") {
			$('#lineup_navigation').show();
			}
		else {
			$('#lineup_navigation').hide();
		}
});



$(function(){
	$("#lineup_navigation").click(function(){
		$("#lineup_navigation").css("display","block");
	})
	$(".close a").click(function(){
		$("#lineup_navigation").css("display","none");
		return false;
	});
});


var NavigationHover = false;

	$("#lineup_navigation").hover(function(){
		NavigationHover = true;
	}, function(){
		NavigationHover = false;
	});
	$("body").mouseup(function(){
		if(!NavigationHover) $("#lineup_navigation").hide();
	});


/*
$("div").not(".lineup_navigationBox").find("div").click(function(){
	$("#lineup_navigation")	.hide();			
});
*/



/*マイアカウント*/
$('.wo_navi_select').mouseover(function(e){
	if($(this).html() == "マイアカウント") {
		$('#myaccounts_navigation').show();
	}
		else {
		$('#myaccounts_navigation').hide();
	}
});
$('.wo_navi_select').click(function(){
	if($(this).html() == "マイアカウント") {
		$('#myaccounts_navigation').show();
	}
		else {
		$('#myaccounts_navigation').hide();
	}
});


$(function(){
	$("#myaccounts_navigation").click(function(){
		$("#myaccounts_navigation").css("display","block");
	})
	$(".close a").click(function(){
		$("#myaccounts_navigation").css("display","none");
		return false;
	});
});


	$("#myaccounts_navigation").hover(function(){
		NavigationHover = true;
	}, function(){
		NavigationHover = false;
	});
	$("body").mouseup(function(){
		if(!NavigationHover) $("#myaccounts_navigation").hide();
	});


/*サーバー ストレージ*/
$('.wo_nav2-main').mouseover(function(e){
	if($(this).html() == "サーバー/ストレージ") {
		$('#option_navigation').show();
	}
		else {
	$('#servers_navigation').hide();
	}
});

$(function(){
	$("#servers_navigation").click(function(){
		$("#servers_navigation").css("display","block");
	})
	$(".close a").click(function(){
		$("#servers_navigation").css("display","none");
		return false;
	});
});





/*サーバー ストレージ*/
$('.wo_nav2-main').mouseover(function(e){
	if($(this).html() == "サーバー/ストレージ") {
		$('#option_navigation').show();
	}
		else {
	$('#servers_navigation').hide();
	}
});

$(function(){
	$("#servers_navigation").click(function(){
		$("#servers_navigation").css("display","block");
	})
	$(".close a").click(function(){
		$("#servers_navigation").css("display","none");
		return false;
	});
});



/*オプション*/
$('.wo_nav2-main').mouseover(function(e){
	if($(this).html() == "オプション") {
		$('#option_navigation').show();
	}
		else {
	$('#option_navigation').hide();
	}
});

$(function(){
	$("#option_navigation").click(function(){
		$("#option_navigation").css("display","block");
	})
	$(".close a").click(function(){
		$("#option_navigation").css("display","none");
		return false;
	});
});


/*お知らせ*/
$('.wo_nav2-main').mouseover(function(e){
	if($(this).html() == "お知らせ") {
		$('#notice_navigation').show();
	}
		else {
	$('#notice_navigation').hide();
	}
});

$(function(){
	$("#notice_navigation").click(function(){
		$("#notice_navigation").css("display","block");
	})
	$(".close a").click(function(){
		$("#notice_navigation").css("display","none");
		return false;
	});
});




/*オプション アコーディオン*/
$(function(){
	$("#accordion_op dd:not(:first)").css("display","none");
	$("#accordion_op dl dt").click(function(){
		if($("+dd",this).css("display")=="none"){
			$("+dd",this).slideDown();
		}
		else{
			$("+dd",this).slideUp();
		}
	});
});