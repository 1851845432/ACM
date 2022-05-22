#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int s[1100],cas=1;
double dp[1100];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(dp,0,sizeof(dp));
	
		for(int i=1;i<=n;i++) cin>>s[i];
//		dp[1]=s[1];
	//根据递推关系由后往前推 
		for(int i=n;i>=1;i--){
			dp[i]=s[i];
			int x;
			x=min(6,n-i);
			 for(int j=i+1;j<=i+6 &&j<=n;j++){
			 	dp[i]+=dp[j]/x;
			 }
		}
		printf("Case %d: %.7lf\n",cas++,dp[1]);
	}
	
	return 0;
}
