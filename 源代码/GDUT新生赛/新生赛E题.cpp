#include<iostream>
using namespace std;
const int mod=1e9+7;
int main(){
	int T;
	cin>>T;
	while(T--){
		long long n;
		cin>>n;
		long long  x=n-2;
		long long y=x*(x-1)/2;
		cout<<y%mod<<endl;
	} 
	
	return 0;
}
