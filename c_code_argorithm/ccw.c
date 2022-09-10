#include<stdio.h>
#include<math.h>
struct vector2D{double x; double y; double angle; 
};

typedef struct vector2D vector2D;

vector2D sub(vector2D a, vector2D b)
{
	vector2D c={0,0};
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	
	return c;
}

vector2D add(vector2D a, vector2D b)
{
	vector2D c={0,0};
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	
	return c;
}

vector2D normalize(vector2D a)
{
	vector2D c={0,0};
	c.x = a.x/sqrt((a.x*a.x)+(a.y*a.y));
	c.y = a.y/sqrt((a.x*a.x)+(a.y*a.y));
	
	return c;
}

double crossMultipleLength2D(vector2D a, vector2D b)
{
	return a.x*b.y - a.y*b.x;
}

int ccw(vector2D a, vector2D c, vector2D d)
{
  vector2D n1 = sub(c,a);
  vector2D n2 = sub(d,a);
  n1 = normalize(n1);
  n2 = normalize(n2);
  
  double crossV = crossMultipleLength2D(n1,n2);
  
  if(crossV>0)
   return -1;
  else if(crossV<0)
   return 1;
  else
    return 0;  
  	
}

double angle(vector2D a, vector2D b)
{
	double dx = b.x - a.x;
	double dy = b.y - a.y;
	
	double Angle = fabs(dy)/(fabs(dx)+fabs(dy));
	
	if((dx >= 0)&&(dy==0))
	{
		return 0;
	}
	else if((dx<0)&&(dy>=0))
	{
		Angle = 2 - Angle;
	}
	else if((dx<=0)&&(dy<0))
	{
		Angle = 2 +Angle;
	}
	else if((dx>=0)&&(dy<0))
	{
		Angle = 4 - Angle;
	}
	
	return Angle*90;
}

double distance(vector2D a, vector2D b)
{
	double x = fabs(a.x-b.x);
	double y = fabs(b.y - a.y);
	double d = sqrt((x*x)+(y*y));
	return d;
}

double solution(vector2D arr[], int num)
{
  int i,j;
  vector2D min;
  vector2D start;
  vector2D arr2[num];
  int index;
  int set[num];
  
  for(i=0;i<num;i++)
  {
  	set[i] = 0;
  }
  
   min = arr[0];
   for(j=0;j<num;j++)
   {
   	 if(arr[j].y<=min.y)
   	 {
   	 	if(arr[j].y == min.y)
   	 	{
   	 	if(arr[j].x < min.x){
			
   	 	min = arr[j];
   	 	index = j;
		}
			}
		else
		{
		min = arr[j];
   	 	index = j;
			}	
   	 
   }
  }
  
  
  start = arr[index];
  start.angle = 0;
  
  for(i=0;i<num;i++)
  {
  	arr[i].angle = angle(start,arr[i]);
  	printf("%f\n",arr[i].angle);
  }
  
  for(i=0;i<num;i++)
  {
  	arr2[i] = arr[i];
  }
  
  for(i=0;i<num-1;i++)
  {min = arr2[0];
   for(j=i+1;j<num;j++)
   {
   	 if(arr2[j].angle<min.angle)
   	 {
   	 	min = arr2[j];
   	 	index = j;
		}
   }
   arr2[index] = arr2[i];
   arr2[i] = min; 
  	
  }
  
  vector2D stack[num];
  int current = 2; 
  stack[0] = arr2[0];
  stack[1] = arr2[1];
  stack[2] = arr2[2];
  
  set[1] = 1;
  set[2] = 2;
  
  int box;
  for(i=3;i<num;i++)
  {
  	if(ccw(stack[current-1],stack[current],arr2[i])==1)
  	{
  		current = current+1;
  		stack[current] = arr2[i];
	  }
	else
	{
		while(ccw(stack[current-1],stack[current],arr2[i])==1)
		{
			current = current-1;
			
		}
		current = current+1;
		stack[current] = arr2[i];
	  }
	  
  }
  
  double total = 0;
  for(i=1;i<=current;i++)
  {
  	total+=distance(stack[i-1],stack[i]);
  }
  
  for(i=0;i<=current;i++)
  {
  	printf("%f %f\n",stack[i].x,stack[i].y);
  }
  printf("\n");
  for(i=0;i<num;i++)
  {
  	printf("%f %f %f\n",arr[i].x,arr[i].y,arr[i].angle);
  }
  return total;
  
}

int main(void)
{
	int num;
	printf("input:\n");
	scanf("%d",&num);
	int i;
	vector2D arr[num];
	for(i=0;i<num;i++)
	{
		vector2D box;
		scanf("%lf %lf",&box.x, &box.y);
		box.angle = 0;
		arr[i] = box;
	}
	printf("result:%f",solution(arr,num));
	return 0;
	
}
