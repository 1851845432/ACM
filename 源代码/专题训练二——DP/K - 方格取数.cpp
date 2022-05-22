#include<iostream>
#include<cstdio>
using namespace std;
int dp[14][14][14][14],m[14][14];
int main(){
	int n;
	cin>>n;
	int x,y,z;
	while(1){
		cin>>x;
		if(x==0)break;
		cin>>y>>z;
		m[x][y]+=z;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int x=1;x<=n;x++){
				for(int y=1;y<=n;y++){
					dp[i][j][x][y]=max(max(dp[i-1][j][x-1][y],dp[i-1][j][x][y-1]),max(dp[i][j-1][x-1][y],dp[i][j-1][x][y-1]))+m[i][j]+m[x][y];
					if(i==x && j==y)dp[i][j][x][y]-=m[i][j];
				}
			}
		}
	}
	cout<<dp[n][n][n][n]<<endl;
	return 0;
} 
