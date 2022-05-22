#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int mod=1e9+7;
#define ll long long 

int main(){
//	freopen("in.txt","r",stdin);
	int a[10];
	int v[10][10]={0};
	for(int i=1;i<=6;i++){
		cin>>a[i];
		v[i][a[i]]=1;
	}
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=6;j++){
			for(int k=6;k>=1;k--){
				if(!v[j][k]){
					v[j][k]=1;
					a[j]=k;
					break;
				} 
			}
		}
	}
	for(int i=1;i<=6;i++){
		cout<<a[i];
		if(i!=6)cout<<" ";
	}
	

	return 0;
}
