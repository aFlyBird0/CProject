#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#define PATH "Urls.txt"

/*****************************************
编写人：李鹤鹏 
功能  ：保存网址并打开 
版本 ：1.0 
****************************************/

typedef struct Url
{
	char caption[50];   //简短说明 
	char url[100];		//网址 
	char details[300];	//详细说明 
}Url;

Url urls[500];

int url_n = 0;

void read_url(const char filename[]); //读取信息 
char* delete_huiche(char *str);		//删除字符串回车 
void help_menu();
void save_url(const char filename[]);
void add_url();		//添加网址
void open_url(int num);    //打开网址 
void edit_url(int num);	//修改网址 
void move_url(int num1, int num2);//移动网址 
void delete_url(int num); //删除网址 
void print_all_url();   //打印所有网址 


int main()
{
	system("color f3"); 
	read_url(PATH);
	//printf("%s", urls[2].caption);
	char instruction;
	while(1)
	{
		int num = 0;
		print_all_url();
		puts("\n请输入指令(不要用中文输入法),按h查看帮助: ");
		instruction = getch();
		//putchar(instruction);
		switch(instruction)
		{
			case 'A':
			case 'a':	add_url();	break;
			case 'E':
			case 'e':
			{
				scanf("%d", &num);
				edit_url(num);
				break;
			}
			case 'O':
			case 'o':
			{
				scanf("%d", &num);
				open_url(num);
				break;
			}
			case 'D':
			case 'd':
			{
				scanf("%d", &num);
				delete_url(num); 
				break;
			}
			case 'M':
			case 'm':
			{
				int num1, num2;
				scanf("%d%d", &num1, &num2);
				move_url(num1, num2);
				break;
			}
			case 'Q':
			case 'q': exit(0);	 break;
			case 'H':
			case 'h': help_menu(); Sleep(5000);	 break;
			default : puts("无效指令!"); break;
		}
		Sleep(1000);
		system("cls");
	}
	//system("explorer http://www.baidu.com"); 
	return 0;
}

void read_url(const char filename[])
{
	int i = 0, j;
	FILE *fp;
 	if(!(fp=fopen(filename,"r")))
  	{
     	printf("failed to open!\n");
     	exit(0);
   	} 
   	while(!feof(fp))
    {
     	i++;
     	fgets(urls[i].caption, 50, fp);
     	//printf("111%s\n", urls[i].caption);
	 	fgets(urls[i].url, 		100, fp);
	 	//printf("111%s\n", urls[i].url);
	 	fgets(urls[i].details,  300, fp);
	 	//printf("111%s\n", urls[i].details);
	 	strcpy(urls[i].caption , delete_huiche(urls[i].caption));
	 	strcpy(urls[i].url , delete_huiche(urls[i].url));
	 	//printf("222%s\n", urls[i].url);
	 	strcpy(urls[i].details , delete_huiche(urls[i].details));
	 	//printf("222%s\n", urls[i].details);
		  	
    }
    fclose(fp); 
    url_n = i - 1; //程序最后面永远有个空行，所以减去一 
}

