#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define COLUM 25
#define SLEEP_TIME 500

/*
发现行和列设置一样的话判断是否漏打很简单
*/ 


void gotoxy(int x,int y)
{
	COORD pos = {x, y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos);
}//这个光标移动函数百度的 x列y行 


int main()
{
	system("color f3");
	int k, colum[COLUM+1]={0};
	char str[COLUM+2]="                         "; 
	//预留一个用来检测是否下落到最低点消失 
	int score_true = 0, score_false = 0;
	char ch;
	srand((unsigned)time(NULL));
	while(1)
	{	
		//for(int i=0; i<10;i++)
		//{
			str[0] = (char)(rand()%26) + 'A';
			//每次随机第一个字母 
			colum[0] = rand()%COLUM + 1 ;
			//每次随机第一个出现列数 
			Sleep(SLEEP_TIME);                //停顿 
			for(k=COLUM; k>0; k--)
			//依次后移每一个字母，列数，包括预留位 
			{
				str[k] = str[k-1];
				colum[k] = colum[k-1];   
			}
			if(str[COLUM]!=' ') score_false++;
			//如果预留位不是' '说明最后一个下落字母没打 
			
			for(k=0; k<COLUM;k++ )
			//一次最多按COLUM个键，也就是最多一次按完所有字母 
			{
				if(kbhit())    //检测是否有按键按下，如果有返回真 
				{
					int k;
					int judge = 0;
					char ch = getch();
					if((ch)=='\x1B') system("pause");
					//ESC暂停 
					for(k=15; k>0; k--)//最先判断最底端字母 
					{
						if(ch==str[k])
						{
							judge = 1;
							str[k] = ' ';//点击之后字母变' ' 
							break;
						}
					}
					if(judge) score_true ++ ;
					else score_false ++ ;
				}
			}	
			system("cls");
			printf(" True:%3d\t\tFalse:%3d\n",score_true,score_false);
			for(k=0;k<COLUM;k++)  //一次输出二十五行(行列相同) 
			{
				gotoxy(colum[k],k+1);
				/*其实本来列数应该减 1，因为第一列 
				  坐标是 0 ，但是空出第一列更美观*/ 
				printf("%c\n",str[k]);
			}
			printf("---------------Bottom---------------------\n");				
		//}
	}	
	return 0;
}
