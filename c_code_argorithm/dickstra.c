#include<stdio.h>
#include<stdlib.h>
#inlcude<string.h>

struct data{int time; char name[20];
};

typedef struct data data;

void dicstra(char**name,int** table,int size,char*start)
{
   char* dataSetD[size];
   char* dataSetND[size];
   
   int i;
   for(i=0;i<size;i++)
   {
   	 dataSetND[i] = name[i];
   }
   
   dataSetD[0] = start;
   
   
}

void set(char** name,int** table,int num, int size; char*start,char* end)
{
	int i,j,row,col;
	j=0; row = -1; col = -1;
	
	for(i=0;(i<size)&&(j<2);i++)
	{
		if(strcmp(name[i],start))
		{
			j+=1;
			col = i;
		}
		
		if(strcmp(name[i],end))
		{
			j+=1;
			row = i;
		}
	}
	
	table[row][col] = num;
	
}