void add_url()
 {
 	url_n++;            //网址的总数量加 1 
	printf("请输入网址简单描述:\n");
	gets(urls[url_n].caption);			
	printf("请输入完整网址(http开头):\n");
	gets(urls[url_n].url);
	printf("请输入网址详细信息:\n");
	gets(urls[url_n].details) ;
	printf("网址添加成功!\n");
	save_url(PATH);
 }
 
 void open_url(int num)
 {
 	char Original[] = "explorer ";
 	if(!(num>=1 && num<=url_n))
	{
		printf("不存在该序号网址!\n");
	 	return;
	}
	char str[60];
	strcpy(str, Original);
	strcat(str, urls[num].url);
	system(str); // 打开网址
 }
 
 void edit_url(int num)
 {
 		getchar();
 		if(!(num>=1 && num<=url_n))
 		{
	 		printf("不存在该序号网址!\n");
	 		return;
		 }
		printf("简单描述：%s\n", urls[num].caption);
		printf("具体网址：%s\n", urls[num].url);
		printf("详细信息：%s\n", urls[num].details);
		char caption_temp[50], url_temp[100], details_temp[300];
		puts("你要将简单描述改为(s跳过):");
		gets(caption_temp);
		if(strcmp(caption_temp, "s"))
			strcpy(urls[num].caption, caption_temp);
		puts("你要将具体网址改为(s跳过):");
		gets(url_temp);
		if(strcmp(url_temp, "s"))
			strcpy(urls[num].url, url_temp);
		puts("你要将详细信息改为(s跳过):");
		gets(details_temp);
		if(strcmp(details_temp, "s"))
			strcpy(urls[num].details, details_temp);
		puts("网址修改成功!");
		save_url(PATH);
 }
 
 void move_url(int num1, int num2)
 {
 	if((!(num1>=1 && num1<=url_n))||(!(num2>=1 && num2<=url_n)))
 	{
	 	printf("不存在该序号网址!\n");
	 	return;
	 }
 	Url url_temp = urls[num1];
	int i;
 	if(num1>=num2)
 	{
 		for(i=num1; i>= num2+1; i--)
	 		urls[i] = urls[i-1];
	 }
	 else
	 {
 		for(i=num1; i<=num2-1; i++)
 			urls[i] = urls[i+1];	
 	}
 	urls[num2] = url_temp;
 	printf("移动成功!\n");
 	save_url(PATH);
 }
 
 void delete_url(int num)
 {
 	if(!(num>=1 && num<=url_n))
	{
	 	printf("不存在该序号网址!\n");
	 	return;
	 }
 	printf("简单描述：%s\n", urls[num].caption);
	printf("具体网址：%s\n", urls[num].url);
	printf("详细信息：%s\n", urls[num].details);
	puts("按y确认删除, n取消");
	getchar();
	char instruction = getch();
	int i;
	if('y' == instruction)
	{
		for(i=num; i<url_n; i++)
			urls[i] = urls[i+1];
		url_n--;
		puts("删除成功!");
	}
	else if('n' == instruction)
		puts("取消删除");
	else
		puts("无效指令!");
	save_url(PATH);
 }

void save_url(const char filename[])
 {
 	int i;
 	FILE* fp=fopen(filename,"w");
	
 	if(fp == NULL)
  	{
     	printf("error\n");
     	exit(0);
   	} 
   	
    for(i=1; i<=url_n; i++)
    {
    	fprintf(fp, "%s\n", urls[i].caption);
    	fprintf(fp, "%s\n", urls[i].url);
    	fprintf(fp, "%s\n", urls[i].details);
   	}
    fclose(fp);
 }

char* delete_huiche(char *str)
{
	char  str2[50];
	char *p1 = str, *p2 = str2;
	while(*p1 != '\0')
	{
		if(*p1 != '\n')
			{
				*p2 = *p1;
				p2 ++;
			}
		p1 ++;
	}
	*p2 = '\0';
	return str2;
}

void print_all_url()
{
	int i;
	printf("序号\t简单描述\t\t\t详细信息\n");
	for(i=1; i<=url_n; i++)
		printf("%d\t%s\t\t\t%s\n", 
				i, urls[i].caption, urls[i].details);
}

void help_menu()
 {
 	printf(" ------------------------------------------------ \n");
 	printf("|             帮助                               |\n");
  	printf("|    a              添加(add)   网址             |\n");
	printf("|    o 数字         打开(open)  网址(空格可省)   |\n");
	printf("|    e 数字         编辑(edit)  网址(空格可省)   |\n");
	printf("|    d 数字         删除(delete)网址(空格可省)   |\n");
	printf("|    m 数字1 数字2  移动第数字1个网址至第数字2个 |\n");
	printf("|    q              退出(quit)并保存             |\n");
	printf(" ------------------------------------------------ \n");
 } 
