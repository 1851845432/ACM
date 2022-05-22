#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int x1,x2,p1,p2;
		cin>>x1>>p1;
		cin>>x2>>p2;
		int  sum1=0,sum2=0;
		int a1,a2;
		a1=x1;a2=x2;
			while(a1){
				sum1++;
				a1/=10;
			}
			while(a2){
				sum2++;
				a2/=10;
			}
		sum1+=p1;sum2+=p2;
		if(sum1>sum2){
			cout<<">"<<endl;
			continue;
		}
		else if(sum1<sum2){
			cout<<"<"<<endl;
			continue;
		}
		else{
			sum1-=p1;sum2-=p2;
			if(sum1<=7)x1*=pow(10,7-sum1); 
			if(sum2<=7)x2*=pow(10,7-sum2); 
			if(x1>x2)cout<<">"<<endl;
			else if(x1<x2)cout<<"<"<<endl;
			else if(x1==x2)cout<<"="<<endl;
			continue;
		}
		
	}
	
	
	return 0;
}
