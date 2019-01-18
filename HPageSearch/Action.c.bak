Action()
{
	//相册动态查询涉及接口（单接口)

	web_reg_save_param_ex("ParamName=status",
						  "LB=\"status\":",
						  "RB=,\"token\"",
						  "NotFound=warning",
						  "Ordinal=1",
						  SEARCH_FILTERS,
						  LAST);

	lr_start_transaction("进入相册动态");

    web_custom_request("owner",
                       "Url=https://{requestUrl}/service/album/get_album_themes_list.jsp?act=owner&shop_id=&search_value=&search_img=&start_date=&end_date=&page_index=1&client_type=ios&token={userToken}&version=2302&",
                       "Method=GET",
                       "Mode=HTTP",
                       LAST);

		if (atoi(lr_eval_string("{status}")) == 0 ){ 
            lr_output_message("查询成功"); 
		} 
        else{ 
            lr_error_message("查询失败"); 
        }

	lr_end_transaction("进入相册动态",LR_PASS);

	return 0;
}
