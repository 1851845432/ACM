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
	printf("������¼���ѧ������ >> ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		stu* p=(stu*)malloc(sizeof(stu));
		p->next=NULL;
		printf("������ѧ������ >> ");
		scanf("%s",p->name);
		getchar();
		printf("������ѧ���Ա�(M or W) >> ");
		scanf("%c",&p->sex);
		getchar();
		printf("������ѧ���ĳ�������(�����շֱ��Կո����) >> ");
		scanf("%d%d%d",&p->birth.year,&p->birth.month,&p->birth.day);
		printf("��%dλѧ����Ϣ��¼����ϣ�\n",i+1);
		p->next =headNode->next;
		headNode->next = p;
	}
  	x=findOldest(headNode);
  	printf("����������%s",x->name);
	return 0;
}
//�Ƚ����������С
int compare(stu x,stu y) //���x�������y�򷵻�1
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
//�ҳ���������ѧ���������������ߵ�����
stu* findOldest(stu*headNode)
{
	stu* p,*s,*m;
	for(p=headNode,s=headNode->next;s;p=p->next,s=s->next)
	{
		m=compare(*p,*s)?p:s;
	}
return m;

}
