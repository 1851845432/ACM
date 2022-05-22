#include<iostream>
using namespace std;
const int N=2e5+10;
int a[N],s[N];
int main(){
	int n;
	int maxn=-999999;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)s[i]=a[i];
		else s[i]=max(s[i-1]+a[i],a[i]);
		maxn=max(maxn,s[i]);
	}
	cout<<maxn<<endl;
	return 0;
} 
