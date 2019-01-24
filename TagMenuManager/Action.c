Action()
{


	web_reg_save_param_ex("ParamName=tag_id_list",
						  "LB=tagId\":",
						  "RB=,\"count",
						  "Ordinal=all",
						  LAST);


	web_custom_request("get_tags",
					   "URL={requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tags&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	lr_save_string(lr_paramarr_random("tag_id_list"), "tag_id_random"); 

	lr_start_transaction("目录标签页查询");

	if(atoi(lr_eval_string("{tag_id_random}")) > 1){

	web_custom_request("get_tags_detail",
					   "URL={requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tag_detail&tag_id={tag_id_random}&page_index=1&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	lr_end_transaction("目录标签页查询",LR_PASS);

	}else{

	lr_end_transaction("目录标签页查询",LR_FAIL);

	}

	return 0;
}
