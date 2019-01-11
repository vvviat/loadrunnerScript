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
        "Url=http://s1.bdstatic.com/r/www/img/i-1.0.0.png", ENDITEM, 
        "Url=http://s1.bdstatic.com/r/www/img/bg-1.0.0.gif", ENDITEM, 
        "Url=/favicon.ico", "Referer=", ENDITEM, 
        "Url=http://suggestion.baidu.com/su?wd=&cb=window.bdsug.sugPreRequest&sid=1440_2031_1945_1788&t=1362056239875", ENDITEM, 
        "Url=http://suggestion.baidu.com/su?wd=%E8%99%AB%E5%B8%88&p=3&cb=window.bdsug.sug&sid=1440_2031_1945_1788&t=1362056247256", ENDITEM, 
        "Url=http://suggestion.baidu.com/su?wd=%E8%99%AB%E5%B8%88%20&p=3&cb=window.bdsug.sug&sid=1440_2031_1945_1788&t=1362056247969", ENDITEM, 
        "Url=http://suggestion.baidu.com/su?wd=%E8%99%AB%E5%B8%88%20%E5%8D%9A%E5%AE%A2%E5%9B%AD&p=3&cb=window.bdsug.sug&sid=1440_2031_1945_1788&t=1362056251016", ENDITEM, 
        LAST);

     lr_end_transaction("百度首页",LR_AUTO);    //设置事务结束

       return 0;
}
