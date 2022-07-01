$(function(){
$(".accordion_faq dt").click(function(){
    $(this).next("dd").slideToggle();
    $(this).next("dd").siblings("dd").slideUp();
    $(this).toggleClass("open");   
    $(this).siblings("dt").removeClass("open");
});
 
});