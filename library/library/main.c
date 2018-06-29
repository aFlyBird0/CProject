/****************************************************
                图书馆信息管理系统 
         
功能概述：1.增删找改存    	      编写人：李鹤鹏 
          2.菜单功能，窗口美化 			  李腾达 
          3.用户登录与借阅功能 			  李叶飞 
           
 ****************************************************/
 
 /**************************************************
 
 部分代码说明：1.所有信息都通过txt保存，
		    	 并且用户密码经过加密处理。
	           2.运用多文件，因临近期末
			     所以部分函数放在了同一个文件中 
			   3.宏定义增加了代码的可读性 
 ***************************************************/ 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "book.h"
#include "user.h"
#include "borrow.h"
#include "code.h" 

#define NEW    1
#define LOOK   2
#define EDIT   3
#define DELETE 4
#define FIND   5 
#define BORROW 6
#define RETURN 7 
#define EXIT   0

#define BOOK_PATH   "Book.txt" 
#define USER_PATH   "User.txt"
#define BORROW_PATH "Borrow.txt" 


int main(int argc, char *argv[])
{ 
	 system("color f3");  //更改字体颜色
	 
	 login_or_regist_window();
	 
	 printf("\t\t【图书馆信息管理系统】\n");
	 read_book(BOOK_PATH);    //读取数据，并且获得书本数量
     while(1)
     {
        int instruction;     //输入菜单指令 
        main_menu();
        scanf("%d", &instruction);
        switch(instruction)
        {
            case NEW   :	add_book()        ;   break;	
            case LOOK  :    look_book()       ;   break;	
            case EDIT  :    edit_book()       ;   break; 
			case DELETE:    delete_book()     ;   break;
			case FIND  :    find_book_window();   break;
	        case EXIT  :    save_book(BOOK_PATH); exit(0) ;
	        case BORROW:	borrow_book(user_name);   break;
	        case RETURN:    return_book(user_name);   break;
            default    :   	printf("无效指令！\n");
        }
     }
}
