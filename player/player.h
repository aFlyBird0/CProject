#ifndef _ZZZ_USER_H___
#define _ZZZ_USER_H___

typedef struct User
{
	int num;            //用户编号 
	char id[30];        //用户id 
	char password[30];  //用户密码 
}User;

extern User users[500];

extern char user_name[30];              //当前用户名称 
extern int user_n;                      //当前总共用户数量 

void read_user(const char filename[]);	//读取用户记录
void save_user(const char filename[]);	//保存用户记录
User* get_user(const char* user_id);
					//通过用户名获取整个用户结构体数据 
int is_exist_user(const char* user_id); //是否存在该用户
void login_or_regist_window();          //登录与注册窗口 
int login();                     		//登录后台代码
void regist();                   		//注册 
void delete_user();						//删除用户 
void change_password();					//更改密码 
char* encode(char *prim);      		    //加密
char* decode(char *code);               //解密 
void create_if_not_exit();
//创建存储具体用户信息的txt，以用户的名字作为文件名 

#endif //_ZZZ_USER_H___
