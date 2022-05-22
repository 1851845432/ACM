#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e4+10;
int gcd(int x,int y){
	if(y==0)return x;
	gcd(y,x%y);	
}
int main(){
		int a,b,c,d;
		scanf("%d/%d",&a,&b);
		scanf("%d/%d",&c,&d);
	
		int x=a*c/gcd(a*c,b*d);
		int y=b*d/gcd(a*c,b*d);
		cout<<y<<' '<<x<<endl;
	
	
	return 0;
}
