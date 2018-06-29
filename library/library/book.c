#include "book.h"
#include "user.h"
#include "borrow.h"
#include "code.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define BOOK_PATH   "Book.txt" 
#define USER_PATH   "User.txt"
#define BORROW_PATH "Borrow.txt" 

Book books[1000];
Borrow_record borrow_records[500];

int book_n = 0;

void read_book(const char filename[])
{
	char content[100];
	int i = 0;
	FILE *fp_book;
 	if(!(fp_book=fopen(BOOK_PATH,"r")))
  	{
     	printf("error to open book");
     	exit(0);
   	} 
   	fgets(content,100,fp_book);  //把第一行读掉 
   	while(!feof(fp_book))
    {
     	i++;
     	fscanf(fp_book,"%d%s%s%s%s%s%s%s%d",
 				 		&book_n, 
						books[i].id, 
						books[i].name,
						books[i].author,
						books[i].kind, 
						books[i].publisher, 
						books[i].time,
						books[i].price,
						&books[i].state );
    }
    fclose(fp_book); 
}

 void save_book(const char filename[])
 {
 	int i;
 	FILE* fp_book=fopen(filename,"w");
	
 	if(fp_book == NULL)
  	{
     	printf("error");
     	exit(0);
   	}
   	freopen(BOOK_PATH, "w", stdout);  //输出重定向至文件 
   	
   	printf("序号\t登录号\t\t书名\t\t作者\t\t分类号\t\t") ;
   	printf("出版单位\t\t出版时间\t\t价格\t\是否可借\n") ;
   	
    for(i=1; i<=book_n; i++)
    {
    	printf("%d\t", i);
		print_book(books + i);
   	}
   	freopen("CON", "w", stdout);  //输出重定向至控制台 
    fclose(fp_book);
 }

 void print_book(const Book *book)
 {
 	printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%d\n", 
				book->id,
				book->name, 
				book->author,
				book->kind,
				book->publisher,
	 			book->time,	
			 	book->price,
			 	book->state);
 }
 
 void cpy_book(int i)
 {
 	while(i<book_n)
	{
		strcpy(books[i].id       , books[i+1].id);
		strcpy(books[i].name     , books[i+1].name);
		strcpy(books[i].author   , books[i+1].author);
		strcpy(books[i].kind     , books[i+1].kind);
		strcpy(books[i].publisher, books[i+1].publisher);
		strcpy(books[i].time     , books[i+1].time);
		strcpy(books[i].price    , books[i+1].price);
		books[i].state = books[i+1].state;
		i++;
	} 
 }
 
 void add_book()
 {
 	book_n++;            //书的总数量加 1 
	printf("请输入登录号:\n");
	scanf("%s",books[book_n].id);			
	printf("请输入书名:\n");
	scanf("%s",books[book_n].name);
	printf("请输入作者名:\n");
	scanf("%s",books[book_n].author) ;
	printf("请输入分类号:\n");
	scanf("%s",books[book_n].kind);
	printf("请输入出版单位:\n");
	scanf("%s",books[book_n].publisher);
	printf("请输入出版时间:\n");
	scanf("%s",books[book_n].time);
	printf("请输入价格:\n");
	scanf("%s",books[book_n].price);
	books[book_n].state = 1; 
	save_book(BOOK_PATH);
 }
 
 void look_book()
 {
 	int i;
 	printf("序号\t登录号\t\t书名\t\t作者\t\t分类号\t\t") ;
 	printf("出版单位\t\t出版时间\t\t价格\t\t是否可借\n") ;
 	for(i=1; i<=book_n; i++)
	{
		printf("%d\t", i); 
		print_book(books+i);
	}
 }
 void edit_book()
 {
	int instruction, change;
	printf("请输入要编辑的图书序号:\n");
	scanf("%d",&change);
	print_book(books+change);
	printf("请输入要修改的内容：1.登录号 2.书名 3.作者 4.分类号 5.出版单位\n");
	printf("6.出版时间 7.价格 8.以上全部 其余按键取消\n");
	scanf("%d",&instruction);
	switch(instruction)
	{
		case 1:
		{
			printf("请输入欲修改的图书登录号:\n");
			scanf("%s", books[change].id);
			break;
		}
		case 2:
		{
			printf("请输入欲修改的图书名:\n");
			scanf("%s", books[change].name);
			break;
		}
		case 3:
		{
			printf("请输入欲修改的图书作者名:\n");
			scanf("%s", books[change].author);
			break;
		}
		case 4:
		{
			printf("请输入欲修改的图书分类号:\n");
			scanf("%s", books[change].kind);
			break;
		}
		case 5:
		{
			printf("请输入欲修改的图书出版单位:\n");
			scanf("%s", books[change].publisher);
			break;
		}
		case 6:
		{
			printf("请输入欲修改的图书出版时间:\n");
			scanf("%s", books[change].time);
			break;
		}
		case 7:
		{
			printf("请输入欲修改的图书价格:\n");
			scanf("%s", books[change].price);
			break;
		}
		case 8:
		{
			printf("请输入欲修改的图书登录号:\n");
			scanf("%s", books[change].id);
			printf("请输入欲修改的图书名:\n");
			scanf("%s", books[change].name);
			printf("请输入欲修改的图书作者名:\n");
			scanf("%s", books[change].author);
			printf("请输入欲修改的图书分类号:\n");
			scanf("%s", books[change].kind);
			printf("请输入欲修改的图书出版单位:\n");
			scanf("%s", books[change].publisher);
			printf("请输入欲修改的图书出版时间:\n");
			scanf("%s", books[change].time);
			printf("请输入欲修改的图书价格:\n");
			scanf("%s", books[change].price);
			break;
		}
	} 
	save_book(BOOK_PATH);			
 }
 
 
 void delete_book()
 {
 	int i, instruction;
 	for(i=1; i<=book_n; i++)
 	{
 		printf("%d\t", i);
 	 	print_book(books+i);
 	}
	 	
	printf("请输入要删除图书信息的序号:\n");
	scanf("%d", &i);
	if(i>=1 && i<=book_n) 
	{
		if(books[i].state == 1) //没人借 
		{
			print_book(books+i);
			printf("按1确认删除，其余取消\n");
			scanf("%d", &instruction);
			if(instruction == 1)
			{
				cpy_book(i);         //书本前移，起到删除功能 
				book_n--;
				save_book(BOOK_PATH);
			}
		}
		else
			printf("该书已被借，不可删除！\n");
	}
	else 
		printf("序号有误！\n"); 
	
 }
 
 void find_book_window()
 {
 	int instruction;
 	printf("1.按书名 2.按作者 其余取消并返回上一级\n");
 	scanf("%d", &instruction);
 	if(instruction ==1)
 	{
	 	char name[30];
 		scanf("%s",name);
 		Book *book = find_book_by_name(name);
 		if(book != NULL)
	 		print_book(book);
 		else 
 			printf("查询无结果！");
 	}
 	else if(instruction ==2)
 	{
	 	char author[30];
 		scanf("%s",author);
 		Book *book  = find_book_by_author(author);
 		if(book != NULL)
	 		print_book(book);
 		else 
 			printf("查询无结果！");
 	}
 }
 
  Book *find_book_by_name(const char name[])
 {
 	int i;
 	for(i=1; i<=book_n; i++)
	{
		if(strcmp(name,books[i].name)==0)
		{ 
			return books+i;
 		}
 	}
 	return NULL;
 }
 
  Book *find_book_by_author(const char author[])
 {
 	int i;
 	for(i=1; i<=book_n; i++)
	{
		if(strcmp(author,books[i].author)==0)
		{ 
			return books+i;
 		}
 	}
 	return NULL;
 }
 
 void main_menu()
 {
 	printf(" -------------------------------------------------------- \n");
 	printf("|                  请输入指令                            |\n");
  	printf("|    1.添加图书信息  2.查看所有图书    3.编辑图书信息    |\n");
	printf("|    4.删除图书      5.查找图书        6.借书            |\n");
	printf("|    7.还书          0.退出并保存                        |\n");
	printf(" -------------------------------------------------------- \n");
 } 
 
 
