#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Date
{
	int year;
	int month;
	int day;
} date;

typedef struct student
{
	char name[20];
	char sex;
	date birth;
	struct student * next;
} stu;

stu* findOldest(stu*p);
int compare(stu x,stu y);

int main()
{
	stu* x;
	stu* headNode=(stu *)malloc(sizeof(stu));
	headNode->next=NULL;
	int n,i;
	printf("请输入录入的学生人数 >> ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		stu* p=(stu*)malloc(sizeof(stu));
		p->next=NULL;
		printf("请输入学生姓名 >> ");
		scanf("%s",p->name);
		getchar();
		printf("请输入学生性别(M or W) >> ");
		scanf("%c",&p->sex);
		getchar();
		printf("请输入学生的出生年月(年月日分别以空格隔开) >> ");
		scanf("%d%d%d",&p->birth.year,&p->birth.month,&p->birth.day);
		printf("第%d位学生信息已录入完毕！\n",i+1);
		p->next =headNode->next;
		headNode->next = p;
	}
  	x=findOldest(headNode);
  	printf("年龄最大的是%s",x->name);
	return 0;
}
//比较两人年龄大小
int compare(stu x,stu y) //如果x年龄大于y则返回1
{
	if(x.birth.year==y.birth.year)
	{
		if(x.birth.month==y.birth.month)
		{
			return x.birth.month<y.birth.month;
		}
		return x.birth.month<y.birth.month;
	}
	return x.birth.year<y.birth.year;
}
//找出年龄最大的学生。输出年龄最大者的名字
stu* findOldest(stu*headNode)
{
	stu* p,*s,*m;
	for(p=headNode,s=headNode->next;s;p=p->next,s=s->next)
	{
		m=compare(*p,*s)?p:s;
	}
return m;

}
