#include<stdio.h>

int main()
{
	int a,b,*p1,*p2,t;
	p1=&a;
	p2=&b;
	scanf("%d %d",p1,p2);
	printf("a=%d,b=%d\n",a,b);
	t=*p1;
	*p1=*p2;
	*p2=t;
	printf("a=%d,b=%d\n",a,b);
	printf("a�ĵ�ַ��%p��b�ĵ�ַ��%p\n",&a,&b);
	printf("p1��ֵ��%p��p2��ֵ��%p\n",p1,p2);
	printf("p1�ĵ�ַ��%p��p2�ĵ�ַ��%p\n",&p1,&p2);

	return 0;
}
