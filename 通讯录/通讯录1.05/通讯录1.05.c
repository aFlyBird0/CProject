/****************************************************
 编写人：李鹤鹏
 ****************************************************/
 
 /***************************************************
 更新日志： 1.01 新增保存功能，函数封装 
 			1.02 改变存储路径 “通讯录.txt"j
			1.03 窗口美化
			1.04 修复函数封装bug 修复编辑联系人序号bug
			1.05 新增查看功能 菜单美化   
 ***************************************************/ 
 
 /************************************************
 待增加代码： 
  SetConsoleTextAttribute
       (GetStdHandle(STD_OUTPUT_HANDLE),11) ;
 **************************************************/ 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NEW    1
#define LOOK   2
#define EDIT   3
#define DELETE 4
#define FIND   5 
#define EXIT   0


struct People
{
	char phone[20];
 	char name[30];
  	char memo[100];
};

struct People peoples[100];

int read_peo   () ;       //读取文件 
int save_peo   (char filename[], int n);//保存 
int new__peo   (int n);       //新建 
int look_peo   (int n);   //查看 
int edit_peo   (int n);   //编辑 
int delete_peo (int n);   //删除
int find_peo   (int n);   //查找 
void main_menu ();        //菜单 
void color(const unsigned short corlor1);//变色 

