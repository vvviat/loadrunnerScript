Action()
{
//从关注好友，发布商品（并发）

	lr_start_transaction("点击已关注");

	web_reg_save_param_ex(
	"ParamName=attention",
	"LB=shop_id\":\"",
	"RB=\",\"total_goods",
	"NotFound=warning",
	SEARCH_FILTERS,
	LAST);

	web_custom_request("attention",
				   "Url=https://{requestUrl}/service/album/get_album_list.jsp?act=attention&search_value=&page_index=1&token={userToken}",
				   "Method=Get",
				   "Mode=HTTP",
				   "LAST");

	lr_end_transaction("点击已关注",LR_AUTO);


	lr_start_transaction("进入好友详情");

	lr_start_sub_transaction("获取所有标签",0);

	web_custom_request("get_tags_except",
				   "Url=https://{requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tags_except&shop_id={attention}&token={userToken}",
				   "Method=Get",
				   "Mode=HTTP",
				   "LAST");
	lr_end_sub_transaction("获取所有标签",LR_PASS);

	lr_start_sub_transaction("获取本地图片",0);

	web_reg_save_param_ex(
	"ParamName=single_album",
	"LB=goods_id\":\"",
	"RB=\",\"miniapp_name",
	"NotFound=warning",
	SEARCH_FILTERS,
	LAST);

	web_custom_request("single_album",
				   "Url=https://{requestUrl}/service/album/get_album_themes_list.jsp?act=single_album&shop_id={attention}&search_value=&search_img=&start_date=&end_date=&tag=[]&page_index=1&from_id=&token={userToken}",
				   "Method=Get",
				   "Mode=HTTP",
				   "LAST");
    
	lr_end_sub_transaction("获取本地图片",LR_PASS);

	lr_start_sub_transaction("用户配置信息",0);

	web_custom_request("get_config",
				   "Url=https://{requestUrl}/service/jsapi_service.jsp?act=get_config&shop_id=&url=https%3A%2F%2Fwww.szwego.com%2Fstatic%2Findex.html%3Ft%3D1544596758444&token={userToken}",
				   "Method=Get",
				   "Mode=HTTP",
				   "LAST");

	lr_end_sub_transaction("用户配置信息",LR_PASS);

	lr_start_sub_transaction("获取七牛token",0);

	web_custom_request("get_qiuniu_token",
				   "Url=https://{requestUrl}/service/get_qiuniu_token.jsp",
				   "Method=Get",
				   "Mode=HTTP",
				   "LAST");

	lr_end_sub_transaction("获取七牛token",LR_PASS);


	lr_end_transaction("进入好友详情",LR_AUTO);


	lr_start_transaction("编辑商品信息");

	lr_start_sub_transaction("获取相册信息",0);

	web_custom_request("single_item",
				   "Url=https://{requestUrl}/service/album/get_album_themes_list.jsp?act=single_item&shop_id={attention}&goods_id={single_album}&token={userToken}",
				   "Method=Get",
				   "Mode=HTTP",
				   "LAST");

	lr_end_sub_transaction("获取相册信息",LR_AUTO);

	lr_start_sub_transaction("获取七牛token",0);

	web_custom_request("get_qiuniu_token",
				   "Url=https://{requestUrl}/service/get_qiuniu_token.jsp",
				   "Method=Get",
				   "Mode=HTTP",
				   "LAST");

	lr_end_sub_transaction("获取七牛token",LR_PASS);

	lr_end_transaction("编辑商品信息",LR_PASS);

	lr_rendezvous("并发分享");

	lr_start_transaction("成功发布商品");
	/*
	 * 	web_reg_find("Fail=NotFound",
	 * 		"Search=Body",
	 * 		"SaveCount=",
	 * 		"Text={single_album}",
	 * 		LAST);
	 */
    web_custom_request("save_theme",
                       "Url=https://{requestUrl}/service/album/album_theme_operation.jsp?act=save_theme&id=&title=060%E8%B4%A7%E5%8F%B7AOJAF326RDB+%F0%9F%87%AB%F0%9F%87%B7%E6%B3%95%E5%9B%BD%E9%AB%98%E7%BA%A7%E5%86%85%E8%A1%A3%E5%93%81%E7%89%8CAmour%EF%BC%8C%E5%8F%AF%E6%8F%92%E8%83%B8%E5%9E%AB%EF%BC%8CU%E5%9E%8B%E7%BE%8E%E8%83%8C%E8%AE%BE%E8%AE%A1%EF%BC%8C%E4%B8%AD%E7%AD%89%E5%8E%9A%E5%BA%A6%EF%BC%8C%E7%A9%BF%E4%B8%8A%E7%89%88%E5%9E%8B%E7%9B%B8%E5%BD%93%E5%A5%BD%EF%BC%8C%E8%81%9A%E6%8B%A2%E6%95%88%E6%9E%9C%E4%BD%B3%EF%BC%8C%E8%BF%9B%E5%8F%A3%E9%9D%A2%E6%96%99%EF%BC%8C%E4%B8%8D%E5%90%AB%E8%8D%A7%E5%85%89%E5%89%82%E5%92%8C%E7%94%B2%E9%86%9B%EF%BC%8C%E6%AC%A7%E7%9B%9F%E6%A0%87%E5%87%86%EF%BC%8C%E5%B0%BA%E5%AF%B8B70%EF%BC%8CC70%EF%BC%8CA75%EF%BC%8CB75%EF%BC%8CC75%EF%BC%8CA80%EF%BC%8CB80%EF%BC%8CC80%EF%BC%8C%E7%89%B9%E4%BB%B759%E5%85%83&main_imgs=%5B%22https%3A%2F%2Fxcimg.szwego.com%2F1544253871_3221608248_0%3FimageView2%2F2%2Fformat%2Fjpg%22%2C%22https%3A%2F%2Fxcimg.szwego.com%2F1544253871_1902793939_1%3FimageView2%2F2%2Fformat%2Fjpg%22%2C%22https%3A%2F%2Fxcimg.szwego.com%2F1544253871_150756200_2%3FimageView2%2F2%2Fformat%2Fjpg%22%2C%22https%3A%2F%2Fxcimg.szwego.com%2F1544253872_3166587506_3%3FimageView2%2F2%2Fformat%2Fjpg%22%2C%22https%3A%2F%2Fxcimg.szwego.com%2F1544253872_4245676544_5%3FimageView2%2F2%2Fformat%2Fjpg%22%2C%22https%3A%2F%2Fxcimg.szwego.com%2F1544582786_3721387049_0%3FimageView2%2F2%2Fformat%2Fjpg%22%2C%22https%3A%2F%2Fxcimg.szwego.com%2F1544582786_266755118_1%3FimageView2%2F2%2Fformat%2Fjpg%22%5D&tags=%5B%5D&personal=0&personalTagIds=%5B%5D&sources=%5B%5D&source_type=100&album_id={attention}&item_id={single_album}&goodsNum=&formats=%5B%5D&priceArr=%5B%5D&noteArr=%5B%5D&batch_share=&token={userToken}",
                       "Mode=HTTP",
                       "Method=POST",
                       LAST);

	lr_end_transaction("成功发布商品",LR_PASS);
	
	return 0;
}
