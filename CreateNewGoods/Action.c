Action()
{

//https://www.szwego.com/service/album/album_theme_operation.jsp?act=save_theme
/*
id: 
title: Testing_No_12345789
main_imgs: ["https://xcimg.szwego.com/o_1d1utldkg1th4rmmvbrgei11lo1h.jpg","https://xcimg.szwego.com/o_1d1utldkg1d8q6r1kil1dm13nf1i.jpg","https://xcimg.szwego.com/o_1d1utldkg1jvcll13s5sjh1cli1j.jpg","https://xcimg.szwego.com/o_1d1utldkgmvkro71ita1rp913601k.jpg","https://xcimg.szwego.com/o_1d1utldkgvcdqqmo024vv1vn31l.jpg","https://xcimg.szwego.com/o_1d1utldkg1idf1nqu1epqfql1fsi1m.jpg","https://xcimg.szwego.com/o_1d1utldkg1gd018fu17ca1eps1rmk1n.jpg","https://xcimg.szwego.com/o_1d1utldkg1l47uim1qajjg61mrm1o.jpg","https://xcimg.szwego.com/o_1d1utldkg19fa1rlpur19df1jfr1p.jpg"]
tags: [{"tagId":2838481,"tagName":"美丽热线"}]
groups: []
personal: 0
personalTagIds: []
sources: []
goodsNum: A_No_123456
formats: [{"formatName":"ABC_123456789"}]
priceArr: [{"type":"price","label":"批发价","value":"123","permission":0,"tagIds":[],"priceType":"3","id":""},{"type":"price","label":"拿货价","value":"123","permission":1,"tagIds":[],"priceType":1,"id":""}]
noteArr: [{"type":"note","label":"","value":"公开","permission":0,"tagIds":[],"id":""}]
*/
	web_custom_request("CreateNewGoods",
					   "URL={requestUrl}/service/album/album_theme_operation.jsp?act=save_theme&token={userToken}",
					   "Method=POST",
					   "Mode=HTTP",
					   "Body=id=&title=Testing_No_{randomNum}&main_imgs={imageUrl}&tags=%5B%7B%22tagId%22%3A{randomNum}%2C%22tagName%22%3A%22%E7%BE%8E%E4%B8%BD%E7%83%AD%E7%BA%BF%22%7D%5D&groups=%5B%5D&personal=0&personalTagIds=%5B%5D&sources=%5B%5D&goodsNum=A_No_{randomNum}&formats=%5B%7B%22formatName%22%3A%22ABC_{randomNum}%22%7D%5D&priceArr=%5B%7B%22type%22%3A%22price%22%2C%22label%22%3A%22%E6%89%B9%E5%8F%91%E4%BB%B7%22%2C%22value%22%3A%22{randomNum}%22%2C%22permission%22%3A0%2C%22tagIds%22%3A%5B%5D%2C%22priceType%22%3A%223%22%2C%22id%22%3A%22%22%7D%2C%7B%22type%22%3A%22price%22%2C%22label%22%3A%22%E6%8B%BF%E8%B4%A7%E4%BB%B7%22%2C%22value%22%3A%22{randomNum}%22%2C%22permission%22%3A1%2C%22tagIds%22%3A%5B%5D%2C%22priceType%22%3A1%2C%22id%22%3A%22%22%7D%5D&noteArr=%5B%7B%22type%22%3A%22note%22%2C%22label%22%3A%22%22%2C%22value%22%3A%22%E5%85%AC%E5%BC%80%22%2C%22permission%22%3A0%2C%22tagIds%22%3A%5B%5D%2C%22id%22%3A%22%22%7D%5D",
					   LAST);

	
	return 0;
}
