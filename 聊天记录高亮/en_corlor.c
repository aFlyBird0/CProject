#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include <string.h>

void SetColor(unsigned short ForeColor,unsigned short BackGroundColor)
{
    HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,(ForeColor%16)|(BackGroundColor%16*16));
}

void get_year(char *year)
{
	int i;
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	char *ch;
	ch = asctime (timeinfo);
	while(*ch!='\n')
		ch++;
	year[4] = '\0';
	ch--;
	for(i=3; i>=0; i--)
	{
		year[i] = *ch;
		ch--;
	}
	//puts(year);
}
int main()
{
	system("color f0");
	FILE *fp;
	char *judge;
	fp = fopen("Chat.txt", "r");
	int x, y, i, j;
	char str[200], year[5];
	get_year(year);
	while(!feof(fp))
	{
		fgets(str, 200, fp);
		judge = strstr(str, year);
		if(NULL != judge)
			SetColor(13,15);	
		else
			SetColor(0,15);
		printf("%s",str);
	}
    fclose(fp);
	system("pause");    

}
