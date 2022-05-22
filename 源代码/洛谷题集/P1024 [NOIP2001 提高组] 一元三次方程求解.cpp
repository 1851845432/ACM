#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
double a,b,c,d;
double fc(double i){
	return a*pow(i,3)+b*pow(i,2)+c*i+d;
}
int main(){

	int sum=0;
	cin>>a>>b>>c>>d;
	for(int i=-100;i<100;i++){
		double l=i;
		double r=i+1;
		double f1=fc(l);
		double f2=fc(r);
		if(!f1){
			printf("%.2lf ",l);
			sum++;
		}
		if(f1*f2<0){
			while(r-l>=0.001){
				double mid=(l+r)/2;
				if(fc(l)*fc(mid)<0){
					r=mid;
				}
				else{
					l=mid;
				}
			}
			printf("%.2lf ",r);
			sum++;	
		}
		if(sum==3)break;
		
	}
	return 0;
}
