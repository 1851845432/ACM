#include<stdio.h>
int main()
{
	int a = 0;
	int cont90 = 0;
	int cont50 = 0;
	int cont = 0;
	float pj = 0;
	int sum = 0;
	printf("����������(����-1ʱ������:\n");
	while (1) {
		scanf("%d", &a);
		if (a == -1)break;
		else if (a == 90)cont90++;
		else if (a >= 50 && a <= 60)cont50++;
		sum += a;
		cont++;

	}
	pj = 1.0*sum / cont;
	printf("90�ĸ���Ϊ��%d\n", cont90);
	printf("��50��60֮������У�%d\n", cont50);
	printf("�����ݵ�ƽ��ֵΪ��%f\n",pj );

	return 0;
}
