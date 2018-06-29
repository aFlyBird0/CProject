#ifndef _ZZZ_BORROW_H___
#define _ZZZ_BORROW_H___

 typedef struct Borrow_record
 {
 	int number ;          //编号 
 	char book_name[30]; 
 	char book_id[30]; 
 	char user_id[30];		
 }Borrow_record;
 
 extern Borrow_record borrow_records[500];
 
 extern int borrow_n; 

void read_borrow_record() ;		//读取借阅记录 
void save_borrow_record(char filename[]); //保存借阅记录
Borrow_record *find_book_by_user_id(char user_id[]); 
								//查找每个人所借的书 
 
void borrow_book(const char user_id[]);	//借书 
void return_book(const char user_id[]); //还书 

extern int book_n;
extern int user_n;
extern int borrow_n; 
extern char user_name[30];   //当前用户名称 

#endif //_ZZZ_BORROW_H___

