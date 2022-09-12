#include<stdio.h>
#include<stdlib.h>

struct block{struct block* next;int*arr;
};

typedef struct block block;

block* make(int max)
{
	block* re = (block*)malloc(sizeof(block));
	re->arr = (int*)malloc(sizeof(int)*max);
}

void insert(int* data,int max,block** head)
{
	block* ne = make(max);
	if(*head == NULL)
	*head = ne;
	else
	(*head)->next = ne;
	
	int i;
	for(i;i<max;i++)
	{
		ne->arr[i] = data[i];
	}
}


void run(int** arr,int row,int col,int* count)
{
	
	if((row<=0)||(col<=0))
	{
		*count+=1;
		return;
	}
	else
	{
		
		if(arr[row][col]==(arr[row-1][col-1]+1))
		{printf("%d %d\n",row,col);
			run(arr,row-1,col-1,count);
			
		}
		else
		{
			
		if(arr[row][col]==arr[row-1][col])
		{printf("%d %d\n",row,col);
			run(arr,row-1,col,count);
			
		}
		
		if(arr[row][col]==arr[row][col-1])
		{printf("%d %d\n",row,col);
			run(arr,row,col-1,count);
			
		}
		
		arr[row][col] = -4;
	   }
	   
		
	}
	return;
}

int search(int** arr,int size)
{
   int count = 0;
   run(arr,size,size,&count);
   return count;	
}
