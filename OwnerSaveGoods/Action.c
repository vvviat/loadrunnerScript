Action()
{
//相册动态-->发布商品-->返回动态

	web_reg_save_param_ex("ParamName=shop_id",
						"LB=shop_id\":\"",
						"RB=\",\"watermark\":true",
						"NotFound=warning",
						SEARCH_FILTERS,
						LAST);
	lr_think_time(3);

	lr_start_transaction("进入相册动态");

	web_custom_request("owner",
					   "Url={requestUrl}/service/album/get_album_themes_list.jsp?act=owner&shop_id=&search_value=&search_img=&start_date=&end_date=&page_index=1&client_type=ios&token={userToken}&version=2302",
					   "Method=POST",
					   "Mode=HTTP",
					   LAST);

	lr_end_transaction("进入相册动态",LR_AUTO);

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

	lr_think_time(3);

	lr_start_transaction("新增商品成功");

	lr_start_sub_transaction("发布商品","新增商品成功");

	web_custom_request("save_theme",
					   "Url={requestUrl}/service/album/album_theme_operation.jsp?act=save_theme&tagId=&client_type=ios&goodsNum=ABC_{randomNum}&main_imgs={images}&title=Testing_{randomNum}&token={userToken}&version=2302&personal=0&platform=app&share_type=-1&source_type=0",
					   "Method=POST",
					   "Mode=HTTP",
					   LAST);

	lr_end_sub_transaction("发布商品",LR_AUTO);

	lr_start_sub_transaction("返回动态","新增商品成功");

	web_custom_request("owner_1",
					   "Url={requestUrl}/service/album/get_album_themes_list.jsp?act=owner&shop_id={shop_id}&search_value=&search_img=&start_date=&end_date=&page_index=1&slip_type=0&token={userToken}",
					   "Method=POST",
					   "Mode=HTTP",
					   LAST);

	lr_end_sub_transaction("返回动态",LR_AUTO);

	lr_end_transaction("新增商品成功",LR_AUTO);

	return 0;
	
}