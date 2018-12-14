Action()
{
//加载首页，搜索txt
	web_reg_save_param_ex(
	"ParamName=owner",
	"LB=shop_id\":\"",
	"RB=\",\"subimgsSrc",
	"NotFound=warning",
	SEARCH_FILTERS,
	LAST);	

	lr_start_transaction("加载app首页");

    web_custom_request("owner1",
                       "Url=https://{requestUrl}/service/album/get_album_themes_list.jsp?act=owner&search_value=&search_img=&start_date=&end_date=&page_index=1&token={userToken}",
                       "Method=GET",
                       "Mode=HTTP",
                       LAST);

	lr_end_transaction("加载app首页",LR_PASS);

	lr_start_transaction("首页搜索txt");

    web_custom_request("owner2",
                       "Url=https://{requestUrl}/service/album/get_album_themes_list.jsp?act=owner&shop_id={owner}&search_value=testing&search_img=&start_date=&end_date=&page_index=1&token={userToken}",
                       "Method=GET",
                       "Mode=HTTP",
                       LAST);

	lr_end_transaction("首页搜索txt",LR_PASS);

	return 0;
}
