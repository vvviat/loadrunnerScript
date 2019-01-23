Action()
{
   //验证IP欺骗代码
	  char * ip ;
			ip = lr_get_vuser_ip();
		if (ip)
			lr_output_message("当前虚拟用户使用的IP为： %s", ip);
		else
			lr_output_message("[enable IP spoofing ]选项没有被启用！");


       lr_start_transaction("百度首页");    //设置事务开始

       web_url("www.baidu.com", 
				"URL=http://www.baidu.com/", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=", 
				"Snapshot=t3.inf", 
				"Mode=HTML", 
				EXTRARES, 
				LAST);

       lr_end_transaction("百度首页",LR_AUTO);    //设置事务结束

       return 0;
}
