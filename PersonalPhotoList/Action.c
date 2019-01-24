Action()
{
//相册动态-->个人相册-->新增新增商品-->返回个人相册
	merc_timer_handle_t timer;
	double wasteTime;

	web_reg_save_param_ex("ParamName=shop_id",
						"LB=shop_id\":\"",
						"RB=\",\"watermark\":true",
						"NotFound=warning",
						SEARCH_FILTERS,
						LAST);


	lr_start_transaction("进入相册动态");

	web_add_header("Accept-Encoding","chunked");


    web_custom_request("owner",
                       "Url={requestUrl}/service/album/get_album_themes_list.jsp?act=owner&shop_id=&search_value=&search_img=&start_date=&end_date=&page_index=1&client_type=ios&token={userToken}&version=2302&",
                       "Method=GET",
                       "Mode=HTTP",
                        LAST);


	lr_end_transaction("进入相册动态",LR_PASS);


    lr_start_transaction("进入个人相册");

	timer=lr_start_timer();

	web_custom_request("single_album",
					   "Url={requestUrl}/service/album/get_album_themes_list.jsp?act=single_album&shop_id={shop_id}&search_value=&search_img=&start_date=&end_date=&tag=&page_index=1&from_id=&client_type=ios&token={userToken}&version=2302",
					   "Method=POST",
					   "EncType=Transfer-Encoding",
				       "Mode=HTTP",
						LAST);

    wasteTime=lr_end_timer(timer);

    lr_wasted_time(wasteTime*1000);
/*
    web_custom_request("get_tags_except",
                       "Url={requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tags_except&has_video=0&shop_id={shop_id}",
                       "Method=GET",
                       "Mode=HTTP",
                       LAST);

	web_reg_save_param_ex("ParamName=mark_code",
						  "LB=mark_code\":\"",
						  "RB=\"},\"errmsg",
						  "NotFound=warning",
						  SEARCH_FILTERS,
						  LAST);

	web_custom_request("get_tags",
					   "Url={requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tags&goods_id=&token={userToken}&version=2302",
					   "Method=GET",
					   "Mode=HTTP",
						LAST);

    web_custom_request("get_tags_except_1",
                       "Url={requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tags_except&has_video=0&shop_id={shop_id}&token={userToken}",
                       "Method=GET",
                       "Mode=HTTP",
                       LAST);


*/
	lr_end_transaction("进入个人相册",LR_AUTO);
	lr_start_transaction("发布新增商品");

	web_custom_request("save_theme",
					   "Url={requestUrl}/service/album/album_theme_operation.jsp?act=save_theme&mark_code=&client_type=ios&goodsNum=ABC_{randomNum}&main_imgs=%5B%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_910270265_0%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_257527751_1%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_1237727370_2%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_1374390121_3%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_3772973971_4%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_3229263933_5%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_3646982984_6%22%2C%0A%20%20%22https%3A%5C/%5C/xcimg.szwego.com%5C/1547209778_76362054_7%22%0A%5D&title=Testing_{randomNum}&token={userToken}&version=2302&personal=0&platform=app&share_type=-1&source_type=0&source_url=&sources=&sub_imgs=",
					   "Method=POST",
					   "Mode=HTTP",
					   LAST);

	lr_end_transaction("发布新增商品",LR_AUTO);

    lr_start_transaction("返回个人相册");

    web_custom_request("get_tags_except_2",
                       "Url={requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tags_except&has_video=0&shop_id={shop_id}&token={userToken}",
                       "Method=GET",
                       "Mode=HTTP",
                       LAST);

	timer=lr_start_timer();

	web_custom_request("single_album_1",
					   "Url={requestUrl}/service/album/get_album_themes_list.jsp?act=single_album&shop_id={shop_id}&search_value=&search_img=&start_date=&end_date=&tag=&page_index=1&from_id=&client_type=ios&token={userToken}&version=2302",
					   "Method=GET",
					   "EncType=Transfer-Encoding",
				       "Mode=HTTP",
						LAST);

    wasteTime=lr_end_timer(timer);

    lr_wasted_time(wasteTime*1000);

	lr_end_transaction("返回个人相册",LR_AUTO);

	return 0;
}
