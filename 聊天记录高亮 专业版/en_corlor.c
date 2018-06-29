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
	int color[13] = {1,2,3,4,5,6,8,9,10,11,12,13,14	};
	int i, j, n = 0;
	system("color f0");
	FILE *fp, *fp_name;
	char *judge, name[50][100];
	fp_name = fopen("Info.txt", "r");
	while(!feof(fp_name))
	{
		fscanf(fp_name, "%s", name+n);
		n++;
	}
	fclose(fp_name);
	
	fp = fopen("Chat.txt", "r");
	char str[200];
	//get_year(year);
	while(!feof(fp))
	{
		SetColor(0,15);
		fgets(str, 200, fp);
		for(i=0; i<n; i++)
		{
			judge = strstr(str, name+i);
			if(NULL != judge)
			{
				SetColor(color[i],15);
				break;
			}
		}
		printf("%s",str);
	}
    fclose(fp);
	system("pause");    

}
