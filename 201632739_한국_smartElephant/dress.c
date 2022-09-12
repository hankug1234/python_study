#include<stdio.h>
struct data{int num; int date; double panelty; int price;
};

typedef struct data data;

void solution(int work,int size, data* list)
{
	data box;
	int i,j;
	for(i=0;i<size;i++)
	{
		list[i].panelty = 0;
		list[i].panelty = (double)(list[i].price)/(double)list[i].date;
	}
	puts("");
	
	
	puts("");
	int k=0;
	
	for(i=0;i<size;i++)
	{   
	    box = list[i];
	    k=i;
		for(j=i+1;j<size;j++)
		{
			if(box.panelty<list[j].panelty)
			{
			
			 box = list[j];
			 k = j;
		    }
		}
		list[k] = list[i];
		list[i] = box;
	}
	
	for(i=0;i<size;i++)
	{
		printf("%d",list[i].num+1);
	}
	printf("\n");
	return;
}

int main(void)
{
	int work = 0;
	int size = 0;
	int i,j;
	
	scanf("%d",&work);
	scanf("%d",&size);
	
	data arr[size];
	for(j=0;j<work;j++)
	{
	
	for(i=0;i<size;i++)
	{
		scanf("%d %d",&arr[i].date,&arr[i].price);
		arr[i].num = i;
	}
	
	solution(work,size,arr);
}
return 0;
}
