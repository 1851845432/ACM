#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int mod=1e9+7;


int main(){
//	freopen("in.txt","r",stdin);
	int a,b;
	cin>>a>>b;
	int n=a+b;
	ll sum=1;
	for(int i=1;i<=n;i++){
		sum*=i;
	}
	cout<<sum<<endl;

	return 0;
}
