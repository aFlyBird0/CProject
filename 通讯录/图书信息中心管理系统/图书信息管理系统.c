/****************************************************
 编写人：李鹤鹏
 ****************************************************/

 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NEW    1
#define LOOK   2
#define EDIT   3
#define DELETE 4
#define FIND   5 
#define EXIT   0
#define PACH "List.txt" 


struct Book 
{
	char login[30];     //登录号 
 	char name[50];      //书名 
 	char author[30];    //作者 
 	char kind[30];      //分类号 
 	char publisher[50]; //出版单位
	char time[30];      //出版时间 
  	char price[15];     //价格 
};

struct Book books[1000];

int read_book   () ;       //读取文件 
int save_book   (char filename[], int n);//保存 
int new__book   (int n);   //新建 
int look_book   (int n);   //查看所有 
int edit_book   (int n);   //编辑 
int delete_book (int n);   //删除
int find_book   (int n);   //查找
void main_menu  ();         //菜单 


int main(int argc, char *argv[])
{ 
	 printf("\t\t【图书馆信息管理系统】\n");
	 int n = read_book();  //读取数据，并且获得书本数量 
	 
	 system("color f3");  //更改字体颜色 
 
     while(1)
     {
     	system("color f3");
        int a;
        main_menu();
        scanf("%d",&a);
        switch(a)
        {
            case NEW   :	n=new_book   (n);   break;	
            case LOOK  :    n=look_book  (n);   break;	
            case EDIT  :    n=edit_book  (n);   break; 
			case DELETE:    n=delete_book(n);   break;
			case FIND  :    n=find_book  (n);   break;
	        case EXIT  :    save_book(PACH,n); exit(0) ;
            default    :    printf("无效指令！\n");
        }
     }
}

