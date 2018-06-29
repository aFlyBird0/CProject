#ifndef _ZZZ_USER_H___
#define _ZZZ_USER_H___

typedef struct User
{
	char id[30];        //用户id 
	char password[30];  //用户密码 
}User;

extern User users[500];

extern int user_n;
extern char user_name[30];   //当前用户名称 

void read_user(const char filename[]);  //读取用户记录
void save_user(const char filename[]);  //保存用户记录
int is_vaild_user(const char* user_id); //是否存在该用户
void login_or_regist_window();          //登录，注册窗口  
int login();                            //登录 
void regist();                          //注册  

#endif //_ZZZ_USER_H___

