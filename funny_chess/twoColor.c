#include<stdio.h>
#include<stdlib.h>

struct vertax{int i; int j;
};

typedef struct vertax vertax;

int** makeArr(int row, int col)
{
	int** arr = (int**)malloc(sizof(int*)*row);
	int i;
	for(i=0;i<row;i++)
	{
		arr[i] = (int*)malloc(sizeof(int)*col);
	}
	
	return arr;
}

void initArr(int** arr,int row, int col)
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

void initGrap(int** arr,int vnum, vertax* list)
{
	int i;
	for(i=0;i<vnum;i++)
	{
		arr[list[i].i][list[i].j] = 1;
	}
	
}

int isValid(int**color,int cnum,int current)
{
	if(color[current-1][0] == color[current][0])
	{
		return 0;
	}
	
	return 1;
}

int solv(int** grap,int**color,int cnum, int current,int c)
{
	int state = 0;
	if(current == num)
	{
		
		return 1;
	}
	else
	{
		if(current == 0)
		{   int i;
			color[current][current] = 1;
			for(i=1;i<cnum;i++)
			{
				if(grap[current][i] == 1)
				{
				solv(grap,color,cnum,i,2);
			    }
			}
			
		}
		else
		{
			if(isValid(color,cnum,current)==1)
			{
				int j;
				for(j=0;j<cnum;j++)
				{
				if(grap[current][j])
				if(c == 1)
				{
					state = solv(grap,color,cnum,current+1,2);
				}
				else
				{
					state = solv(grap,color,cnum,current+1,1);
				}
				
			    }
			}
		}
	}
	return state;
}

void solution(int cnum, int vnum, vertax* list)
{
	int** grap = makeArr(cnum,cnum);
	int** color = makeArr(cnum,cnum);
	initArr(grap,cnum,cnum);
	initGrap(grap,vnum,list);
	
	
}



