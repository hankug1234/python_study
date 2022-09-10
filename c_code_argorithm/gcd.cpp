#include<stdio.h>

struct re{int d; int x; int y;
};
typedef struct re re;

re gcd(int x,int y)
{
	int a,b,c,count;
	count = 0;c=0;
	a=x; b = y;
	int list[100];
	
	while((b != 0)&&(a != 1))
	{
	 if(a>=b)
	 {
	 	c=a;
	 	a = b;
	 	b = c%b;
	 }
	 else
	 {
		b = b%c;
	 }
	 list[count] = b;
	 count+=1;
    }
    
    if(a == 1)
    {
    	re data;
    	data.d = 1;
    	data.x = 0;
    	data.y = 0;
    	return data;
	}
     
    int i;
    re data;
    data.d = a;
    data.x = 1;
    data.y = 0;
    
    int n,m;
    
    for(i=count-1;i>=0;i++)
    {
    	n = data.x;
    	m = data.y;
    	data.x = m;
    	data.y = n-list[i]*m;
	}
    
    return data;
}


int main(void)
{
	re data = gcd(15,6);
	printf("%d %d %d",data.d,data.x,data.y);
}
