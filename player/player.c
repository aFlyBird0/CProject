#include "player.h"
#include <stdio.h>
#include <windows.h>

#define USER_PATH "user.txt" 

/*******************************************
ʹ��ʱ��Ҫ��exeͬ��Ŀ¼���洴��һ����USER_PATH
��Ӧ���ַ�����Ĭ�ϡ�user.txt")ͬ����txt�ļ�

ע��user.txt��������������û����ֺ�������ļ�
���������ĳ���û�����.txt���������ÿ���û�������Ϣ���ļ� 
���ļ����Ѿ�д���Զ����ɹ��� 
*******************************************/

User users[500];

int user_n;
char user_name[30];

void read_user(const char filename[])
{
	char content[100];
	int i = 0;
	FILE *fp_user; 
 	if(!(fp_user=fopen(USER_PATH,"r")))
  	{
     	printf("error to open user");
     	exit(0);
   	} 
   	fgets(content,100,fp_user);  //�ѵ�һ�ж��� 
   	while(!feof(fp_user))
    {
     	i++;
     	fscanf(fp_user,"%d%s%s", &users[i].num, 
								 users[i].id, 
								 users[i].password );
     	strcpy(users[i].password, decode(users[i].password)); //���� 
    }
    user_n = i - 1;
    //printf("%d ", user_n);
    fclose(fp_user); 
    
}

 
 void save_user(const char filename[])
 {
 	int i;
 	FILE* fp_user = fopen(filename,"w");
 	//printf("%d ", user_n);
 	if(fp_user == NULL)
  	{
     	printf("error");
     	exit(0);
   	}
   	fprintf(fp_user,"���\t�û���(id)\t����\n") ;
   	
    for(i=1; i<=user_n; i++)
    {
		fprintf(fp_user,"%d\t%s\t\t%s\t\t\n",
	 					users[i].num, 
	 					users[i].id, 
	 					encode(users[i].password));
   	}
    fclose(fp_user);
 }
 
 int is_exist_user(const char* user_id)
 {
 	int i;
  	for(i=1; i<=user_n; i++)
  	{
		if(strcmp(user_id, users[i].id)==0)
			return 1;  	
  	}
  	return 0;
 }
 
