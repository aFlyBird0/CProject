#ifndef _ZZZ_BOOK_H___
#define _ZZZ_BOOK_H___

typedef struct Book 
{
	char id[30];        //登录号 
 	char name[50];      //书名 
 	char author[30];    //作者 
 	char kind[30];      //分类号 
 	char publisher[50]; //出版单位
	char time[30];      //出版时间 
  	char price[15];     //价格
	int state;          //是否可借 
}Book;

extern Book books[1000];

void read_book(const char filename[]);   //读取书籍记录 
void save_book(const char filename[]);   //保存书籍记录 
void add_book();                         //新建 
void look_book();                		 //查看所有 
void edit_book();               		 //编辑书籍 
void delete_book();            			 //删除书籍 
void find_book_window();   //查找书籍（窗口以及全部功能） 
Book *find_book_by_name(const char name[]); //按书名查找 
Book *find_book_by_author(const char author[]);//按作者查找 
void main_menu();               		 //菜单 
void print_book(const Book* book); 
									     //一次打印单个图书 
void cpy_book(int i);          			 //书籍前移（删除书籍时用） 

extern int book_n;             			 //目前书籍数量 

#endif //_ZZZ_BOOK_H___
