Action1()
{
lr_start_transaction("hao123");
	web_url("web_url",
		"URL=https://www.hao123.com",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Mode=HTML",
		LAST);
lr_end_transaction("hao123",LR_PASS);

	return 0;
}
