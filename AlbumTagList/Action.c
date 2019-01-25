Action()
{

	int randomNum;

	randomNum=rand()%3+1;

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

	web_reg_save_param_ex("ParamName=tag_Id",
						  "LB=tagId\":",
						  "RB=,\"count",
						  "Ordinal=all",
						  SEARCH_FILTERS,
						  LAST);

	lr_start_transaction("个人相册页");


	web_custom_request("get_tags_except",
					   "URL={requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tags_except&has_video=0&shop_id={shop_id}&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	lr_save_string(lr_paramarr_random("tag_Id"), "tag_Id_random"); 

/*
消息函数
	lr_message("lr_message消息函数:%s",lr_eval_string("{tag_Id_random}"));
	lr_output_message("output消息:%s",lr_eval_string("{tag_Id_random}"));
	lr_error_message("error消息:%s",lr_eval_string("{tag_Id_random}"));
	//前3不收日志开关控制
	lr_log_message("log日志消息:%s",lr_eval_string("{tag_Id_random}"));
	lr_debug_message(LR_MSG_CLASS_BRIEF_LOG, "debug调试消息:%s",lr_eval_string("{tag_Id_random}"));
*/

/*	
检查点：
	web_reg_find("Fail=NotFound",
			"Search=Body",
			"SaveCount=success",
			"Text={tag_Id_random}",
			LAST);
*/
	lr_think_time(3);

	lr_start_sub_transaction("标签独立页","个人相册页");

	lr_message("lr_message消息函数:%s",lr_eval_string("{tag_Id_count}"));
	lr_save_int(randomNum, "randomNum");
//	lr_message("lr_message消息save整型函数:%d",randomNum);

    
	if(atoi(lr_eval_string("{tag_Id_count}")) > 0){

//	if(strcmp(lr_eval_string("{tag_Id_count}"),lr_eval_string("{randomNum}")) ==0 ){

//	lr_message("lr_message成功消息:%s",lr_eval_string("{randomNum}"));

	web_custom_request("tag_list",
					   "URL={requestUrl}/service/album/get_album_themes_list.jsp?act=tag_list&shop_id={shop_id}&tag_id=[{tag_Id_random}]&group_id=&search_value=&search_img=&start_date=&end_date=&from_id=",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

		lr_end_sub_transaction("标签独立页",LR_PASS);

	}else{

//		lr_message("lr_message失败消息:%s",lr_eval_string("{randomNum}"));

		lr_end_sub_transaction("标签独立页",LR_FAIL);

//		lr_output_message("该用户商店个人相册：%s，无标签",lr_eval_string("{shop_id}"));
	}

	lr_end_transaction("个人相册页",LR_AUTO);


	return 0;
}
