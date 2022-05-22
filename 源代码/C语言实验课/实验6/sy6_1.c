#include<stdio.h>
void readin(int *p,int n);
void sortA(float *b, int n);
float product(int a[],int n);
int  m[1000];
double credit;
int main(){
	int i;
	int N=3;
	float average=0;
	float b[1000];
	printf("请输入该科目的学分："); 
	scanf("%lf",&credit);
	printf("请输入学生人数：");
	scanf("%d",&N); 
	readin(m,N);
	average=product(m,N);
	sortA(b,N);
	printf("平均分数为：%.2f\n",average);
	printf("学分排序后，结果如下："); 
	for(i=0;i<N;i++){
		printf("%.2f\t",b[i]);
	}
	
	return 0;
} 
