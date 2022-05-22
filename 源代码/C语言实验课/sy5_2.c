#include<stdio.h>
#define N 5
char name[N][20];
int H[N];//身高cm 
float W[N];//体重kg 

void printStar(float *p,int n){
	int i,j;

	printf("name\t BMI\t \n");
	for(i=0;i<n;i++){
		printf("%s\t",name+i);
		for(j=0;j<(int)(p[i]+0.5);j++){
			printf("*");
		}
		printf("\n");
	}
	
}
double averBMI(float *p,int n ){
	int i=0;
	float average=0;
	for(i=0;i<n;i++){
		average+=p[i]/n;
	}
	return average;
	
}
int main(){
	int n;
	int i;
	float BMI[N];
	printf("请输入待测人数：");
	scanf("%d",&n);
	printf("请分别输入名字，身高（cm），体重（kg）（以空格隔开）\n"); 
	
	for( i=0;i<n;i++){
		scanf("%s",name+i);
		scanf("%d%f",&H[i],&W[i]);
		BMI[i]=W[i]/(H[i]/100.0)/(H[i]/100.0);
	}
	printStar(BMI,n);
	printf("平均BMI为：");
	printf("%lf\n",averBMI(BMI,n));

	
	return 0;
}
