#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#define X first
#define Y second
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=5e3+10;
const int mod=1e9+7;
int a[N],b[N];
int dp[N][N];
int main() {
	int n;
	cin>>n;
	double x;
	int y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		a[i]=(int)x*10000;
		b[i]=y;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=10000;j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-a[i]]+b[i]);
		}
	}
	cout<<dp[n][10000]<<endl;
	
	
	
	

	return 0;
}



