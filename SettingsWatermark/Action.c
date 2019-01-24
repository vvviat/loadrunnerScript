Action()
{

	int result;
	int HttpRetCode;

	web_reg_save_param_ex("ParamName=watermark",
						  "LB=watermark\":",
						  "RB=,\"dev",
						  SEARCH_FILTERS,
						  LAST);

	web_custom_request("get_settings",
					   "URL={requestUrl}/service/album/album_user_setting_operation.jsp?act=get_settings&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	//lr_log_message(lr_eval_string("{watermark}"));

    HttpRetCode = web_get_int_property(HTTP_INFO_RETURN_CODE);

	if(HttpRetCode==200){
		//lr_log_message("执行成功！");
	}else{
		lr_log_message("执行失败，再执行一次！");

		web_custom_request("get_settings",
					   "URL={requestUrl}/service/album/album_user_setting_operation.jsp?act=get_settings&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);
	}

	result = strcmp(lr_eval_string("{watermark}"),lr_eval_string("false"));

	if( result == 0){

	//lr_log_message("用户watermark设置%s,开启水印。",lr_eval_string("{watermark}"));

	web_custom_request("save_settings",
					   "URL={requestUrl}/service/album/album_user_setting_operation.jsp?act=save_settings&setting_type=watermark&token={userToken}",
					   "Method=POST",
					   "Mode=HTTP",
					   LAST);

	}else{
		//lr_log_message("用户已开启watermark设置为：%s",lr_eval_string("{watermark}"));

	}

	return 0;
}
