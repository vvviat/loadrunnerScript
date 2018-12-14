searchimg()
{	
/*
    int randomnumber;
    randomnumber=rand()%3+1;
	lr_save_int(randomnumber,"temp");
//	lr_output_message(lr_eval_string("{temp}"));


    switch (randomnumber) {
    case 1:{

		lr_rendezvous("testPerformance");
        //搜索
		lr_start_transaction("搜索txt");
        web_custom_request("owner",
                       "Url=https://{requestUrl}/service/album/get_album_themes_list.jsp?act=owner&search_value=%E6%9C%8D%E8%A3%85&search_img=&page_index=1&token={userToken}",
                       "Method=POST",
                       "Mode=HTTP",
                       LAST);
	    lr_end_transaction("搜索txt", LR_PASS);
		break;
    }

    case 2:{

		//搜索
		lr_start_transaction("搜索img");
		web_custom_request("owner",
					   "Url=https://{requestUrl}/service/album/get_album_themes_list.jsp?act=owner&search_value=%E9%9E%8B%E5%AD%90&search_img=https://xcimg.szwego.com/o_1cue75mck5kj1c641el050o1sb7h.jpg&start_date=&end_date=&page_index=1&slip_type=1&token={userToken}",
					   "Method=POST",
					   "Mode=HTTP",
					   LAST);
		lr_end_transaction("搜索img",LR_AUTO);
		break;
    }

	case 3:{
		lr_output_message("本次结果为%d,没有请求需要执行！",randomnumber);
	}

    }
*/
	return 0;
}
