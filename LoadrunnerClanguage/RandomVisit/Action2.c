Action2()
{
lr_start_transaction("baidu");
	web_url("web_url",
		"URL=https://www.baidu.com",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Mode=HTML",
		LAST);
lr_start_transaction("baidu",LR_PASS);
	return 0;
}
