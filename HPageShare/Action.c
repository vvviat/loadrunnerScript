Action()
{
//首页，分享图片
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

	lr_start_transaction("加载app首页");

    web_custom_request("owner",
                       "Url=https://{requestUrl}/service/album/get_album_themes_list.jsp?act=owner&search_value=&search_img=&start_date=&end_date=&page_index=1&token={userToken}",
                       "Method=GET",
                       "Mode=HTTP",
                       LAST);

	lr_end_transaction("加载app首页",LR_PASS);

	lr_save_string(lr_paramarr_random("goods_id_list"), "goods_id_random");
	lr_save_string(lr_paramarr_random("shop_id_list"), "shop_id_random");

	lr_start_transaction("分享商品");

    web_custom_request("share_plat",
                       "Url=https://{requestUrl}/service/album/share_operation.jsp?act=share_plat&search_value=&albumId={shop_id_random}&itemId={goods_id_random}&token={userToken}",
                       "Method=GET",
                       "Mode=HTTP",
                       LAST);

	lr_end_transaction("分享商品",LR_PASS);

	return 0;
}
