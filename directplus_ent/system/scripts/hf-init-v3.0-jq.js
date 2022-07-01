
(function($,HP,HF){
	
	HP.caasDomain=HP.caasDomain;
	
	var readCookie=function(key){
		if(!name)return;
		if(document.cookie&&document.cookie!=''){
			var cookies=document.cookie.split(';');
				for(var i=0;i<cookies.length;i++){
					var c=$.trim(cookies[i]);
					if(c.indexOf(name+'=')==0){
						return decodeURIComponent(c.substring(name.length+1));
					}
				}
		}
		return null;
	};
	

	
	HP.Utils=HP.Utils||{
		ready:function(){}
	};
	
	HP.hfInit=function(params){
		var defaultParams={};
		var p=$.extend(defaultParams,params);
		HF.Utils.ready(function(){
			var cats=[];
			var searchBox=can.$('#searchBox');
			var searchContainer=searchBox.parent();
			
			initSearchBoxSliding(searchBox,searchContainer);
			hfAutocompleteStart(cats,p.autocompleteURL,{
				language:p.languageCode,
				cc:p.countryCode,
				widthElement:searchContainer,
				requestType:'jsonp',
				sendSSData:p.autocompleteSSRequest
			});
				
			initSkipLinks();
			HF.Control.init(HF.PrimaryNavigation,'.js_menu .selectable');
			HF.Control.init(HF.ShoppingWidget,'.js_shopping_widget');
			HF.Control.init(HF.InputPrompt,'.searchBox',{activeClass:''});
			HF.Control.init(HF.CountrySelector,'.js_cselector',{url:p.countrySelectorURL,requestType:'jsonp'});
			initHFMetrics('.link_metrics');
			window.initHFMetrics=function(){};
			
			HP.HF_IS_READY=true;});};})(can.$,window.HP||(window.HP={}),window.HF||(window.HF={}));

/*
Date: 11/14/2013 7:28:49 PM
All images published
*/