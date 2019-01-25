Action()
{
	/*
      LoadRunner中常用的字符串操作函数有:
            strcpy(destination_string, source_string);
            strcat(string_that_gets_appended, string_that_is_appended);
            atoi(string_to_convert_to_int); //returns the integer value
            itoa(integer_to_conver_to_string, destination_string, base); // base is 10
            strcmp(string1, string2); // returns 0 if both strings are equal
	  对各函数的定义:
            strcpy( ):拷贝一个字符串到另一个字符串中.
            strcat( ):添加一个字符串到另一个字符串的末尾。
            strcmp( ):比较两个字符串，如果相等返回0。
            atoi（）：转换一个ASCII字符串为一个整型。
            itoa（）：根据给定的进制，转换一个整型数据为ASCII字符串
    */
		char MyString1[20] = "";  
 
        char MyString2[20] = "";  
 
        char MyString3[20] = "Mercury2";  
 
        char Cstring[10] = "12345";  
 
        int Cint;  

        // MyString1 is empty   
 
        lr_output_message(">>>>>>>>>> MyString1 = %s",MyString1);  
   
        // copy "Mercury1" into MyString1  
 
        strcpy(MyString1,"Mercury1");  
 
        // Now MyString1 contains "Mercury1"  
 
        lr_output_message(">>>>>>>>>> MyString1 = %s",MyString1); 

		// Copy MyString3 into MyString2   
 
        strcpy(MyString2,MyString3);  
 
        lr_output_message(">>>>>>>>>> MyString2 = %s",MyString2);  
 
        // Catenate MyString2 to MyString1  
 
        strcat(MyString1,MyString2);  
 
        lr_output_message(">>>>>>>>>> MyString1 = %s",MyString1);  
 
        // Cstring is converted to integer Cint  
		Cint= 321;

		Cint = atoi(Cstring); 

        lr_output_message(">>>>>>>>>> Cstring = %s",Cstring);  
 
        lr_output_message(">>>>>>>>>> Cint = %d",Cint);
 
        // Cint is converted to string  
		Cint = 100;  
 
        itoa(Cint,Cstring,10); 
 
        lr_output_message(">>>>>>>>>> Cstring = %s",Cstring);  

		//strcmp compare two string
		if (strcmp(lr_eval_string("Cstring"),"Cstring")==0){
			lr_output_message("正确！");
		}else{
			lr_output_message("错误！");
		}
 
	return 0;
}
