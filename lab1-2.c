#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student_grade {float grade; char sname[20];
}; //학생의 성적 과 이름을 담는 구조 체 

typedef struct student_grade info;

info* allocate_info(char name[20], float g) // 학생의 이름과 성적을 받아서 동적으로 메모리를 할당하고 받은 변수 값을 저장한후 주소를 반환한다 
{
	info* box = NULL;
	box = (info*)malloc(sizeof(info));
	
	strncpy(box->sname , name,20);
	box->grade = g;
	
	return box;
}

float avg(info** a , int num)// info주소 배열과 그 배열의 길이를 받은후 학생들의 성적의 평균을 구한다 
{
	int i;
	float total = 0;
	for(i = 0; i<num ; i++)
	{
		total += a[i]->grade;
	}
	
	
	
	return total/5;
}



int check(float g)// 학생의 성적이 적절한 범위 안에 있는지 판단한후 적절하다면 1을 아니면 0을 반환한다 
{
	if(g>0 && g<=4.5)
	return 1;
	else 
	return 0;
}

int* find(info** a , int b )// 평균성적보다 성적이 좋은 학생들의 배열 인덱스 번호를 int 형 배열에 동적 할당한후 그 주소를 반환 한다 
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
	char n[20];// 학생 이름 변수 
	float grade;// 성적 변수 
	int i;
	int* dlist; // find의 반환 값을 담는 변수 
	
	for(i = 0; i< 5 ; i++)
	{
	
	puts("please enter student name:");
	scanf("%s",n);
	
	
	
	
	while(getchar() != '\n');//버퍼를 비워주기 위해서 
	
	puts("please enter student grade");
	scanf("%f",&grade);
	
	while(check(grade) == 0)// 성적의 타당성 을 체크 하고 타당하지 않으면 다시 입력 해야 한다 
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
