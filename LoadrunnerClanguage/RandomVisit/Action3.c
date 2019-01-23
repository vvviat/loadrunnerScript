Action3()
{
	lr_start_transaction("sina");
	web_url("web_url",
		"URL=https://www.sina.com.cn",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Mode=HTML",
		LAST);
lr_start_transaction("sina",LR_PASS);
	return 0;
}
