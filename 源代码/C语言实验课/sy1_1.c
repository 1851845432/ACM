#include<stdio.h>
int main()
{
	double fh, mh;
	printf("��ֱ����븸�׺�ĸ�׵����(�ÿո����)��");
	scanf("%lf%lf",&fh,&mh);
	char sex, sports, diet;
		printf("�������Ա�����ΪM��Ů��ΪF):");
		getchar();
		sex=getchar();
		printf("�Ƿ�ϲ������ѵ����Y or N����");
			sports=getchar();
			getchar ();
		printf("�Ƿ������õ�������ʳϰ�ߣ�Y or N����");
			diet=getchar();
			getchar();
	double H;
	if (sex == 'F')
	{
		H = (fh * 0.923 + mh) / 2;
	}
	else if (sex == 'M')
	{
		H = (fh + mh) * 0.54;
	}
	if (sports == 'Y')
		H = H * 1.02;
	if (diet == 'Y')
		H =  H * 1.015;
		printf("Ԥ������Ϊ��%.2lf\n",H);


	return 0;
}
