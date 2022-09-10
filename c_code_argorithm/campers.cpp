#include<stdio.h>
#include<math.h>

struct vector{double x; double y; double angle;
};

typedef struct vector vector;

struct data{vector d; struct data* next;
};

typedef struct data data;

void modeChange(double angle,int*mode)// change angle calculate mode
{
	if((angle>=0.0)&&(angle<=90.0))
	{
		 *mode = 1;
	}
	else if((angle>90.0)&&(angle<180.0))
	{
		*mode = 2;
	}
	else if((angle>=180.0)&&(angle<270.0))
	{
		*mode = 3;
	}
	else
	{
		*mode = 4;
	}
}

double distance(vector a, vector b)//calculate distance of two point
{
	double c,d;
	c = b.x - a.x;
	d = b.y - a.y;
	return sqrt((c*c)+(d*d));
}

vector angle(vector zero,vector a,int mode)//calculate angle
{
	double adx, ady, bdx, bdy;
	adx = mode*(a.x-zero.x);
	ady = mode*(a.y-zero.y);
	
	vector n1 = {0,0,0};
	
	n1.x = a.x; n1.y = a.y;
	
	double angleA = fabs(ady)/(fabs(adx)+fabs(ady));
	
	if((adx>=0)&&(ady==0))
	 angleA = 0;
	else
	{
		if((adx<0)&&(ady>=0))
		 angleA = 2-angleA;
		else if((adx<=0)&&(ady<0))
		  angleA = angleA = 2+angleA;
		else if((adx>0)&&(ady<0))
		  angleA = 4-angleA;   
	 } 
	 
	 n1.angle = angleA*90;
     printf("angle:%f y:%f x:%f\n",n1.angle,n1.y,n1.x);	 
	 return n1;
	
}

vector improveAngle(vector zero,vector a,int mode)// calculate relative angle
{
	double adx, ady, bdx, bdy;
	int modea=0,modeb=0;
	
	switch(mode)
	{
		case 1: modea = 1; modeb = 1; break;
		case 2: modea = 1; modeb = -1; break;
		case 4: modea = -1; modeb = 1; break;
		case 3: modea = -1; modeb = -1; break;
		default: break;
	}
	
	if((mode==1)||(mode == 3))
	{
	adx = modea*(a.x-zero.x);
	ady = modeb*(a.y-zero.y);
    }
    else 
    { 
     ady = modeb*(a.x-zero.x);
	 adx = modea*(a.y-zero.y);	
	}
	
	vector n1 = {0,0,0};
	
		n1.x = a.x; n1.y = a.y;
	
	
	double angleA = fabs(ady)/(fabs(adx)+fabs(ady));
	
	if((adx>=0)&&(ady==0))
	 angleA = 0;
	else
	{
		if((adx<0)&&(ady>=0))
		 angleA = 2-angleA;
		else if((adx<=0)&&(ady<0))
		  angleA = angleA = 2+angleA;
		else if((adx>0)&&(ady<0))
		  angleA = 4-angleA;   
	 } 
	 
	 n1.angle = angleA*90;
	 
	 return n1;
	
}


void march(vector a[],int num,vector zero)// normal javis march funtion
{
	
  int set[num];
  int i,mode=1;
  int init = 0;
  int max; double maxAngle = 360.0;
  vector z = zero;
  
  for(i=0;i<num;i++)
  {
  	set[i] = 0;
  }
  
  for(i=0;i<num;i++)
  {
  	if((zero.x==a[i].x)&&(zero.y==a[i].y))
  	{
  		init = i;
  		break;
	  }
  }
  
  while(set[init]!=1)
  {
   
  for(i=0;i<num;i++)
  {
  	a[i] = angle(z,a[i],mode);
  	if(maxAngle>a[i].angle)
  	{if(set[i] == 0)
	  {
	    
  	  if((z.x!=a[i].x)||(z.y!=a[i].y))
  		{
		  max = i; maxAngle = a[i].angle;}
		  
	  }
    }
  }
   
  if(maxAngle>=180.0)
   mode = -1*mode;
  
  z = a[max];
  maxAngle = 360.0;
  set[max] = 1;
  
  	
  }
  
  for(i=0;i<num;i++)
  {
  	if(set[i] == 1)
  	 printf("%f %f\n",a[i].x,a[i].y);
	}  
   
}

