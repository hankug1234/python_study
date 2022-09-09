#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point{double x; double y; int id; double distance;
};

typedef struct point point; 

struct points{int length; point list[];
};

typedef struct points points;

struct location{double x; double y;
};

typedef struct location location;

struct idNode{int id; struct idNode* next;
};

typedef struct idNode idNode;

struct idNodeList{int maxId; idNode* list;
};

typedef struct indNodeList indNodeList;

struct heapNode{double distance; int index;
};

typedef struct heapNode heapNode;

struct heapTable{int row; int col; heapNode** table;int state[];};

typedef struct heapTable heapTable;

heapNode** makeTable(int row, int col)
{
	int** arr = (heapNode**)malloc(sizeof(heapNode*)*row);
	int i = 0;
	for(i=0;i<row;i++)
	{
		arr[i] = (heapNode*)malloc(sizeof(heapNode)*col);
	}
	return arr;
}

void initHeapTable(heapNode** arr, int row, int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			arr[i][j].distance = 0.0;
			arr[i][j].index = -1;
		}
	}
}

heapTable* makeHeapTable(int row, int col)
{
	heapTable* re = (heapTable*)malloc(sizeof(heapTalbe)+(sizeof(int)*row));
	heapNode** table = makeTable(row, col);
	initHeapTable(table,row,col);
	re->row = row;
	re->col = col;
	re->table = table;
	int i;
	for(i=0;i<row;i++)
	{
		re->state[i] = 0;
	}
	
	
	return re;
}

void heapInsert(heapTable* table,int rowNum, heapNode data)
{
	int cstate = table->state[rowNum];
	table->table[rowNum][cstate] = data;
	
	int index = cstate+1;
	int parent;
	heapNode box;
	
	while(index !=1)
	{
		parent = index/2;
		if(table->table[rowNum][index-1]<table->table[rowNum][parent-1])
		{
			box = table->table[rowNum][parent-1];
			index = parent;
			
		}
		else
		 break;
	}
	
	table->table[rowNum][parent-1] = table->table[rowNum][cstate];
	table->table[rowNum][cstate] = box;
	table->state[rowNum] +=1;
	
}

void heapDelete(heapTable* table, int rowNum, heapNode* re)
{
	
	
  int cstate = table->state[rowNum];
  if(cstate == 0)
  {
  	heapNode null = {0.0,-1};
  	*re = null;
  }
  else
  {
    heapNode box = table->table[rowNum][cstate];
	table->state[rowNum] -=1;
	*re = table->table[rowNum][0];
	
	cstate -=1;
	
	table->table[rowNum][0] = box;
	index = 1;
	int left = index*2;
	int right = 2*index+1;
	
	while(true)
	{
		if(left > cstat)
		{
			break;
		}
		else if(left == cstate)
		{
			box = table->table[rowNum][index-1];
			table->table[rowNum][index-1] = table->table[rowNum][left-1]
			table->table[rowNum][left-1] = box;
			index = left;
		}
		else
		{
		
		if(table->table[rowNum][left-1].distance < table->table[rowNum][right-1].distance)
		{
			box = table->table[rowNum][index-1];
			table->table[rowNum][index-1] = table->table[rowNum][left-1]
			table->table[rowNum][left-1] = box;
			index = left;
		}
		else
		{
			box = table->table[rowNum][index-1];
			table->table[rowNum][index-1] = table->table[rowNum][right-1]
			table->table[rowNum][right-1] = box;
			index = right;
		}
	    }
		
		left = index*2;
		right = 2*index+1;
		
	}
		
    
  }
	
	
}

int getId(idNodeList* idList)
{
	if((idList->maxId == -1)||(idList->list == NULL)
	{
		 makeIdNode(idList);
	}
	
	idNode* n = idList->list;
	idList->list = n->next;
	int re = n->id;
	free(n);
	
	return re;
}

void freeId(idNodeList* idList, int id)
{ 
  idNode* re = (idNode*)malloc(sizeof(idNode));
  re->next = idList->list;
  re->id = id;
  idList->list = re;
	
}

idNodeList* makeIdNodeList(void)
{
	idNodeList* re = (idNodeList*)malloc(sizeof(idNodeList));
	re->maxId = -1;
	re->list = NULL;
	return re;

}

void makeIdNode(idNodeList* idList)
{
	idNode* re = (idNode*)malloc(sizeof(idNode));
	re->next = idList->list;
	idList->maxId+=1;
	int newId = idList->maxId;
	re->id = newId;
	idList->list = re;
	
}


points* makePoints(int len, location* p,idNodeList* idList, int flag)
{
	points* re =  (points*)malloc(sizeof(points)+(len*sizeof(point)));
	re->length = len;
	
	int i;
	if(flag == 0)
	{
	 for(i=0;i<len;i++)
	 {
		re->list[i].x = p[i].x;
		re->list[i].y = p[i].y;
		re->list[i].id = -1;
		re->list[i].distance = 0.0;
	 }
    }
    else
    {
     for(i=0;i<len;i++)
	 {
		re->list[i].x = p[i].x;
		re->list[i].y = p[i].y;
		re->list[i].id = getId(idList);
		re->list[i].distance = 0.0;
	 } 
    	
	}
	
	return re;
}


double distanceAB(point a, point b)
{
	double x = (a.x-b.x);
	double y = (a.y-b.y);
	return sqrt((x*x)+(y*y));
}


int tracking(points* past,  points* current, idNodeList* idList,heapTable* table,double min, double max)
{
	int i,j;
	heapNode data;
	for(i = 0; i < past->length; i++)
	{
		
		for(j=0; j< current->length; j++)
		{
			 current->list[j].distance = distanceAB(past->list[i],current->list[j]);
			
			
			 if((min < current->list[j].distance)&&(current->list[j].distance < max))
			 {
			 	heapNode node = {current->list[j].distance,j};
				heapInsert(table,i,node);
		    
		     }
		     
		     
		}
		heapDelete(table,i,&data);
		if(data.index != -1)
		{
		
		 if(current->list[data.index].id == -1)
		 {
			current->list[data.index].id = past->list[i].id;
			current->list[data.index].distance = data.distance;
		 }
		 else
		 {
			
		 } 
		 
	    }
	    else
	    {
	    	
		}
		
	}
	
}


