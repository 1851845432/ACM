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
	printf("������ÿ�Ŀ��ѧ�֣�"); 
	scanf("%lf",&credit);
	printf("������ѧ��������");
	scanf("%d",&N); 
	readin(m,N);
	average=product(m,N);
	sortA(b,N);
	printf("ƽ������Ϊ��%.2f\n",average);
	printf("ѧ������󣬽�����£�"); 
	for(i=0;i<N;i++){
		printf("%.2f\t",b[i]);
	}
	
	return 0;
} 
