Action()
{
//相册动态-->发布商品，返回动态-->新增保存商品-->返回个人相册

	web_reg_save_param_ex("ParamName=shop_id",
						"LB=123456\",\"shop_id\":\"",
						"RB=\",\"watermark",
						"NotFound=warning",
						SEARCH_FILTERS,
						LAST);

	lr_start_transaction("个人相册保存商品");

	lr_start_sub_transaction("进入相册动态","个人相册保存商品");

	web_custom_request("owner",
					   "Url=https://{requestUrl}/service/album/get_album_themes_list.jsp?act=owner&shop_id=&search_value=&search_img=&start_date=&end_date=&page_index=1&client_type=ios&token={userToken}&version=2302",
					   "Method=POST",
					   "Mode=HTTP",
					   LAST);

	lr_end_sub_transaction("进入相册动态",LR_AUTO);

	web_reg_save_param_ex("ParamName=mark_code",
						  "LB=mark_code\":\"",
						  "RB=\"},\"errmsg",
						  "NotFound=warning",
						  SEARCH_FILTERS,
						  LAST);

	lr_start_sub_transaction("发布商品返回动态","个人相册保存商品");

	web_custom_request("get_markcode",
					   "Url=https://{requestUrl}/service/album/album_theme_operation.jsp?act=get_markcode&client_type=ios&platform=app&token={userToken}&version=2302",
					   "Method=GET",
					   "Mode=HTTP",
						LAST);

	web_custom_request("save_theme",
					   "Url=https://{requestUrl}/service/album/album_theme_operation.jsp?act=save_theme&mark_code={mark_code}&client_type=ios&goodsNum=ABC_{randomNum}&main_imgs=%5B%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_910270265_0%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_257527751_1%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_1237727370_2%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_1374390121_3%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_3772973971_4%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_3229263933_5%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_3646982984_6%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_76362054_7%22%0A%5D&title=Testing_{randomNum}&token={userToken}&version=2302&personal=0&platform=app&share_type=-1&source_type=0&source_url=&sources=&sub_imgs=",
					   "Method=POST",
					   "Mode=HTTP",
					   LAST);

	lr_end_sub_transaction("发布商品返回动态",LR_AUTO);

	web_custom_request("owner_1",
					   "Url=https://{requestUrl}/service/album/get_album_themes_list.jsp?act=owner&shop_id={shop_id}&search_value=&search_img=&start_date=&end_date=&page_index=1&slip_type=0&token={userToken}",
					   "Method=POST",
					   "Mode=HTTP",
					   LAST);
	
	lr_start_sub_transaction("发布商品返回个人相册","个人相册保存商品");

	web_custom_request("save_theme",
					   "Url=https://{requestUrl}/service/album/album_theme_operation.jsp?act=save_theme&album_id={shop_id}&client_type=ios&goodsNum=ABC_{randomNum}&main_imgs=%5B%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_910270265_0%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_257527751_1%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_1237727370_2%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_1374390121_3%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_3772973971_4%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_3229263933_5%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_3646982984_6%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_76362054_7%22%0A%5D&title=Testing_{randomNum}&token={userToken}&version=2302",
					   "Method=POST",
					   "Mode=HTTP",
					   LAST);

	lr_end_sub_transaction("发布商品返回个人相册",LR_AUTO);

	web_custom_request("single_album",
					   "Url=https://{requestUrl}/service/album/get_album_themes_list.jsp?act=single_album&shop_id={shop_id}&search_value=&search_img=&start_date=&end_date=&tag=[]&page_index=1&from_id=&client_type=ios&token={userToken}&version=2302",
					   "Method=POST",
				       "Mode=HTTP",
						LAST);

	lr_end_transaction("个人相册保存商品",LR_AUTO);

	return 0;
}
