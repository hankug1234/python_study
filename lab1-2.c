#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student_grade {float grade; char sname[20];
}; //�л��� ���� �� �̸��� ��� ���� ü 

typedef struct student_grade info;

info* allocate_info(char name[20], float g) // �л��� �̸��� ������ �޾Ƽ� �������� �޸𸮸� �Ҵ��ϰ� ���� ���� ���� �������� �ּҸ� ��ȯ�Ѵ� 
{
	info* box = NULL;
	box = (info*)malloc(sizeof(info));
	
	strncpy(box->sname , name,20);
	box->grade = g;
	
	return box;
}

float avg(info** a , int num)// info�ּ� �迭�� �� �迭�� ���̸� ������ �л����� ������ ����� ���Ѵ� 
{
	int i;
	float total = 0;
	for(i = 0; i<num ; i++)
	{
		total += a[i]->grade;
	}
	
	
	
	return total/5;
}



int check(float g)// �л��� ������ ������ ���� �ȿ� �ִ��� �Ǵ����� �����ϴٸ� 1�� �ƴϸ� 0�� ��ȯ�Ѵ� 
{
	if(g>0 && g<=4.5)
	return 1;
	else 
	return 0;
}

int* find(info** a , int b )// ��ռ������� ������ ���� �л����� �迭 �ε��� ��ȣ�� int �� �迭�� ���� �Ҵ����� �� �ּҸ� ��ȯ �Ѵ� 
{
	float avgg = avg(a , b);
	int i,fs = 0;
	int* c = (int*)malloc(sizeof(int)*6);
	for(i = 0 ; i< b ; i++)
	{
		if(a[i]->grade > avgg)
		{   
			c[fs] = i;
			fs +=1;
		}
	}
	c[5] = fs;
	return c;
}

int main(void)
{
	info* list_student[5]; 
	char n[20];// �л� �̸� ���� 
	float grade;// ���� ���� 
	int i;
	int* dlist; // find�� ��ȯ ���� ��� ���� 
	
	for(i = 0; i< 5 ; i++)
	{
	
	puts("please enter student name:");
	scanf("%s",n);
	
	
	
	
	while(getchar() != '\n');//���۸� ����ֱ� ���ؼ� 
	
	puts("please enter student grade");
	scanf("%f",&grade);
	
	while(check(grade) == 0)// ������ Ÿ�缺 �� üũ �ϰ� Ÿ������ ������ �ٽ� �Է� �ؾ� �Ѵ� 
	{
		    puts("error please enter again");
			puts("please enter student grade");
	        scanf("%f",&grade);
	}
	
	
	while(getchar() != '\n');
	
	list_student[i] = allocate_info(n,grade);
    }
    
    
    dlist = find(list_student,5);
	puts("student name that take grade above average");
	for(i = 0; i< dlist[5] ; i++)
	{
		printf("student_name:%s\n",list_student[dlist[i]]->sname);
		printf("student_grade:%f\n",list_student[dlist[i]]->grade);
	}
	printf("\ntotal_avg:%f\n",avg(list_student,5));
	 
	 free(dlist);
	 for(i = 0;i<5;i++)
	 {
	 	free(list_student[i]);
	 }
	return 0;
}
