#include<stdio.h>
#include<stdlib.h>

int Solution(char* s, char* t,int sm,int tm)
{
	int arr[tm+1][sm+1];// record past branch's calculated values
	int i,j,k; // count variables
	int result = 0;// result variable
	for(i=0;i<=tm;i++) //initialize array to zero
	{
		for(j=0;j<=sm;j++)
	   {
		arr[i][j] = 0;
	   }
	}
	
	// main algorism iterlate tm+1 X sm+1
	for(i=1;i<=tm;i++) 
	{
		for(j=1;j<=sm;j++)
		{
			if(s[j-1] == t[i-1])
			{
				if(i==1)// count number of first matched char
				  arr[i][j]+=1;
				else
				{
				    
				for(k=0;k<j;k++)// if position of char > 1 then add past branch's calculated values 
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
	
	for(i=0;i<tm+1;i++)// show entire matrix
	{
		for(j=0;j<sm+1;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	
	for(i=0;i<=sm;i++)// calculate final result
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
