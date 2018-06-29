#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define MAX_MAP_ROW 16
#define MAX_MAP_COLUM 40
#define SLEEP_TIME 1000
#define UP    'w'
#define DOWN  's'
#define LEFT  'a'
#define RIGHT 'd'
 
/*

#define UP    (char)(0x4b)
#define DOWN  (char)(0x48)
#define LEFT  (char)(0x4d)
#define RIGHT (char)(0x50)

*/ 


/*****************
程序名称：贪食蛇 
制作人：  李鹤鹏 
版本号:   1.0 
******************/

/************************************
更新日志： 1.0 基础功能

************************************/ 

 

enum types{blank, body, food, wall_row, wall_colum};
enum types type;

char map[MAX_MAP_ROW][MAX_MAP_COLUM];
int snake_x[MAX_MAP_ROW*MAX_MAP_COLUM];
int snake_y[MAX_MAP_ROW*MAX_MAP_COLUM];
int length;
int food_x, food_y;
int sleep_time = SLEEP_TIME;
char direction; 
char cursor[6] = " *o$$";

void load_map();  //加载地图 
void gotoxy(int x,int y);//输出坐标移动
void print_snake(); //输出蛇 
void move();        //移动 
int game_over();    //判断是否撞墙，撞身体 
void eat();         //关于食物的一系列操作 
 
int main()
{
	system("color f3");
	int i, j = 1;
	srand(time(NULL));
	length = 1;
	snake_x[0] = rand()%(MAX_MAP_COLUM-2)+1;
			//随机生成x，并且不在地图边缘上 
 	snake_y[0] = rand()%(MAX_MAP_ROW-2)+1;
	food_x  = rand()%(MAX_MAP_COLUM-2)+1;
	food_y  = rand()%(MAX_MAP_ROW-2)+1;
	i = rand()%4 + 1;            //初始化方向
	if(i==1) 	  direction = UP;
	else if(i==2) direction = DOWN;
	else if(i==3) direction = LEFT;
	else if(i==4) direction = RIGHT;
	
	load_map();
	
 	while(1)
 	{
	 	print_snake();	
 		for(i=0; i<20; i++)
 		{
		 	if(kbhit())
		 	{
		 		direction = getch();
		 		if(direction==UP||direction==DOWN||direction==LEFT||direction==RIGHT)  //高位 
		 		{
		 			j = 0;
		 			move();
		 			if(game_over()) //如果输了 
 					{
		 				gotoxy(MAX_MAP_COLUM/2-4,MAX_MAP_ROW/2);
		 				puts("game over!");//居中输出game over
		 				break;
	 				}
	 				eat();
	 				print_snake(); 
		 		}
 				 
 		 	} 
		 }
 		if(j) move();
 		j = 1;
 		print_snake();
 		if(game_over()) //如果输了 
 		{
 			gotoxy(MAX_MAP_COLUM/2-4,MAX_MAP_ROW/2);
		 	puts("game over!");   //居中输出game over
			system("pause"); 
		 	break;
	 	}
	 	eat();
	 	Sleep(sleep_time);  //停顿 
	 }
	 return 0;
	  
}

void load_map()
{
	int i, j;
	for(i=0; i<MAX_MAP_ROW; i++)
	{
		for(j=0; j<MAX_MAP_COLUM; j++)
		{
			map[i][j] = cursor[(type=blank)];
		}
	}
	for(i=1; i<MAX_MAP_COLUM-1; i++)
		map[0][i] = cursor[(type=wall_row)];
	for(i=1; i<MAX_MAP_COLUM-1; i++)
		map[MAX_MAP_ROW-1][i] = cursor[(type=wall_row)];
	for(i=1; i<MAX_MAP_ROW-1; i++)
		map[i][0] = cursor[(type=wall_colum)];
	for(i=1; i<MAX_MAP_ROW-1; i++)
		map[i][MAX_MAP_COLUM-1] = cursor[(type=wall_colum)];
		
	for(i=0; i<MAX_MAP_ROW; i++)
	{
		for(j=0; j<MAX_MAP_COLUM; j++)
		{
			printf("%c",map[i][j]);
		}
		putchar('\n');
	}
}

void print_snake()
{
	int i;
	for(i=0; i<length; i++)
	{
		gotoxy(snake_x[i], snake_y[i]);
		printf("\b%c",cursor[(type=body)]); 
				//退格再输出 相当于把地图的空格改成身体 
	}
	gotoxy(snake_x[i], snake_y[i]);
	printf("\b%c",cursor[(type=blank)]);
	gotoxy(food_x, food_y);
	printf("\b%c",cursor[(type=food)]);
	gotoxy(0,MAX_MAP_ROW);
}
void gotoxy(int x,int y)
{
	COORD pos = {x, y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos);
}//这个光标移动函数百度的 x列y行

void eat()
{
	int i;
	if(snake_x[0]==food_x && snake_y[0]==food_y)
	{
	 	length ++;
	 	gotoxy(food_x, food_y);
		printf("\b%c",cursor[(type=body)]);
		gotoxy(0,MAX_MAP_ROW);
		food_x  = rand()%(MAX_MAP_COLUM-2)+1;
		food_y  = rand()%(MAX_MAP_ROW-2)+1;
		sleep_time = (int)(sleep_time*0.95);
	}
}

void move()
{
	int i;
	gotoxy(snake_x[length-1], snake_y[length-1]); 
	printf("\b%c",cursor[(type=blank)]);//擦去尾巴 
	for(i=length-1; i>0; i--)
	{
		snake_x[i] = snake_x[i-1]; //蛇向前 
		snake_y[i] = snake_y[i-1]; 
	}
	switch(direction)
	{
		case UP:
		{
			snake_y[0] --; 
			break;
		}
		case DOWN:
		{
			snake_y[0] ++; 
			break;
		}
		case LEFT:
		{
			snake_x[0] --; 
			break;
		}
		case RIGHT:
		{
			snake_x[0] ++; 
			break;
		}
	}
	print_snake();
}

int game_over()
{
	int i, judge = 0;     //如果judge为 1 就代表gameover 
	for(i=1; i<length; i++) //去除头 
	{
		if(snake_x[0]==snake_x[i] && snake_y[0]==snake_y[i])
							//判断头是否接触身体 
		{
			judge = 1;
			break;
		}
	}
	if(snake_x[0]==0||snake_x[0]==MAX_MAP_COLUM-1||snake_y[0]==0||snake_y[0]==MAX_MAP_ROW-1)
	                       //判断头是否撞地图 
		judge = 1;
		
	return judge;
}
