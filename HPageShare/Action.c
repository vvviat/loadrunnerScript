Action()
{

//首页-->相册动态，长按分享图片，保存商品



	web_reg_save_param_ex(
	"ParamName=goods_id_list",
	"LB=goods_id\":\"",
	"RB=\",\"miniapp_name",
	"NotFound=warning",
    "Ordinal=All",
	SEARCH_FILTERS,
	LAST);	

	web_reg_save_param_ex(
	"ParamName=shop_id_list",
	"LB=shop_id\":\"",
	"RB=\",\"subimgsSrc",
	"NotFound=warning",
    "Ordinal=All",
	SEARCH_FILTERS,
	LAST);

	web_reg_save_param_ex(
	"ParamName=title",
	"LB=title\":\"",
	"RB=\",\"videoURL",
	"NotFound=warning",
	"Ordinal=All",
	SEARCH_FILTERS,
	LAST);

	web_reg_save_param_ex(
	"ParamName=imges",
	"LB=imgsSrc\":",
	"RB=,\"old_time",
	"NotFound=warning",
	"Ordinal=All",
	SEARCH_FILTERS,
	LAST);

	web_add_header("Transfer-Encoding","chunked");

    web_custom_request("owner",
                       "Url={requestUrl}/service/album/get_album_themes_list.jsp?act=owner&shop_id=&search_value=&search_img=&start_date=&end_date=&page_index=1&client_type=ios&token={userToken}&version=2302&",
                       "Method=GET",
                       "TargetFrame=",
					   "Resource=0",
					   "Referer=",
                       "Mode=HTTP",
                        LAST);


    //lr_convert_string_encoding("{title}",LR_ENC_SYSTEM_LOCALE,LR_ENC_UTF8,"title");
	web_convert_param("title_5", "SourceEncoding=PLAIN", "TargetEncoding=URL", LAST ); 

	//lr_output_message(lr_eval_string("{title_5}"));

    web_convert_param("imges_3", "SourceEncoding=PLAIN", "TargetEncoding=URL", LAST ); 

	lr_start_transaction("分享商品");

	lr_start_sub_transaction("一键分享","分享商品");

	web_custom_request("hold_theme",
					   "URL={requestUrl}/service/album/album_theme_operation.jsp?act=hold_theme&client_type=ios&token={userToken}&version=2302&shop_id={shop_id_list_2}&goods_id={goods_id_list_2}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	lr_end_sub_transaction("一键分享",LR_AUTO);


	lr_start_sub_transaction("获取商品属性","分享商品");

	web_custom_request("get_markcode",
					   "URL={requestUrl}/service/album/album_theme_operation.jsp?act=get_markcode&client_type=ios&goods_id={goods_id_list_2}&platform=app&shop_id={shop_id_list_2}&token={userToken}&version=2302",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	web_custom_request("get_all_tag",
					   "URL={requestUrl}/service/album/album_group.jsp?act=get_all_tag&client_type=ios&platform=app&token={userToken}&version=2302",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	lr_end_sub_transaction("获取商品属性",LR_AUTO);

	lr_start_sub_transaction("获取用户是否vip","分享商品");

	web_custom_request("get_vip_object",
					   "URL={requestUrl}/service/account/user_info_operation.jsp?act=get_vip_object&client_type=ios&platform=app&token={userToken}&version=2302",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	lr_end_sub_transaction("获取用户是否vip",LR_AUTO);


	lr_start_sub_transaction("保存商品","分享商品");

	web_custom_request("save_theme",
					   "URL={requestUrl}/service/album/album_theme_operation.jsp",
					   "Method=POST",
					   "Mode=HTTP",
					   "Body=act=save_theme&album_id={shop_id_list_2}&client_type=ios&item_id={goods_id_list_2}&main_imgs={imges_3}&mark_code=&personal=0&platform=app&share_type=2&source_type=100&source_URL=&sub_imgs=&token={userToken}&version=2302&title={title_5}",
					   LAST);

	lr_end_sub_transaction("保存商品",LR_AUTO);

	lr_end_transaction("分享商品",LR_AUTO);

	return 0;
}
