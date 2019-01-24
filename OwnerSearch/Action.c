Action()
{

	web_reg_save_param_ex("ParamName=status",
						  "LB=\"status\":",
						  "RB=,\"token\"",
						  "NotFound=warning",
						  "Ordinal=1",
						  SEARCH_FILTERS,
						  LAST);

	lr_start_transaction("首页动态");

    web_custom_request("owner",
                       "Url={requestUrl}/service/album/get_album_themes_list.jsp?act=owner&shop_id=&search_value=&search_img=&start_date=&end_date=&page_index=1&client_type=ios&token={userToken}&version=2302&",
                       "Method=GET",
                       "TargetFrame=",
					   "Resource=0",
					   "Referer=",
                       "Mode=HTTP",
                        LAST);

	if (atoi(lr_eval_string("{status}")) == 0 ){ 
            lr_end_transaction("首页动态",LR_PASS);
		} 
        else{ 
            lr_end_transaction("首页动态",LR_FAIL);
        }

	return 0;
}
