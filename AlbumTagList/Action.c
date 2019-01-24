Action()
{

	
	web_set_max_html_param_len("50000");

	web_reg_save_param_ex(
						"ParamName=shop_id",
						"LB=\"shop_id\":\"",
						"RB=\",\"watermark\":true",
						SEARCH_FILTERS,
						LAST);


	web_custom_request("owner",
					   "URL={requestUrl}/service/album/get_album_themes_list.jsp?act=owner&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

//	lr_output_message(lr_eval_string("{shop_id}"));

	web_reg_save_param_ex("ParamName=tag_Id",
						  "LB=tagId\":",
						  "RB=,\"count",
						  "Ordinal=all",
						  SEARCH_FILTERS,
						  LAST);


	web_custom_request("get_tags_except",
					   "URL={requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tags_except&has_video=0&shop_id={shop_id}&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);



	lr_save_string(lr_paramarr_random("tag_Id"), "tag_Id_random"); 

//	lr_output_message(lr_eval_string("{tag_Id_random}"));

/*	
检查点：
web_reg_find("Fail=NotFound",
		"Search=Body",
		"SaveCount=success",
		"Text={tag_Id_random}",
		LAST);
*/
	
	if(atoi(lr_eval_string("{tag_Id_count}")) > 1){

	lr_start_transaction("标签独立页");

	web_custom_request("tag_list",
					   "URL={requestUrl}/service/album/get_album_themes_list.jsp?act=tag_list&shop_id={shop_id}&tag_id=[{tag_Id_random}]&group_id=&search_value=&search_img=&start_date=&end_date=&from_id=",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	lr_end_transaction("标签独立页",LR_AUTO);

	}else{

		lr_output_message("该用户商店个人相册：%s，无标签",lr_eval_string("{shop_id}"));
	}


	return 0;
}
