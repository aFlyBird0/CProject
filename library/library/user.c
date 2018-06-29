#include "user.h"
#include "borrow.h"
#include "book.h"
#include "code.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define USER_PATH   "User.txt"

int book_n ;
int user_n = 0;
char user_name[30];   //当前用户名称 

User users[500];
Book books[1000];

void read_user(const char filename[])
{
	char content[100];
	int i = 0;
	FILE *fp_user;
 	if(!(fp_user=fopen(USER_PATH,"r")))
  	{
     	printf("error to open user");
     	exit(0);
   	} 
   	fgets(content,100,fp_user);  //把第一行读掉 
   	while(!feof(fp_user))
    {
     	i++;
     	fscanf(fp_user,"%d%s%s", &user_n, 
								 users[i].id, 
								 users[i].password );
     	strcpy(users[i].password, decode(users[i].password)); //解密 
    }
    fclose(fp_user); 
}

 
 void save_user(const char filename[])
 {
 	int i;
 	FILE* fp_user = fopen(filename,"w");
 	if(fp_user == NULL)
  	{
     	printf("error");
     	exit(0);
   	}
   	fprintf(fp_user,"序号\t用户名(id)\t\t密码\t\t\n") ;
   	
    for(i=1; i<=user_n; i++)
    {
		fprintf(fp_user,"%d\t%s\t\t%s\t\t\n",
	 					i, 
	 					users[i].id, 
	 					encode(users[i].password));
   	}
    fclose(fp_user);
 }
 
 int is_vaild_user(const char* user_id)
 {
 	int i;
  	for(i=1; i<=user_n; i++)
  	{
		if(strcmp(user_id, users[i].id)==0)
			return 1;  	
  	}
  	return 0;
 }
 
 User* get_user(const char* user_id)
 {
	int i;
  	for(i=1; i<=user_n; i++)
  	{
		if(strcmp(user_id, users[i].id)==0)
			return users+i;  	
  	}
  	return NULL;
 }
 
 
 void login_or_regist_window()
 {
 	read_user(USER_PATH);
	 while(1)
	 {
	 	int instruction;
	 	printf("1.登录 2.注册 其余退出并保存\n");
	 	scanf("%d", &instruction);
	 	if(instruction == 1)
	 	{
	 		if(login())   //是否登录成功
		 	{
 				printf("登录成功!\n");
 				Sleep(500);  //延迟半秒
 				system("cls");//清屏 
 				return;
 			} 
 			else 
			{
				printf("登录失败，自动返回上级菜单\n");
 				Sleep(500);  //延迟半秒
 				system("cls");//清屏 
			}			
	 	}
	 	else if(instruction == 2)
	 	{
 			regist();
 			Sleep(500);  //延迟半秒
 			system("cls");//清屏 
 		} 
 		else
 			exit(0);	 
 	 }
 }
 
 int login(char filename[])
 {
 	int i, login_state = 0;
 	char user_id[30], password[30]; 
 	User *user = NULL;
 	printf("请输入你的id(用户名):\n");
 	scanf("%s", user_id);
 	
 	if(is_vaild_user(user_id)!=1)
 	{
		printf("该用户不存在\n"); 	
 	}
 	else
 	{
 		user = get_user(user_id);
 		for(i=0; i<3; i++)    //三次机会输入密码 
 		{
		 	printf("请输入你的密码:\n");
	 		scanf("%s", password);
	 		if(strcmp(password, user->password)==0)
	 		{
		 		login_state = 1; 
		 		strcpy(user_name, user_id);//保存当前用户名字 
		 		return login_state;
		 	}	
	 	}
		 printf("连续三次密码输入错误!\n");	
 	}
 	return login_state;    //返回是否登录成功 
 }
 
 void regist()
 {
 	printf("请输入欲注册的用户名(id):\n");
 	char user_id[30], password1[30], password2[30];
 	scanf("%s", user_id);
 	User *user = NULL;
 	if(is_vaild_user(user_id)==1)
 	{
	 	printf("该用户已存在！\n");
	 	return;
 	}
 	printf("请输入密码:\n");
 	scanf("%s",password1);
 	printf("请再次输入密码:\n");
 	scanf("%s",password2);
 	if(strcmp(password1,password2)==0)
 	{
	 	user_n++;
	 	strcpy(users[user_n].id, user_id); 
	 	strcpy(users[user_n].password, password1);
	 	printf("注册成功！\n");
	 	strcpy(user_name, user_id);
	 	save_user(USER_PATH);
 	}		
	else
 		printf("两次密码不一致，注册失败！\n");
	Sleep(500);
	system("cls"); 
 }
