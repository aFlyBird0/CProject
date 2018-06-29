#include <stdio.h>
#define MAX_DIGIT 100

int main()
{
	int i, n;
	char plus1[MAX_DIGIT], plus2[MAX_DIGIT];
	int a[MAX_DIGIT] = {0}, b[MAX_DIGIT] = {0};
	int result[MAX_DIGIT] = {0};
	scanf("%s%s", plus1, plus2);
	for(n=0; plus1[n]!='\0'; n++);
	for(i=0; plus1[i]!='\0'; i++)
 		a[n-i-1] = (int)(plus1[i] - '0');//char转int，反序 
	for(n=0; plus2[n]!='\0'; n++);
	for(i=0; plus2[i]!='\0'; i++)
 		b[n-i-1] = (int)(plus2[i] - '0');
	for(i=0; i<MAX_DIGIT; i++)
	{
		result[i] += (a[i] + b[i]);  //从最低位开始求和 
		if( result[i] >= 10 )           
		{
			result[i] -= 10;
			result[i+1] ++;         //进位 
		}			
	}
	for(n=MAX_DIGIT-1; result[n]==0; n--);
	for(i=n; i>=0; i--)
		printf("%d", result[i]);
	putchar('\n');
	return 0;
}
