Action()
{

	lr_rendezvous("concurrentSave");

	lr_start_transaction("分享商品");
	//单纯并发分享接口，tps
	web_custom_request("save_theme",
				   "Url=https://{requestUrl}/service/album/album_theme_operation.jsp?act=save_theme&id=&title=this's+a+testing{randomNum}&main_imgs=%5B%22https%3A%2F%2Fxcimg.szwego.com%2Fo_1cue7aedn1s7u1v7beq91h9315umv.jpg%22%2C%22https%3A%2F%2Fxcimg.szwego.com%2Fo_1cue7alfi1dv71mus1npo45r1hel15.png%22%5D&tags=%5B%5D&personal=0&personalTagIds=%5B%5D&sources=%5B%5D&goodsNum=&formats=%5B%5D&priceArr=%5B%5D&noteArr=%5B%5D&token={userToken}",
				   "Method=POST",
				   "Mode=HTTP",
				   LAST);

	lr_end_transaction("分享商品",LR_PASS);

	return 0;
}
