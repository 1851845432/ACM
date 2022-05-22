#include<stdio.h>
int main()
{
	int a = 0;
	int cont90 = 0;
	int cont50 = 0;
	int cont = 0;
	float pj = 0;
	int sum = 0;
	printf("请输入数据(输入-1时结束）:\n");
	while (1) {
		scanf("%d", &a);
		if (a == -1)break;
		else if (a == 90)cont90++;
		else if (a >= 50 && a <= 60)cont50++;
		sum += a;
		cont++;

	}
	pj = 1.0*sum / cont;
	printf("90的个数为：%d\n", cont90);
	printf("在50到60之间的数有：%d\n", cont50);
	printf("该数据的平均值为：%f\n",pj );

	return 0;
}
