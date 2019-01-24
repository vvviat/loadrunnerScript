Action()
{

	web_reg_save_param_ex("ParamName=tagId",
						  "LB=tagId\":",
						  "RB=,\"count",
						  "Ordinal=all",
						  SEARCH_FILTERS,
						  "Scope=BODY",
						  LAST);
	
	web_reg_save_param_ex("ParamName=tagName",
						  "LB=tagName\":\"",
						  "RB=\",\"order",
						  "Ordinal=all",
						  SEARCH_FILTERS,
						  "Scope=BODY",
						  LAST);


	web_custom_request("get_tags",
					   "URL={requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tags&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	if(atoi(lr_eval_string("{tagId_count}")) != 0){
		lr_save_string(lr_eval_string("0"),"tagId_random");
		lr_save_string(lr_eval_string("{randomNum}"),"tagName_random");
	}else{
		lr_save_string(lr_paramarr_random("tagName"), "tagName_random"); 
		lr_save_string(lr_paramarr_random("tagId"), "tagId_random"); 
	}

//	lr_output_message("随机给一个值：%d","{tagId_random}");
//	lr_output_message("随机给一个值：%d","{tagName_random}");

	lr_start_transaction("新增save商品");

	if(atoi(lr_eval_string("{tagId_count}")) > 1){

	web_custom_request("CreateNewGoods",
					   "URL={requestUrl}/service/album/album_theme_operation.jsp?act=save_theme&token={userToken}",
					   "Method=POST",
					   "Mode=HTTP",
					   "Body=id=&title=Testing_No_{randomNum}&main_imgs={imageUrl}&tags=%5B%7B%22tagId%22%3A{tagId_random}%2C%22tagName%22%3A{tagName_random}%7D%5D&groups=%5B%5D&personal=0&personalTagIds=%5B%5D&sources=%5B%5D&goodsNum=A_No_{randomNum}&formats=%5B%7B%22formatName%22%3A%22ABC_{randomNum}%22%7D%5D&priceArr=%5B%7B%22type%22%3A%22price%22%2C%22label%22%3A%22%E6%89%B9%E5%8F%91%E4%BB%B7%22%2C%22value%22%3A%22{randomNum}%22%2C%22permission%22%3A0%2C%22tagIds%22%3A%5B%5D%2C%22priceType%22%3A%223%22%2C%22id%22%3A%22%22%7D%2C%7B%22type%22%3A%22price%22%2C%22label%22%3A%22%E6%8B%BF%E8%B4%A7%E4%BB%B7%22%2C%22value%22%3A%22{randomNum}%22%2C%22permission%22%3A1%2C%22tagIds%22%3A%5B%5D%2C%22priceType%22%3A1%2C%22id%22%3A%22%22%7D%5D&noteArr=%5B%7B%22type%22%3A%22note%22%2C%22label%22%3A%22%22%2C%22value%22%3A%22%E5%85%AC%E5%BC%80%22%2C%22permission%22%3A0%2C%22tagIds%22%3A%5B%5D%2C%22id%22%3A%22%22%7D%5D",
					   LAST);

		lr_end_transaction("新增save商品",LR_PASS);
	}else{
		lr_end_transaction("新增save商品",LR_FAIL);
	}

	return 0;
}
