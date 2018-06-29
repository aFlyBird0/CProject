#include <stdio.h>
#include <string.h>

int main()
{
	freopen("in and out.txt","r",stdin);
	int i=0,j=0,m=0,n1=0,n=0,n2=0,n3=0,
 		b[500]={0},k=0,c[600]={0};
 		//scanf("%d",&num) ;
	char ch[20], str[10000]= "", result[11000];
	while(scanf("%s",ch)!=EOF)
	{
		strcat(str," ");
		strcat(str,ch);
	}
	//printf("%s\n",str);
	for(i=0;str[i]!='\0';i++)
	{
		//if(str[i]=='¡£') str[i]='.'; 
		//if(str[i]=='£¿') str[i]='?';
		//if(str[i]=='£¡') str[i]='!';
		//if(str[i]=='£¬') str[i]=',';
		if(str[i]=='.'||str[i]=='?'||str[i]=='!')
		{
			b[j] = i;
			j++;
		}
		if(str[i]==',')
		{
			c[k] = i;
			k++;
		}
		n1 = i;
	}
	fclose(stdin);
	k = 0;
	j = 0;
	n3 = n1;
	for(i=0;i<=n1;i++)
	{
		result[j] = str[i];
		if(i==b[m])
		{
			if(str[i+1]!=' ')
			{
				j++;
				result[j] = ' ';
				
			}
			else
			{
				result[j] = str[i]; 
			}
			m++;
		}
		if(i==c[k])
		{
			if(str[i+1]!=' ')
			{
				j++;
				result[j] = ' ';
				
			}
			else
			{
				result[j] = str[i]; 
			}
			k++;
		}
		n3++;
		j++;
	}
	
	i = 0;
	j = 0;
	m = 0;
	for(i=0;i<=n3;i++)
	{
		if(result[i]=='.' || result[i]=='?' || result[i]=='!')
		{
			if(result[i+2]>='a' && result[i+2]<='z')
			{
				result[i+2] -= 32;
			}
		}
	}
	freopen("in and out.txt","w",stdout);
	k = 0;
	for(i=0;i<=n3;i++)
	{
		putchar(result[i]);
		
		//if(result[i]=='\n') k = 0;
		if(k>=45 && result[i]==' ')
		{
			putchar('\n');
			k = 0;
		}
		k++;
		
	}
	//printf("%s\n",result);
	fclose(stdout);
	return 0;
}
