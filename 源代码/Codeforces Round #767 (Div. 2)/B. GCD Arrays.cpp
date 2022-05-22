#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int l,r,k;
		cin>>l>>r>>k;
		if(l==r){
			if(l!=1)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
			continue;
		}
		int j=(r-l)/2;
		if(l&1 || r&1) j+=1;
		if(j<=k){
			cout<<"YES"<<endl;
			continue;
		}
		else{
			cout<<"NO"<<endl;
			continue;
		}
	}
	return 0;
}
