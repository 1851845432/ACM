#include<stdio.h>
int main()
{
	double fh, mh;
	printf("请分别输入父亲和母亲的身高(用空格隔开)：");
	scanf("%lf%lf",&fh,&mh);
	char sex, sports, diet;
		printf("请输入性别（男性为M，女性为F):");
		getchar();
		sex=getchar();
		printf("是否喜爱体育训练（Y or N）：");
			sports=getchar();
			getchar ();
		printf("是否有良好的卫生饮食习惯（Y or N）：");
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
		printf("预测的身高为：%.2lf\n",H);


	return 0;
}
