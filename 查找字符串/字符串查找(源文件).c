#include <stdio.h>
#include <string.h>

struct peo
{
	char name[60];
}people[500];
struct peo2
{
	char name[60];
}people2[500];

int main()
{
	//char in1[150][25], in2[150][25];
	int i = 0,j = 0,k=0,n,m,line=0;
	freopen("in1.txt","r",stdin);
	while(scanf("%s",people[i].name)!=EOF)
	{
		i++;
	}
	i--;
	n = i;
	freopen("in2.txt","r",stdin);
	while(scanf("%s",people2[j].name)!=EOF)
	j++;
	j--;
	m=j;
	fclose(stdin);
	freopen("out.txt","w",stdout);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(!strcmp(people[i].name,people2[j].name)) 
			{
				k=1;
				break;
			}
			else k=0;
		}
		if(k==0)
		{
			printf("%s\t",people[i].name);
			line++;
			if(line==5)
			{
				putchar('\n');
				line=0;
			}
		}
		k = 0 ;
	}
	fclose(stdout);
	return 0 ;
}
