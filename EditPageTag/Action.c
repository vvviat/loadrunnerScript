Action()
{
/*
owner
https://www.szwego.com/service/album/album_group.jsp?act=get_all_tag&type=0&_=1548302377606
https://www.szwego.com/service/album/album_theme_format_operation.jsp?act=get_formats&_=1548302377605
https://www.szwego.com/service/album/album_theme_tag_operation.jsp?act=get_tags&goods_id=I201812290951152240108414&_=1548302377604
https://www.szwego.com/service/album/get_album_themes_list.jsp?act=single_item&shop_id=A201812080953300270014587&goods_id=I201812290951152240108414&_=1548302377603
*/
// SEARCH_FILTERS

	web_set_max_html_param_len("10240");

	web_reg_save_param_ex("ParamName=shop_id",
						  "LB=shop_id\":\"",
						  "RB=\",\"watermark\":true",
						  LAST);
/*
	web_reg_save_param_ex("ParamName=goods_id",
						  "LB=goods_id\":\"",
						  "RB=\",\"miniapp_name",
						  "Ordinal=all",
						  LAST);
*/
	web_custom_request("owner",
					   "URL={requestUrl}/service/album/get_album_themes_list.jsp?act=owner&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

//	lr_log_message(lr_eval_string("{shop_id}"));

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

	lr_end_transaction("进入编辑页",LR_PASS);

	return 0;
}
