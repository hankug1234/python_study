#include<stdio.h>
#include<math.h>

int gcd(int a, int b)
{
	int a1, b1,c;
	a1 = a; b1 = b;
	while((a1!=1)&&(b1!=0))
	{
		if(a1>b1)
		{
			c = a1; a1 = b1; b1 = c;
			b1 = b1%a1;
		}
		else
		{
			b1 = b1%a1;
		}
		
	}
	
	if(a1==1)
	 return 1;
	else
	 return a1; 
}

int* solution(int a, int b)
{
	
}
