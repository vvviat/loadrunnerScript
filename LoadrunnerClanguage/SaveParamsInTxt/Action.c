Action()
{

	int i=1;
	char shop_index[64];
	char goods_index[64];

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

	while(i<=32){
	
	sprintf(shop_index, "{shop_id_list_%d}", i);
    lr_message("shop_id %d:%s",i,lr_eval_string(shop_index));

	sprintf(goods_index, "{goods_id_list_%d}", i);
	lr_message("goods_id %d:%s",i,lr_eval_string(goods_index));
		
	fprintf(file_stream,"%s,%s\n",lr_eval_string(shop_index),lr_eval_string(goods_index));
	
	i++;

	}

	lr_end_transaction("加载app首页",LR_PASS);

	return 0;
}
