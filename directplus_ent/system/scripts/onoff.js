(function($){
$(document).ready(function(){

//rollover
$('a img').hover(function(){
$(this).attr('src', $(this).attr('src').replace('_off', '_on'));
}, function(){
if (!$(this).hasClass('currentPage')) {
$(this).attr('src', $(this).attr('src').replace('_on', '_off'));
}
});


});
})(jQuery);

