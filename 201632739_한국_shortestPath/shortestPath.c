#include<stdio.h>
#include<stdlib.h>

int index(int crow,int arow,int type)
{
	if(type == 1)
	{
		if((crow-1)<0)
		 crow = arow-1;
		else
		 crow = crow-1; 
		
	}
	else if(type==3)
	{
		if((crow+1)==arow)
		 crow = 0;
		else
		  crow = crow+1; 
	}
	else;
	
	return crow;
}

void shortestPath(int**arr,int row, int col,int size)
{
	int arr2[row][col+1];
	int i,j,k,re;
	
	for(i=0;i<row;i++)
	{
		arr2[i][col] = 10000;
		arr2[i][col-1] = arr[i][col-1];
	}
	
	for(i=col-1;i>=1;i--)
	{
		for(j=0;j<row;j++)
		{
			for(k=1;k<=size;k++)
			{
				re = arr2[index(j,row,k)][i]+arr[j][i-1];
				if(arr2[j][col]>re)
				 {
				 	arr2[j][col] = re;
				 }
				 
			}
			
			arr2[j][i-1] = arr2[j][col];
		}
		
		for(j=0;j<row;j++)
		{
			arr2[j][col] = 10000;
			
		}
		
	}
	
	int num,max;
	max = arr2[0][0];
	num = 0;
	for(i=1;i<row;i++)
	{
		if(max>arr2[i][0])
		{
			max = arr2[i][0];
			num = i;
		}
	}
	printf("shortestPath: %d\n",arr2[num][0]);
	printf("path: ");
	
	int arr3[col];
	int num2;
	arr3[0] = num;
	for(i=1;i<col;i++)
	{
		max = index(num,row,1);
		for(j=2;j<=size;j++)
		{
			num2 = index(num,row,j);
			if(arr2[max][i]>arr2[num2][i])
			 max = num2;
		}
		num = max;
		arr3[i] = max;
	}
	
	for(i=0;i<col;i++)
	 printf("%d ",arr[arr3[i]][i]);
	 
	printf("\n"); 
	
	return;
}

int arr[5][6] = {{3,4,1,2,8,6},{6,1,8,2,7,4},{5,9,3,9,9,5},{8,4,1,3,2,6},{3,7,2,8,6,4}};
int test[5][6] = {{3,4,1,2,8,6},{6,1,8,2,7,4},{5,9,3,9,9,5},{8,4,1,3,2,6},{3,7,2,1,2,3}};

int main(void)
{
int row,col;
scanf("%d %d",&row,&col);
int arr[row][col];
int x,y;
for(x=0;x<row;x++)
{
	for(y=0;y<col;y++)
	{
		scanf("%d",&arr[x][y]);
	}
	
}
puts("result:");
	
	int** arr2 = (int**)malloc(sizeof(int*)*row);
	int i,j;
	for(i=0;i<row;i++)
	{
		arr2[i] = (int*)malloc(sizeof(int)*col);
	}
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			arr2[i][j] = arr[i][j];
		}
	}
	
	shortestPath(arr2,row,col,3);
	return 0;
}
