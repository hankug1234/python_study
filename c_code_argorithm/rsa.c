#include<stdio.h>
#include<math.h>

struct Public{int e; int n;
};
struct Private{int d; int n;
};

typedef struct Public Public;
typedef struct Private Private;

int rsa(int a, int b, int n)
{
	int c,d;
	c = 0; d = 1;
	int arr[32];
	int count =0;
	while(b>1)
	{
		if((b%2) == 0)
		 arr[count] = 0;
		else
		 arr[count] = 1;
		count+=1;
		b = b/2;  
	}
	arr[count] = 1;
	int i;
	
	for(i=count;i>=0;i--)
	{
		c = 2*c;
		d = (d*d)%n;
		if(arr[i] == 1)
		 {
		  c+=1;
		  d = (d*a)%n;
	     }
		 
	}
	return d;

}

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

int e(int a)
{
	int count = 3;
	while((gcd(a,count)!=1))
	{
		count+=2;
	}
	return count;
}

int d(int n,int e)
{
	int count = 1;
	int a = (count*n)+1;
	while((a%e)!=0)
	{
		count+=1;
		a = (count*n)+1;
	}
	return a/e;
}

Public pb(int p, int q)
{
	int n = (p-1)*(q-1);
	int ee = e(n);
	Public r;
	r.e = ee;
	r.n = p*q;
	
	return r;
}

Private pr(int p, int q,int e)
{
	int n = (p-1)*(q-1);
	int dd = d(n,e);
	Private r;
	r.d = dd;
	r.n = p*q;
	
	return r;
}

int Encrypt(int M, Public k)
{
	return (int)rsa((int)M,k.e,k.n);
}

int Encrypt2(int M, int k, int n)
{
	return (int)rsa((int)M,k,n);
}

int Decrypt(int S, Private k)
{
	return (int)rsa(S,k.d,k.n);
}

int Decrypt2(int S, int k, int n)
{
	return (int)rsa(S,k,n);
}

int main(void)
{
	int p,q;
	char str[500];
	int estr[500];
	int i;
	for(i=0;i<500;i++)
	 estr[i] = 0; 
	
	
	printf("please enter prime number:");
	scanf("%d",&p);
	printf("please enter prime number:");
	scanf("%d",&q);
	
	
	Public pbk = pb(p,q);
	Private prk =  pr(p,q,pbk.e);
	
	while(getchar()!='\n');
	printf("please enter sentence:");
	scanf("%s",str);

	
	int count=0;
	printf("encrypt:");
	while(str[count]!='\0')
	{
		estr[count] = Encrypt((int)str[count],pbk);
		printf("%d ",estr[count]);
		count+=1;
	}
	puts("");
	
     int nn;
	for(i=0;i<count;i++)
	{   
		nn = Decrypt(estr[i],prk);
		str[i] = (char)nn;
		
	}
	
	printf("decrypt:%s\n",str);
	
	printf("private key: %d\n",prk.d);
	printf("public key: %d\n",pbk.e);
	printf("n: %d %d",pbk.n,prk.n);
	
	return 0;
}
