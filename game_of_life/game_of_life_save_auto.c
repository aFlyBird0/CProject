#include<stdio.h>
#include<windows.h>
#include<time.h>

#define MAXROW 85
#define MAXCOL 350
#define ALIVE 1
#define DEAD 0
#define SLEEP_TIME 50
#define PATH "result\\result_001.txt"
#define SAVE_TIME 500

int num;   //已生成图案数量

int map[MAXROW][MAXCOL], newmap[MAXROW][MAXCOL];
void init();
int neighbors(int, int);
void outputMap();
void copyMap();
void gotoxy(int x, int y);
void read_num();
void save_num();
void save_result(char *filename);

int main()
{
    srand(time(NULL));
  	int row, col;
  	read_num();
    while(1)
   {
    	int i = 0;
    	init();
    	while (1)
    	{
   			outputMap();
   		 	for (row = 0; row < MAXROW; row++)
   		 	{
  		  		for (col = 0; col < MAXCOL; col++)
   		  		{
       		 	switch (neighbors(row, col))
	       		 {
	          		case 0:
	          		case 1:
	          		case 4:
	       		    case 5:
	         	    case 6:
	       		    case 7:
	                case 8:
	            			newmap[row][col] = DEAD;
	           				 break;
	          		case 2:
	            			newmap[row][col] = map[row][col];
	           				 break;
	         	    case 3:
	            			newmap[row][col] = ALIVE;
	           				 break;
        }
      }
    }
    copyMap();
  	Sleep(SLEEP_TIME);
  	gotoxy(0,0);
  	i++;
  	if(i==SAVE_TIME)
  	{
  		num++;
  		char path[15] = PATH;
		sprintf(path+14, "%03d.txt", num); // 修改保存路径
  		save_result(path);
		break;
	}
  }


  }
  return 0;
}

void init()
{
  int row, col;
  for (row = 0; row < MAXROW; row++)
    for (col = 0; col < MAXCOL; col++)
      map[row][col] = rand()%2;  //随机生成
}

int neighbors(int row, int col)
{
  int count = 0, c, r;
  for (r = row - 1; r <= row + 1; r++)
  for (c = col - 1; c <= col + 1; c++)
  {
    if (r < 0 || r >= MAXROW || c < 0 || c >= MAXCOL)
      continue;
    if (map[r][c] == ALIVE)
      count++;
  }
  if (map[row][col] == ALIVE)
    count--;
  return count;
}

void outputMap()
{
  int row, col;
  printf("\n\nGame of life cell status\n");
  for (row = 0; row < MAXROW; row++)
  {
    printf("\n%20c", ' ');
    for (col = 0; col < MAXCOL; col++)
      if (map[row][col] == ALIVE)
        putchar('#');
      else
        putchar(' ');
  }
}

void copyMap()
{
  int row, col;
  for (row = 0; row < MAXROW; row++)
    for (col = 0; col < MAXCOL; col++)
      map[row][col] = newmap[row][col];
}

void gotoxy(int x,int y)
{
	COORD pos = {x, y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos);
}//光标移动 x列y行

void read_num()
{
	FILE *fp = fopen("number.txt","r" );
	fscanf(fp,"%d", &num);
	fclose(fp);
}

void save_num()
{
	FILE *fp = fopen("number.txt","w");
	fprintf(fp,"%d", num);
	fclose(fp);
}

void save_result(char* filename)
{
	int row, col;
	FILE *fp_save = fopen(filename, "w");
	for(row=0; row<MAXROW; row++)
	{
		for(col=0; col<MAXCOL; col++)
		{
			if(map[row][col] == ALIVE)
        		fputc('#', fp_save);
	  		else
       		    fputc(' ', fp_save);

		}
		fputc('\n',fp_save);
	}
	fclose(fp_save);
	save_num();
}
