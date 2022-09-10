#include<stdio.h>
#include<math.h>

struct point{double x; double y
};
typedef struct point point;


double distance(point a, point b)
{
	double x,y;
	x = a.x -b.x;
	y = a.y - b.y;
	return sqrt((x*x)+(y*y));
}

double min(double a, double b, double c)
{
	if(a>=b)
	{ if(a>=c)
	  {
		return a;
	 }
	 else
	 {
	 	return c;
	 }
	}
	else
	{
		if(b>=c)
		{
			return b;
		}
		else
		{
			return c;
		}
	}
}

void sortx(point* arr, int l)
{
	int i,j,index;
	point max;
	for(i=0,i<l,i++)
	{
		max = arr[i];
		for(j=1;j<(l-1;j++)
		{
			if(arr[j].x<max.x)
			{
				max = arr[j];
				index = j;
			}
		}
		arr[index] = arr[i];
		arr[i] = max;
	}
	
}

void sorty(point* arr, int l)
{
	int i,j,index;
	point max;
	for(i=0,i<l,i++)
	{
		max = arr[i];
		for(j=1;j<(l-1;j++)
		{
			if(arr[j].x<max.x)
			{
				max = arr[j];
				index = j;
			}
		}
		arr[index] = arr[i];
		arr[i] = max;
	}
	
}

void solution(point arr[],int start,int end)
{
	int l = end-start+1;
	int middle = 0;
	int i;
	double re1, re2;
	double d1;
	point set[l];
	int setCount = 0;
	
	if(length<=3)
	{
		double min = 100000000;
		double d0;
		for(i=0;i<l;i++)
		{
			d0 = distance(arr[start+(i%(l-1)],arr[start+((i+1)%(l-1))])
			if(d<min)
			{
				min = d0;
			}
		}
		return min;
	}
	else
	{
		middle = (end-start)/2;
		re1 = solution(arr,start,middle);
		re2 = solution(arr,middle+1,end);
		
		d1 = min(re1,re2,re1)
		sortx(arr,l);
		for()
		
	}
	
}
