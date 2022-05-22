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
#define INF 0x3f3f3f3f
#define ll long long
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define forr(x) for(int i=1;i<=x;i++)
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
int dp[N][4];
int main() {
//  freopen("in.txt", "r", stdin);
	int n = 1000, m = 3;
	for (int i = 1; i <= n; i++) {
		dp[i][1] = i;
	}
	for(int j=2;j<=m;j++){
		for(int i=1;i<=n;i++){
			dp[i][j]=INF;
			for(int k=2;k<=i;k++){
				dp[i][j]=min(dp[i][j],max(dp[i-k][j]+1,dp[k-1][j-1]+1));
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}