double improveMarch(vector a[],int num,vector zero)// calculate shortest silke path
{
	
  int set[num];//set of outer point
  double set2[num];// set of each path's length
  int set3[num];// set of each path's max outer point number
  int s = 2;
  double total;
  int i,mode=1;
  int init = 0;//initial point index number variable
  int init2 = 0;
  int max; double maxAngle = 360.0;
  vector z = zero;
  vector out;
  vector order[num];
  int j,k;
  
  for(i=0;i<num;i++)//sort entire point set by there angle
  {
  	order[i] = improveAngle(zero,a[i],mode);
  }
  
  for(i=0;i<num-1;i++)
  {
  	max = i;
  	out = order[i];
  	for(j=i+1;j<num;j++)
  	{
  		if(out.angle>order[j].angle)
  		{
  			max = j;
  			out = order[j];
		  }
	  }
	  order[max] = order[i];
	  order[i] = out;
  }
  
  
  for(i=0;i<num;i++)// initialize variable
  {
  	set[i] = 0;
  	set2[i] = 0.0;
  	set3[i] = 0;
  }
  
  for(i=0;i<num;i++)// find initial point index number
  {
  	if((zero.x==a[i].x)&&(zero.y==a[i].y))
  	{
  		init = i;
  		break;
	  }
  }
  
  for(j=1;j<num;j++)// select start direction
  {
  	out = order[j]; 
  	for(i=0;i<num;i++)
  {
  	if((out.x==a[i].x)&&(out.y==a[i].y))
  	{
  		init2 = i;
  		break;
	  }
  }
  
   modeChange(out.angle,&mode);//select start direction
  
  
  set[init2] = 1;
  while(set[init]==0)//javis march argolithm
  {
   
  for(i=0;i<num;i++)
  {
  	a[i] = improveAngle(out,a[i],mode);
  	if(maxAngle>a[i].angle)
  	{if(set[i] == 0)
	  {
	    
  	  if((out.x!=a[i].x)||(out.y!=a[i].y))
  		{
		  max = i; maxAngle = a[i].angle;}
		  
	  }
    }
  }
   
  modeChange(angle(zero,a[max],1).angle,&mode);
  out = a[max];
  maxAngle = 360.0;
  set[max] = s;
  s+=1;
  	
  }
  
  for(i=0;i<num;i++)
   printf("%d\n",set[i]);
  printf("\n"); 
  
  mode = 1;
  z = zero;
  total = 0.0;
  init2 = 0;
  for(k=1;k<=s;k++)
  {
  
  	for(i=0;i<num;i++)
  {
  	if(set[i] == k)
  	{
  		init2 = i;
  		break;
	  }
  }
  
  	total+=distance(z,a[init2]);
  	z = a[init2];
  
 }
 set3[j] = s;
 s = 2;
 set2[j] = total;
  for(i=0;i<num;i++)
  {
  	set[i] = 0;
  }
  
}
 
 double re = 9999999.0;
 int m=0;
 for(i=0;i<num;i++)
 {
 	if(set3[i]>m)
 	 m =  set3[i];
 }
  
  for(i=1;i<num;i++)
  {if(set3[i]==m)
  {
  
  	 if(set2[i]<re)
  	  re = set2[i];
  }
  }
  
  return re+2.0;
   
}


int main(void)
{
	int test,size;
	printf("please enter test number:");
	scanf("%d",&test);
	printf("\n\n\n");
	
	
	vector a = {.x=0,.y=0,.angle=0};
	vector arr[size+1];	
	arr[0] = a;
	int i,j;
	for(j=0;j<test;j++)
    {
    	printf("please enter point number:");
	scanf("%d",&size);
	 printf("\nplease enter point location y x\n");
	for(i=0;i<size;i++)
	{
		scanf("%lf %lf",&(arr[i+1].y),&(arr[i+1].x));
		arr[i+1].angle = 0;
	}
	
	double re = improveMarch(arr,size+1,a);
	
	printf("result:%f\n",re);
	
    }
	
	
	return 0;
}
