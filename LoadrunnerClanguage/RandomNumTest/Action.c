Action()
{
	int randomNum_id;

	randomNum_id=rand();

	lr_output_message("产生的随机数：%d",randomNum_id);

	lr_output_message("引用参数：%d",lr_eval_string("{randomNum_id}"));

	return 0;
}
