#include<stdio.h>
#include<string.h>

struct pet { char Pname[20]; int Page;
};

typedef struct pet Pet;

struct human { char name[20]; Pet list[3]; int petnum;
};

typedef struct human Human;

Human findOld(Human* a,int num)// Human 변수의 주소와 펫의 숫자 변수를 받은후 가장 나이가 많은 펫의 정보를 찾은후 그 정보를 새로운 Human 변수의 list 요소의 0번방에 저장한후 Human 변수를 반환한다  
{
	int max,i,count;
	Human b;
	max = a->list[0].Page;
	count = 0;
	for(i =1 ; i< num ; i++)
	{
		if(max<a->list[i].Page)
		{
			max = a->list[i].Page;
			count = i;
		}
		
	}
	strncpy(b.name , a->name,20);
	strncpy(b.list[0].Pname , a->list[count].Pname , 20);
	b.list[0].Page = a->list[count].Page;
	b.petnum = num;
	
	return b;
	
	
}

int main(void)
{char name[20];// 사람 이름 변수 
 int num,i,age;// 펫 숫자 카운트 펫 나이 변수 
 Human test; // 입력받은 변수를 저장하는 Human 변수 
 Human test2;//findOld 의 결과를 저장할 변수 
 
 
	puts("what is your name?");
	scanf("%s",name);
	
	strncpy(test.name , name, 20);
	
	while(getchar() != '\n');
	
	puts("how many pet do you have?");
	scanf("%d",&num);
	
	while(num>3 || num<0)// 펫 숫자 타당성 test 
	{
		while(getchar() != '\n');
	puts("pet number must between 0~3");
	puts("how many pet do you have?");
	scanf("%d",&num);	
	}
	
	test.petnum = num;
	
	for(i = 0;i<num;i++)
	{
		puts("please enter pet name");
		scanf("%s",name);
		strncpy(test.list[i].Pname , name , 20);
		
		while(getchar() != '\n');
		
		puts("please enter pet age");
		scanf("%d",&age);
		test.list[i].Page = age;
		
		while(getchar() != '\n');
	}
	
	 test2 = findOld(&test,num);
	
	puts("info");
	printf("human_name:");
	puts(test2.name);
	printf("pet_number:%d\n",test2.petnum);
	printf("pet_name:%s\n",test2.list[0].Pname);
	printf("pet_age:%d\n",test2.list[0].Page);
	
	return 0;
}
