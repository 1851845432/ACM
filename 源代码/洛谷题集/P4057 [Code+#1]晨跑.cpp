#include<bits/stdc++.h>
using namespace std;
unsigned long long gcd(long long  x,long long y){
		long long  z=x%y;
		while(z){
			x=y;
			y=z;
			z=x%y;
		}
		return y;
}
int main(){
	unsigned long long a,b,c;
cin>>a>>b>>c;
unsigned	long long  z=a/gcd(a,b)*b;
unsigned	long long  r=z/gcd(z,c)*c;
	cout<<r<<endl;
	return 0;
}
