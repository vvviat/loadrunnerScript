Action()
{
//进入编辑商品，分享，返回首页
	lr_start_transaction("编辑商品信息窗口");

	web_custom_request("get_tags1",
				   "Url=https://{requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tags&type=2&goods_id=&token={userToken}",
				   "Method=get",
				   "Mode=HTTP",
				   "LAST");
	web_custom_request("get_tags2",
				   "Url=https://{requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tags&type=2&tagType=1&goods_id=&token={userToken}",
				   "Method=get",
				   "Mode=HTTP",
				   "LAST");
	web_custom_request("get_formats",
				   "Url=https://{requestUrl}/service/album/album_theme_format_operation.jsp?act=get_formats&token={userToken}",
				   "Method=get",
				   "Mode=HTTP",
				   "LAST");
	web_custom_request("get_qiuniu_token",
				   "Url=https://{requestUrl}/service/get_qiuniu_token.jsp",
				   "Method=get",
				   "Mode=HTTP",
				   "LAST");

	lr_end_transaction("编辑商品信息窗口",LR_PASS);

	
	web_reg_save_param_ex(
	"ParamName=save_theme",
	"LB=\"album_id\":\"",
	"RB=\",\"id",
	"NotFound=warning",
	SEARCH_FILTERS,
	LAST);

	lr_rendezvous("concurrentSave");

	lr_start_transaction("分享商品");

	web_custom_request("save_theme",
				   "Url=https://{requestUrl}/service/album/album_theme_operation.jsp?act=save_theme&id=&title=this+is+a+testing{randomNum}&main_imgs=%5B%22https%3A%2F%2Fxcimg.szwego.com%2Fo_1cugmnv8m1ksr1m6v4j41e0t1n7jp.jpg%22%2C%22https%3A%2F%2Fxcimg.szwego.com%2Fo_1cugmo6o2129b1up11rsk176qelgv.png%22%5D&tags=%5B%5D&personal=0&personalTagIds=%5B%5D&sources=%5B%5D&goodsNum=&formats=%5B%5D&priceArr=%5B%5D&noteArr=%5B%5D&token={userToken}",
				   "Method=POST",
				   "Mode=HTTP",
				   "LAST");

	lr_end_transaction("分享商品",LR_PASS);


	lr_start_transaction("回到首页");

	web_custom_request("owner",
				   "Url=https://{requestUrl}/service/album/get_album_themes_list.jsp?act=owner&shop_id={save_theme}&search_value=&search_img=&start_date=&end_date=&page_index=1&slip_type=0&time_stamp=1544600608765&token={userToken}",
				   "Method=POST",
				   "Mode=HTTP",
				   "LAST");

	lr_end_transaction("回到首页",LR_PASS);

	return 0;
}
