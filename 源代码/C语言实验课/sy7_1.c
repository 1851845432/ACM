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
	printf("a的地址：%p，b的地址：%p\n",&a,&b);
	printf("p1的值：%p，p2的值：%p\n",p1,p2);
	printf("p1的地址：%p，p2的地址：%p\n",&p1,&p2);

	return 0;
}
