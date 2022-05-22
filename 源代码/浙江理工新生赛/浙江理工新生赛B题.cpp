#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N],s[N];
int n,m;
void cf(int l, int r, long long w){
	for(int i=l;i<=r;i++){
		a[i]&=w;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	while(m--){
		int l,r;
		long long w;
		cin>>l>>r>>w;
		cf(l,r,w);	
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	
	
}
