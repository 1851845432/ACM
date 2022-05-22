#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5;
int dp[N],h[N];
int main(){
	int C,H;
	cin>>C>>H;
	for(int i=0;i<H;i++){
		cin>>h[i];
	}
	for(int i=0;i<H;i++){
		for(int j=C;j>=h[i];j--){
			dp[j]=max(dp[j],dp[j-h[i]]+h[i]);
		}
	}
	cout<<dp[C]<<endl;
	return 0;
}
