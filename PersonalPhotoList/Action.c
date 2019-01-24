Action()
{
//相册动态-->个人相册-->新增商品编辑页-->保存商品-->返回个人相册

	web_reg_save_param_ex("ParamName=shop_id",
						"LB=shop_id\":\"",
						"RB=\",\"watermark\":true",
						"NotFound=warning",
						LAST);

	lr_start_transaction("进入相册动态");

    web_custom_request("owner",
                       "Url={requestUrl}/service/album/get_album_themes_list.jsp?act=owner&token={userToken}&version=2302&",
                       "Method=GET",
                       "Mode=HTTP",
                        LAST);

	lr_end_transaction("进入相册动态",LR_AUTO);

    lr_start_transaction("进入个人相册");

	lr_start_sub_transaction("个人相册页面","进入个人相册");
	
	web_custom_request("single_album",
					   "Url={requestUrl}/service/album/get_album_themes_list.jsp?act=single_album&shop_id={shop_id}&token={userToken}&version=2302",
					   "Method=POST",
				       "Mode=HTTP",
						LAST);

	lr_end_sub_transaction("个人相册页面",LR_AUTO);

	lr_start_sub_transaction("获取相册标签","进入个人相册");

    web_custom_request("get_tags_except",
                       "Url={requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tags_except&has_video=0&shop_id={shop_id}&token={userToken}",
                       "Method=GET",
                       "Mode=HTTP",
                       LAST);

	lr_end_sub_transaction("获取相册标签",LR_AUTO);

	lr_end_transaction("进入个人相册",LR_AUTO);

	lr_start_transaction("进入编辑页");

	web_custom_request("get_all_tag",
					   "URL={requestUrl}/service/album/album_group.jsp?act=get_all_tag&type=0&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	web_custom_request("get_formats",
					   "URL={requestUrl}/service/album/album_theme_format_operation.jsp?act=get_formats&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

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
					   "URL={requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tags&goods_id=&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	web_custom_request("get_tags_1",
					   "URL={requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tags&type=2&tagType=1&goods_id=&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);				 

	lr_end_transaction("进入编辑页",LR_AUTO);

	if(atoi(lr_eval_string("{tagId_count}")) != 0){
		lr_save_string(lr_eval_string("0"),"tagId_random");
		lr_save_string(lr_eval_string("{randomNum}"),"tagName_random");
	}else{
		lr_save_string(lr_paramarr_random("tagName"), "tagName_random"); 
		lr_save_string(lr_paramarr_random("tagId"), "tagId_random"); 
	}

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

    lr_start_transaction("返回个人相册");

	lr_start_sub_transaction("获取相册标签","返回个人相册");

    web_custom_request("get_tags_except_2",
                       "Url={requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tags_except&has_video=0&shop_id={shop_id}&token={userToken}",
                       "Method=GET",
                       "Mode=HTTP",
                       LAST);

	lr_end_sub_transaction("获取相册标签",LR_AUTO);

	lr_start_sub_transaction("个人相册页面","返回个人相册");

	web_custom_request("single_album_1",
					   "Url={requestUrl}/service/album/get_album_themes_list.jsp?act=single_album&shop_id={shop_id}&search_value=&search_img=&start_date=&end_date=&tag=&page_index=1&from_id=&client_type=ios&token={userToken}&version=2302",
					   "Method=GET",
				       "Mode=HTTP",
						LAST);

	lr_end_sub_transaction("个人相册页面",LR_AUTO);

	lr_end_transaction("返回个人相册",LR_AUTO);

	return 0;
}
