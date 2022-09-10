#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct data{double x; double y;
};

struct datas{int s; int d; double dis;
};

typedef struct data data;
typedef struct datas datas;


double distance(double x1, double y1,double x2, double y2)
{
	double a = x1 - x2;
	double b = y1 - y2;
	
	return sqrt((a*a)+(b*b));
}

void solution(void)
{int size=0;
int i,j;
	scanf("%d",&size);
data list[size];	
	for(i=0;i<size;i++)
	{
		scanf("%f %f",&list[i].x,&list[i].y);
	}
 	
	puts("1");
 double arr[size][size];
 for(i=0;i<size;i++)
 {
 	for(j=0;j<size;j++)
 	{
 		arr[i][j] = 0;
	 }
 }
 puts("2");
 for(i=0;i<size;i++)
 {
 	for(j=0;j<size;j++)
 	{
 		arr[i][j] = distance(list[i].x,list[i].y,list[j].x,list[j].y);
	 }
 }

int nsize = ((size*size)-size)/2;
datas list2[nsize];



for(i=0;i<nsize;i++)
{
	list2[i].s = 0;
 		list2[i].d = 0;
 		list2[i].dis = 0;
}



int count = 0;
puts("3");
for(i=0;i<size;i++)
 {
 	for(j=i+1;i<size;i++)
 	{
 		list2[count].s = i;
 		list2[count].d = j;
 		list2[count].dis = arr[i][j];
 		count+=1;
 		
	 }
 }
 puts("4");
 datas box;
 double max = 0;
 int num;
 for(i=0;i<nsize-1;i++)
 { max = list2[i].dis;
   num = i;
 	for(j=i+1;j<nsize;j++)
 	{
 		if(list2[j].dis>max)
 		{
		 
 		 max = list2[j].dis;
 		 num = j;
 	    }
 		 
	 }
	 box.s = list2[i].s;
	 box.d = list2[i].d;
	 box.dis = list2[i].dis;
	 
	 list2[i].s = list2[num].s;
	 list2[i].d = list2[num].d;
	 list2[i].dis = list2[num].dis;
	 
	 list2[num].s = box.s;
	 list2[num].d = box.d;
	 list2[num].dis = box.dis;
  }
  
  double count2 = 0.0;
  puts("5");
  for(i=0;i<nsize;i++)
  {count2 = 0.0;
  printf("%d\n",list2[i].s);
   arr[list2[i].s][list2[i].d] = 0;
  	for(j=list2[i].s+1;j<size;j++)
  	{
  	   count2+=arr[list2[i].s][j];
  		printf("%f\n",count2);
	  }
	  if(count2==0)
	   arr[list2[i].s][list2[i].d] = list2[i].dis;
  }

 count2 = 0.0;
 puts("6");
 for(i=1;i<size;i++)
 {
 	for(j=i+1;i<size;i++)
 	{
 		count2+=arr[i][j];
	 }
 }
 
 printf("reslut: %f\n",count2);
 
 return;
 
 	
}

void main(void)
{
	solution();
}
