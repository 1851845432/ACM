#include<iostream>
using namespace std;
const int N=1e5+10;
int a[N],s[N];
void cf(int L,int R,int d){
	s[L]+=d;
	s[R+1]-=d;
	for(int i=1;i<=n;i++){
		a[i]=s[i]+a[i-1];
	}
}
int sum(int x){
	int ans=0;
	if(x==1)return 0;
	for(int i=1;i<=x/2;i++){
		if(x%i==0){
			ans+=2;
		}
	}
	return x-ans;
}



int main(){
	int n,m;
	cin>>n>>m;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]-a[i-1];
	}
	while(m--){
		
		
	}
	
	return 0;
}