int read_peo()
{
	char str[50];
	int i=0,n=0;
	FILE*fp;
 	if(!(fp=fopen("通讯录.txt","r")))
  	{
     	printf("error");
     	exit(0);
   	} 
   	fgets(str,50,fp);  //把第一行读掉 
   	while(!feof(fp))
    {
     	i++;
     	fscanf(fp,"%d%s%s%s", &n, peoples[i].name,
  		peoples[i].phone, peoples[i].memo);
    }
    fclose(fp);
    return n;
}
         
 
 int save_peo(char filename[], int n)
 {
 	int i;
 	FILE* fp=fopen(filename,"w");
	
 	if(fp == NULL)
  	{
     	printf("error");
     	exit(0);
   	}
   	fprintf(fp,"序号\t名字\t\t\t电话\t\t\t\t备注\t\t\n") ;
    for(i=1; i<=n; i++)
    {
		fprintf(fp,"%d\t%s\t\t\t%s\t\t\t%s\n",
		        i, peoples[i].name,peoples[i].phone, 
		        peoples[i].memo);
   	}
    fclose(fp);
    return n;
 }
 
 
 int new_peo (int n)
 {
 	n++;
	printf("请输入联系人名字:\n");
	scanf("%s",peoples[n].name);			
	printf("请输入联系人号码:\n");
	scanf("%s",peoples[n].phone);
	printf("请输入联系人备注:\n");
	scanf("%s",peoples[n].memo) ;
	save_peo("通讯录.txt",n);
 	return n;
 }
 
 int look_peo(int n)
 {
 	int i;
 	printf("序号\t名字\t\t\t电话\t\t\t\t备注\n") ;
 	for(i=1;i<=n;i++)
	{
		printf("%d\t%s\t\t\t%s\t\t\t%s\n",
 		         i, peoples[i].name,
		         peoples[i].phone,peoples[i].memo);
  		save_peo("通讯录.txt",n);
	}
 	    return n;
 }
 int edit_peo(int n)
 {
	int b, change;
	printf("请输入要编辑的联系人序号:\n");
	scanf("%d",&change);
	printf("%d\t%s\t\t\t%s\t%s\n", change, peoples[change].name, 
 			peoples[change].phone,peoples[change].memo);
	printf("请输入要修改的内容：1.名字 2.号码 3.备注 4.以上全部 其余数字取消\n");
	scanf("%d",&b);
				
	if(b==1) 
	{
		printf("请输入联系人名字:\n");
		scanf("%s",peoples[change].name);				
	}
	else if(b==2) 
	{
		printf("请输入联系人号码:\n");
		scanf("%s",peoples[change].phone);				
	}
	else if(b==3) 
	{
		printf("请输入联系人备注:\n");
		scanf("%s",peoples[change].memo);					
	}
	else if(b==4) 
	{
		printf("请输入联系人名字:\n");
		scanf("%s",peoples[change].name) ;
		printf("请输入联系人号码:\n");
		scanf("%s",peoples[change].phone);
		printf("请输入联系人备注:\n");
		scanf("%s",peoples[change].memo) ;					
	}
	save_peo("通讯录.txt",n);			
 }
 
 int delete_peo(int n)
 {
 	int i = 0, a;
	printf("请输入要删除的人的序号:\n");
	scanf("%d",&a);
	printf("%d\t%s\t\t\t%s\t\t\t\t%s\n", 
	          a, peoples[a].name, peoples[a].phone,
 				peoples[a].memo);
	printf("按1确认删除，其余取消\n");
	scanf("%d",&i);
	if(i==1)
	{
		for(a;a<n;a++)
		{
			strcpy(peoples[a].phone   , peoples[a+1].phone);
			strcpy(peoples[a].name    , peoples[a+1].name);
			strcpy(peoples[a].memo    , peoples[a+1].memo);
		}
	n--;
	save_peo("通讯录.txt",n);
	}
	return n;
 }
 
 int find_peo(int n)
 {
 	int i,a;
 	char find[40];
 	printf("1.按姓名 2.按电话 3.按备注 0.\n");
 	scanf("%d",&a);
 	switch(a)
 	{
	 	case 1:
	 	{
	 		printf("请输入姓名\n");
	 		scanf("%s",find);
	 		for(i=1;i<=n;i++)
	 		{
		 		if(strcmp(find,peoples[i].name)==0)
		 		{
		 			printf("%d\t%s\t\t\t%s\t\t\t%s\n",
 		               i, peoples[i].name,
		               peoples[i].phone,peoples[i].memo);
		 		}
		 	}
		 	break;
	 	}
	 	case 2:
	 	{
	 		printf("请输入电话\n");
	 		scanf("%s",find);
	 		for(i=1;i<=n;i++)
	 		{
		 		if(strcmp(find,peoples[i].phone)==0)
		 		{
		 			printf("%d\t%s\t\t\t%s\t\t\t%s\n",
 		               i, peoples[i].name,
		               peoples[i].phone,peoples[i].memo);
		 		}
		 	}
	 		break;
	 	}
	 	case 3:
	 	{
	 		printf("请输入备注\n");
	 		scanf("%s",find);
	 		for(i=1;i<=n;i++)
	 		{
		 		if(strcmp(find,peoples[i].memo)==0)
		 		{
		 			printf("%d\t%s\t\t\t%s\t\t\t%s\n",
 		               i, peoples[i].name,
		               peoples[i].phone,peoples[i].memo);
		 		}
		 	}
	 		break;
	 	}
	 	case 0:
	 	{
	 		break;
	 	}
	 	default:printf("无效指令!\n"); 
	 	
 	}
 	return n;
 }
 
 void main_menu()
 {
 	printf(" ---------------------------------------------------- \n");
 	printf("|                  请输入指令                        |\n");
  	printf("|    1.新建联系人  2.查看所有联系人  3.编辑联系人    |\n");
	printf("|    4.删除联系人  5.查看联系人      0.退出          |\n");
	printf("|                                                    |\n");
	printf(" ---------------------------------------------------- \n");
 } 
 
 /*void color(const unsigned short color1) 
 {
 	if(color1>=0&&color1<=15)
 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color1);
 	else
 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
 }*/
 
 
int main(int argc, char *argv[])
{ 
	 printf("\t\t  【通 讯 录】\n");
	 int n=read_peo();     //读取数据，并且获得人数 
	 
	 system("color f3");
 
     while(1)
     {
     	system("color f3");
        int a;
        main_menu();
        scanf("%d",&a);
        switch(a)
        {
            case NEW   :	n=new_peo   (n);   break;	
            case LOOK  :    n=look_peo  (n);   break;	
            case EDIT  :    n=edit_peo  (n);   break; 
			case DELETE:    n=delete_peo(n);   break;
			case FIND  :    n=find_peo  (n);   break;
	        case EXIT  :    exit(0)  ;
            default    :    printf("无效指令！\n");
        }
     }
}
