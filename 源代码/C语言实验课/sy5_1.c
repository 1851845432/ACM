#include<stdio.h>
#include<math.h>
	double x;
	int k;
	double sum;
	int fac(int n){
		if(n==1)return 1;
		return n*fac(n-1);
	}
void p(){
		int i;
		for(i=1;i<=k;i++){
			sum+=(pow(x,i+1)/fac(2*i-1));	
		}
		printf("%lf",sum);
}

int main(){
	scanf("%lf%d",&x,&k);
	p();
	
	
	return 0;
} 
