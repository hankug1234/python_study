#include<stdio.h>
#include<stdlib.h>

int Solution(char* s, char* t,int sm,int tm)
{
	int arr[tm+1][sm+1];
	int i,j,k;
	int result = 0;
	for(i=0;i<=tm;i++)
	{
		for(j=0;j<=sm;j++)
	   {
		arr[i][j] = 0;
	   }
	}
	
	
	for(i=1;i<=tm;i++)
	{
		for(j=1;j<=sm;j++)
		{
			if(s[j-1] == t[i-1])
			{
				if(i==1)
				  arr[i][j]+=1;
				else
				{
				    
				for(k=0;k<j;k++)
				{
					arr[i][j]+=arr[i-1][k];
				}
			   }
			}
			else
			{
				arr[i][j] = 0;
			}
		}
	}
	
	for(i=0;i<tm+1;i++)
	{
		for(j=0;j<sm+1;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	
	for(i=0;i<=sm;i++)
	 result+=arr[tm][i];
	printf("amount: %d",result);
	
	return 0;
}


int main(void)
{
	char s[12];
	char t[12];
	printf("please enter string 10\n");
	scanf("%s",s);
	printf("please enter string 10\n");
	scanf("%s",t);
	
	Solution(s,t,strlen(s),strlen(t));
	return 0;
}