void login_or_regist_window()
 {
 	read_user(USER_PATH);
	 while(1)
	 {
	 	int instruction;
	 	printf("1.��¼ 2.ע�� �����˳�������\n");
	 	scanf("%d", &instruction);
	 	if(instruction == 1)
	 	{
	 		if(login())   //�Ƿ��¼�ɹ�
		 	{
 				printf("��¼�ɹ�!\n");
 				Sleep(500);  //�ӳٰ���
 				system("cls");//���� 
 				return;
 			} 
 			else 
			{
				printf("��¼ʧ�ܣ��Զ������ϼ��˵�\n");
 				Sleep(500);  //�ӳٰ���
 				system("cls");//���� 
			}			
	 	}
	 	else if(instruction == 2)
	 	{
 			regist();
 		} 
 		else
 			exit(0);	 
 	 }
 }
 
 int login(const char filename[])
 {
 	int i, login_state = 0;
 	char user_id[30], password[30]; 
 	User *user = NULL;
 	printf("���������id(�û���):\n");
 	scanf("%s", user_id);
 	
 	if(is_exist_user(user_id)!=1)
 	{
		printf("���û�������\n"); 	
 	}
 	else
 	{
 		user = get_user(user_id);
 		printf("%s\n", user->password); 
 		for(i=0; i<3; i++)    //���λ����������� 
 		{
		 	printf("�������������:\n");
	 		scanf("%s", password);
	 		if(strcmp(password, user->password)==0)
	 		{
		 		login_state = 1; 
		 		strcpy(user_name, user_id);//���浱ǰ�û����� 
		 		return login_state;
		 	}	
	 	}
		 printf("�������������������!\n");	
 	}
 	return login_state;    //�����Ƿ��¼�ɹ� 
 }
 
 void regist()
 {
 	printf("��������ע����û���(id):\n");
 	char user_id[30], password1[30], password2[30];
 	scanf("%s", user_id);
 	User *user = NULL;
 	if(is_exist_user(user_id)==1)
 	{
	 	printf("���û��Ѵ��ڣ�\n");
	 	return ;
 	}
 	printf("����������:\n");
 	scanf("%s",password1);
 	printf("���ٴ���������:\n");
 	scanf("%s",password2);
 	if(strcmp(password1,password2)==0)
 	{
	 	user_n++;
	 	users[user_n].num = user_n;
	 	strcpy(users[user_n].id, user_id); 
	 	strcpy(users[user_n].password, password1);
	 	printf("ע��ɹ���\n");
	 	strcpy(user_name, user_id);
	 	save_user(USER_PATH);
 	}		
	else
 		printf("�������벻һ�£�ע��ʧ�ܣ�\n");
 }
 
 void delete_user()
 {
 	 int i, instruction;
     char temp_password[50];
 	 printf("��ǰ�û�����%s\n", user_name);
 	 User *user = get_user(user_name);
 	 printf("�������û�����:\n");
 	 scanf("%s", temp_password);
 	 if(strcmp(temp_password, user->password) == 0)
 	 {
 	 	printf("��1ȷ��ɾ��������ȡ��\n");
 	 	scanf("%d", &instruction);
 	 	if(instruction == 1)
 	 	{
	 	 	for(i=user->num; i<user_n-1; i++)
	 	 	{
		 	 	strcpy((users+i)->id,(users+i+1)->id);
		 	 	strcpy((users+i)->password,(users+i+1)->password);
	 	    }
		 	 printf("  �û�����:\n");
		 	 user_n--;
		 	 save_user(USER_PATH);
	 	 }
 	 	
 	 }
 	 else
 	 	printf("�������,ɾ���û���Ϣʧ�ܣ�\n");
 	 
 }
 
 void change_password()
 {
	 int i, instruction;
     char temp_password[50], password1[50], password2[50];
 	 printf("��ǰ�û�����%s\n", user_name);
 	 User *user = get_user(user_name);
 	 printf("�������û�����:\n");
 	 scanf("%s", temp_password);
 	 if(strcmp(temp_password, user->password) == 0)
 	 {
 	 	printf("������֤�ɹ������������޸�Ϊ������:\n");
	 	scanf("%s",password1);
	 	printf("���ٴ���������:\n");
	 	scanf("%s",password2);
	 	if(strcmp(password1,password2)==0)
	 	{
		 	strcpy(user->password, password1);
		 	printf("�����޸ĳɹ���\n");
		 	save_user(USER_PATH);
	 	}		
 	 	
 	 }
 	 else
 	 	printf("�������,�������ʧ�ܣ�\n");
 }
 
 User* get_user(const char* user_id)
 {
	int i;
  	for(i=1; i<=user_n; i++)
  	{
		if(strcmp(user_id, users[i].id)==0)
			return users+i;  	
  	}
  	return NULL;
 }
 
 char* encode(char *prim) 
{
    int i,n,len;
    char code[100];
    char temp_char,trans_char;
    int temp_num,trans_num;
    len = strlen(prim);

    for(i = 0;i < len;i++)
    {
        temp_char = prim[i]; 
        if (temp_char <= 'z' && temp_char >= 'a')
            temp_num = temp_char - 'a' + 1;
        else if (temp_char <= 'Z' && temp_char >= 'A')
            temp_num = temp_char - 'A' + 27;

        trans_num = temp_num*3 % 52;

        if (trans_num > 26 && trans_num <= 52)
            trans_char = 'A' + trans_num - 27;
        else if (trans_num > 0 && trans_num <= 26)
            trans_char = 'a' + trans_num - 1;
            
        if (temp_char >= '0' && temp_char <= '9')
		    temp_num = temp_char - '0' + 53;
		    trans_num = temp_num;
		if (trans_num > 52 && trans_num <= 63)
		    trans_char = '0' + 63 - trans_num; 

        code[i] = trans_char;
    }
    code[len] = '\0';
    return code;
}

char* decode(char *code)
{
    int i,n,len;
    char prim[100];
    char temp_char,trans_char;
    int temp_num,trans_num;
    len = strlen(code);

    for(i = 0;i < len;i++) {
        temp_char = code[i];
        if (temp_char <= 'z' && temp_char >= 'a')
            temp_num = temp_char - 'a' + 1;
        else if (temp_char <= 'Z' && temp_char >= 'A')
            temp_num = temp_char - 'A' + 27;

        n = temp_num % 3;
        switch(n) {
        case 0:
            trans_num = temp_num/3;
            break;
        case 1:
            trans_num = 35 + temp_num/3;
            break;
        case 2:
            trans_num = 18 + temp_num/3;
            break;
        default:
            break;
        }
        if (trans_num > 26 && trans_num <= 52)       
            trans_char = 'A' + trans_num - 27;
        else if (trans_num > 0 && trans_num <= 26)
            trans_char = 'a' + trans_num - 1;
            
        if (temp_char <= '9' && temp_char >= '0')
            temp_num = '0' + 63 - temp_char;
            trans_num = temp_num;
        if (trans_num >52 && trans_num <= 63)
            trans_char = trans_num + '0' - 53;

        prim[i] = trans_char;
    }
    prim[len] = '\0';
    return prim;
}


void create_if_not_exit()
  /*ע����������������Ǿ���ĳ���˵���Ϣ
    ����"player_1.txt" ��������Ǿ�����Ϣ
    ���ļ��ı��湦����Ϊÿ���������ݶ���һ�����Բ�д 
	*/ 
{
	int i;
	char filename[50];
	strcpy(filename, user_name);
	strcat(filename, ".txt");
	FILE *fp;
	if(!(fp=fopen(filename,"r")))
  	{
     	FILE *fp = fopen(filename,"w");
     	fclose(fp);
	 	//�������û���Ϣ�ļ���δ����������ô����һ�� 
   	} 
   	fclose(fp); 
}