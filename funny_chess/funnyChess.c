#include<stdio.h>
#include<stdlib.h>

struct tile{int x; int y;
};
typedef struct tile tile;


int** makeArr(int row, int col)
{
	int** arr = (int**)malloc(sizeof(int*)*row);
	int i = 0;
	for(i=0;i<row;i++)
	{
		arr[i] = (int*)malloc(sizeof(int)*col);
	}
	return arr;
}

void initArr(int** arr, int row, int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			arr[i][j] = 0;
		}
	}
}

void put(int** arr, int row, int col, tile p)
{
	int i = p.x;
	int j = p.y;
	while((i>=0)&&(j>=0))
	{
		arr[i][j] += 1;
		i-=1;
		j-=1;
	}
	i = p.x;
	j = p.y;
	while((j<col)&&(i>=0))
	{
		arr[i][j] += 1;
		i-=1;
		j+=1;

	}
	i = p.x;
	j = p.y;
	while((j>=0)&&(i<row))
	{  arr[i][j] += 1;
		i+=1;
		j-=1;
	}
	i = p.x;
	j = p.y;
	while((j<col)&&(i<row))
	{arr[i][j] += 1;
		i+=1;
		j+=1;
		
	}
}

void unPut(int** arr, int row, int col, tile p)
{
	int i = p.x;
	int j = p.y;
	
	while((i>=0)&&(j>=0))
	{arr[i][j] -= 1;
		i-=1;
		j-=1;
		
		
	}
	i = p.x;
	j = p.y;
	while((j<col)&&(i>=0))
	{arr[i][j] -= 1;
		i-=1;
		j+=1;
		
	}
	i = p.x;
	j = p.y;
	while((j>=0)&&(i<row))
	{arr[i][j] -= 1;
		i+=1;
		j-=1;
		
	}
	i = p.x;
	j = p.y;
	while((j<col)&&(i<row))
	{arr[i][j] -= 1;
		i+=1;
		j+=1;
		
	}
}

int canPut(int** arr, tile p,int**state)
{
	if((arr[p.x][p.y] > 0)||(state[p.x][p.y]!=0))
	 return 0;
	else
	 return 1; 
}


void onState(int** state, tile point, int num)
{
	state[point.x][point.y] = num;
	
}

void offState(int** state,int row, int col, int num)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(state[i][j] == num)
			 state[i][j] = 0;
		}
	}
}

void solve(int** arr, int row,int col, int num, int*can, int** state)
{
	int i,j;
 if(num == 0)
  {*can+=1;
  return;
  }	
	
 for(i=0;i<row;i++)
  {
  	for(j=0;j<col;j++)
  	{tile point = {i,j};
  		if(canPut(arr,point,state) == 1)
  		{
  			put(arr,row,col,point);
  			onState(state,point,num);
  			solve(arr,row,col,num-1, can,state);
  			unPut(arr,row,col,point);
  			
		}
		  
	  }
  }
  offState(state,row,col,num);
  
}

int solution(int row, int col, int num)
{
  int** arr = makeArr(row,col);
  int** state = makeArr(row,col);
  initArr(arr,row,col);
  initArr(state,row,col);
  int can = 0;
  
  solve(arr,row,col,num,&can,state);
  
 return can; 	
}



 int main(void)
 {  printf("input:\n");
    int i=1,j=1;
    while((i!=0)&&(j!=0))
    {
    	scanf("%d %d",&i,&j);
    	printf("result: %d\n",solution(i,i,j));
	}
    
 	return 0;
 }
