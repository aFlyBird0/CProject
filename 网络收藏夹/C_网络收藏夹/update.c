#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#define PATH  "Urls.txt"
#define PATH2 "../Urls.txt"

/*****************************************
编写人：李鹤鹏 
功能  ：合并两个收藏夹 
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

char* delete_huiche(char *str)
{
	char  str2[300];
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
	 	fgets(urls[i].url, 		100, fp);
	 	fgets(urls[i].details,  300, fp);
	 	strcpy(urls[i].caption , delete_huiche(urls[i].caption));
	 	strcpy(urls[i].url , delete_huiche(urls[i].url));
	 	strcpy(urls[i].details , delete_huiche(urls[i].details));
		  	
    }
    fclose(fp); 
    url_n = i - 1; //程序最后面永远有个空行，所以减去一 
    //printf("%d", url_n);
}

void read_url2(const char filename[])
{
	int i;
	FILE *fp;
 	if(!(fp=fopen(filename,"r")))
  	{
     	printf("不存在需要被合并的收藏夹txt文件!\n");
     	Sleep(1000);
     	exit(0);
   	} 
   	while(!feof(fp))
    {
     	url_n++;
     	fgets(urls[url_n].caption, 50, fp);
	 	fgets(urls[url_n].url, 		100, fp);
	 	fgets(urls[url_n].details,  300, fp);
	 	strcpy(urls[url_n].caption , delete_huiche(urls[url_n].caption));
	 	strcpy(urls[url_n].url , delete_huiche(urls[url_n].url));
	 	strcpy(urls[url_n].details , delete_huiche(urls[url_n].details));
	 	for(i=1; i<url_n; i++)
	 	{
	 		if(!strcmp(urls[i].url, urls[url_n].url))
 			{
			 	url_n--;
			 	break;
			 }
	 	}
		  	
    }
    fclose(fp); 
    url_n--;
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


void print_all_url()
{
	int i;
	printf("序号\t简单描述\t\t\t详细信息\n");
	for(i=1; i<=url_n; i++)
		printf("%d\t%s\t\t\t%s\n", 
				i, urls[i].caption, urls[i].details);
}


int main()
{
	read_url(PATH);
	read_url2(PATH2);
	save_url(PATH);
	printf("收藏夹合并成功!\n");
	printf("程序将在1秒后自动关闭\n");
	Sleep(1000); 
	return 0;
}
