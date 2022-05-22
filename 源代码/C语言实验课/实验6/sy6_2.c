#include<stdio.h>
extern int m[1000];
extern double credit;
void readin(int *p,int n){
	int i=0;
	for(i=0;i<n;i++){
	printf("ÇëÊäÈë·ÖÊý£º");
	scanf("%d",p+i);
	} 
	return ;
}
float product(int a[],int n){
	int i=0;
	float sum=0.0;
	for(i=0;i<n;i++){
		sum+=a[i];
	}
	return sum/n;
}
void sortA(float *b, int n){
	int i,j;
	for(i=0;i<n;i++){
		b[i]=1.0*m[i]/100*credit;
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(b[i]>b[j]){
				float a=*(b+i);
				*(b+i)=*(b+j);
				*(b+j)=a;
			}
		}
	}
	
}
