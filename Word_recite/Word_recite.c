#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define SLEEP_TIME 2000


void gotoxy(int x,int y)
{
	COORD pos = {x, y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos);
}//这个光标移动函数百度的 x列y行 

int main()
{
	char ch;
	system("color f3");
	char str[2000][100]={" "};
	char str_print[5][100]={" "};
	int i = 0,n = 0,k;
	FILE*fp;
 	if(!(fp=fopen("Word.txt","r")))
  	{
     	printf("error");
     	exit(0);
   	}
   	while(!feof(fp))
    {
     	fgets(str[n],50,fp);
     	for(i=0;str[n][i]!='\0';i++)
     		if(str[n][i]=='\n') str[n][i]=' ';//吃回车 规范格式 
     	n++;
     	//scanf("%s",str[n]);
    }
    fclose(fp);
    //printf("read done\n");
    
    srand((unsigned)time(NULL));
    int judge = 0;
    printf("输入 1 顺序播放，其余数字随机播放\n");
	scanf("%d",&judge);
	int m = -1;
    while(1)
    {
    	if(judge!=1) m = rand()%(n+1)+1;
    	else m ++;
    	for(i=0;str[m][i]!='\0';i++)
    	{
	    	str_print[0][i] = str[m][i];
	    }
	    str_print[0][i] = '\0';
	    printf("\n\n");
    	for(k=0;k<5;k++) 
		{
			//gotoxy(15,2*k+1);
			printf("\t\t%s\n\n",str_print[k]);
		}
		if(kbhit()) system("pause") ;
		for(k=4; k>0; k--) 
		{
			int j;
			for(j=0;str[k][j]!='\0';j++)
			{
				str_print[k][j] = str_print[k-1][j];
			} 
		}	
		Sleep(SLEEP_TIME);
		system("cls");//清屏 
    }
    return 0;
    
}
