OwnerSearch()
{

    	lr_rendezvous("testPerformance");
        //µ¥´¿Ê×Ò³²¢·¢ËÑË÷
		lr_start_transaction("ËÑË÷txt");

        web_custom_request("owner",
                       "Url=https://{requestUrl}/service/album/get_album_themes_list.jsp?act=owner&search_value=%E6%9C%8D%E8%A3%85&search_img=&page_index=1&token={userToken}",
                       "Method=POST",
                       "Mode=HTTP",
                       LAST);

	    lr_end_transaction("ËÑË÷txt", LR_PASS);

	return 0;
}
