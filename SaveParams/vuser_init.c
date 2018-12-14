char *filename="D:/paramters.log";
long file_stream;

vuser_init()
{
	if((file_stream=fopen(filename,"a+"))==NULL){
		lr_error_message("That's log cant open£¡%s",filename);
		return -1;
	}
	fprintf(file_stream,"shop_id,goods_id\n");
	return 0;
}