int read_book()
{
	char str[50];
	int i=0,n=0;
	FILE*fp;
 	if(!(fp=fopen(PACH,"r")))
  	{
     	printf("error");
     	exit(0);
   	} 
   	fgets(str,100,fp);  //把第一行读掉 
   	while(!feof(fp))
    {
     	i++;
     	fscanf(fp,"%d%s%s%s%s%s%s%s", &n, books[i].name,
  		books[i].login, books[i].name,books[i].author,
		books[i].kind, books[i].publisher, books[i].time,
		books[i].price );
    }
    fclose(fp);
    return n;
}
         
 
 int save_book(char filename[], int n)
 {
 	int i;
 	FILE* fp=fopen(filename,"w");
	
 	if(fp == NULL)
  	{
     	printf("error");
     	exit(0);
   	}
   	fprintf(fp,"序号\t登录号\t\t书名\t\t作者\t\t分类号\t\t") ;
   	fprintf(fp,"出版单位\t\t出版时间\t\t价格\t\t\n") ;
   	
    for(i=1; i<=n; i++)
    {
		fprintf(fp,"%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",
	 	i, books[i].login, books[i].name,
	 	books[i].author,books[i].kind, books[i].publisher,
	 	books[i].time,books[i].price);
   	}
    fclose(fp);
    return n;
 }
 
 
 int new_book (int n)
 {
 	n++;
	printf("请输入登录号:\n");
	scanf("%s",books[n].login);			
	printf("请输入书名:\n");
	scanf("%s",books[n].name);
	printf("请输入作者名:\n");
	scanf("%s",books[n].author) ;
	printf("请输入分类号:\n");
	scanf("%s",books[n].kind);
	printf("请输入出版单位:\n");
	scanf("%s",books[n].publisher);
	printf("请输入出版时间:\n");
	scanf("%s",books[n].time);
	printf("请输入价格:\n");
	scanf("%s",books[n].price);
	save_book(PACH,n);
 	return n;
 }
 
 int look_book(int n)
 {
 	int i;
 	printf("序号\t登录号\t\t书名\t\t作者\t\t分类号\t\t") ;
 	printf("出版单位\t\t出版时间\t\t价格\t\t\n") ;
 	for(i=1;i<=n;i++)
	{
		printf("%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
		i, books[i].login,books[i].name, books[i].author,
		books[i].kind,books[i].publisher,
	 	books[i].time,	books[i].price);
  		save_book(PACH,n);
	}
 	    return n;
 }
 int edit_book(int n)
 {
	int b, change;
	printf("请输入要编辑的图书序号:\n");
	scanf("%d",&change);
	printf("%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
			change,	books[change].login, books[change].name,
 			books[change].author,books[change].kind,
 			books[change].publisher, books[change].time,
			books[change].price);
	printf("请输入要修改的内容：1.登录号 2.书名 3.作者 4.分类号 5.出版单位\n");
	printf("6.出版时间 7.价格 8.以上全部 其余按键取消\n");
	scanf("%d",&b);
	switch(b)
	{
		case 1:
		{
			printf("请输入欲修改的图书登录号:\n");
			scanf("%s",books[change].login);
			break;
		}
		case 2:
		{
			printf("请输入欲修改的图书名:\n");
			scanf("%s",books[change].name);
			break;
		}
		case 3:
		{
			printf("请输入欲修改的图书作者名:\n");
			scanf("%s",books[change].author);
			break;
		}
		case 4:
		{
			printf("请输入欲修改的图书分类号:\n");
			scanf("%s",books[change].kind);
			break;
		}
		case 5:
		{
			printf("请输入欲修改的图书出版单位:\n");
			scanf("%s",books[change].publisher);
			break;
		}
		case 6:
		{
			printf("请输入欲修改的图书出版时间:\n");
			scanf("%s",books[change].time);
			break;
		}
		case 7:
		{
			printf("请输入欲修改的图书价格:\n");
			scanf("%s",&books[change].price);
			break;
		}
		case 8:
		{
			printf("请输入欲修改的图书登录号:\n");
			scanf("%s",books[change].login);
			printf("请输入欲修改的图书名:\n");
			scanf("%s",books[change].name);
			printf("请输入欲修改的图书作者名:\n");
			scanf("%s",books[change].author);
			printf("请输入欲修改的图书分类号:\n");
			scanf("%s",books[change].kind);
			printf("请输入欲修改的图书出版单位:\n");
			scanf("%s",books[change].publisher);
			printf("请输入欲修改的图书出版时间:\n");
			scanf("%s",books[change].time);
			printf("请输入欲修改的图书价格:\n");
			scanf("%s",books[change].price);
			break;
		}
	} 
	save_book(PACH,n);			
 }
 
 int delete_book(int n)
 {
 	int i, a;
	printf("请输入要删除图书信息的序号:\n");
	scanf("%d",&i);
	printf("%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
		i, books[i].login, books[i].name,
		books[i].author,books[i].kind, books[i].publisher,
	 	books[i].time,	books[i].price);
	printf("按1确认删除，其余取消\n");
	scanf("%d",&a);
	if(a==1)
	{
		for(i=0;i<n;i++)
		{
			strcpy(books[i].login    , books[i+1].login);
			strcpy(books[i].name     , books[i+1].name);
			strcpy(books[i].author   , books[i+1].author);
			strcpy(books[i].kind     , books[i+1].kind);
			strcpy(books[i].publisher, books[i+1].publisher);
			strcpy(books[i].time     , books[i+1].time);
			strcpy(books[i].price    , books[i+1].price);
		}
	n--;
	save_book(PACH,n);
	}
	return n;
 }
 
 int find_book(int n)
 {
 	int i,a;
 	char find[40];
 	printf("1.按书名 2.按作者 其余取消\n");
 	scanf("%d",&a);
 	switch(a)
 	{
	 	case 1:
	 	{
	 		int judge = 0;
	 		printf("请输入预查询书籍名\n");
	 		scanf("%s",find);
	 		for(i=1;i<=n;i++)
	 		{
		 		if(strcmp(find,books[i].name)==0)
		 		{
		 			printf("%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
		i, books[i].name,books[i].login, books[i].name,
		books[i].author,books[i].kind, books[i].publisher,
	 	books[i].time,	books[i].price); 
	 				judge++;  //判断是否有书籍 
		 		}
		 	}
		 	if(!judge) puts("搜索无结果！");
		 	break;
	 	}
	 	case 2:
	 	{
	 		int judge = 0;
	 		printf("请输入预查询图书作者名\n");
	 		scanf("%s",find);
	 		for(i=1;i<=n;i++)
	 		{
		 		if(strcmp(find,books[i].author)==0)
		 		{
		 			printf("%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
		i, books[i].name,books[i].login, books[i].name,
		books[i].author,books[i].kind, books[i].publisher,
	 	books[i].time,	books[i].price);
		               judge++;
		 		}
		 	}
		 	if(!judge) puts("搜索无结果！");
	 		break;
	 	}	 	
 	}
 	return n;
 }
 
 void main_menu()
 {
 	printf(" -------------------------------------------------------- \n");
 	printf("|                  请输入指令                            |\n");
  	printf("|    1.添加图书信息  2.查看所有图书    3.编辑图书信息    |\n");
	printf("|    4.删除图书      5.查找图书        0.退出并保存      |\n");
	printf("|                                                        |\n");
	printf(" -------------------------------------------------------- \n");
 } 

