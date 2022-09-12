#include<stdio.h>
#include<stdlib.h>

void box(int pearl,int b1, int p1, int b2, int p2)
{
	int i,j,k,i1,j1,x;
	double cost1 = (double)p1/(double)b1;
	double cost2 = (double)p2/(double)b2;
	int result = 0;
	
	if(cost2<cost1)
	{
		j = p2; i = b2;
		j1 = p1; i1 = b1;
	}
	else
	{
		j = p1; i = b1;
		j1 = p2; i1 = b2; 
	}
	x = (pearl/i);
	
	if(pearl%i == 0)
	 printf("%d %d",x,0);
	else
	{
		result = (i*x)+i1;
		for(k=1;(result-i*k)>=pearl;k++);
		
		if((result-i*k)==pearl)
		 printf("%d %d",x-k,1);
		else
		 puts("fail");
		
	}
	

}

int main(void)
{
	box(43,3,1,4,2);
	return 0;
}
