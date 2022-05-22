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
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int dp[55][1100];
int main() {
	int t;
	int ans = 0;
	cin >> t;
	for (int i = 1; i <= 1000; i++) {
		dp[1][i] = i - 1;
	}
	for (int i = 1; i <= 50; i++) {
		dp[i][1] = 0;
	}
	for (int i = 2; i <= 50; i++) { //枚举测试的手机数目
		for (int j = 2; j <= 1000; j++) {//枚举最大的压力值
		dp[i][j]=INF;
			for (int x = 1; x < j; x++) { //枚举可能折断的压力
				int t = max(dp[i][j - x], dp[i - 1][x]) + 1; //若x为折断的压力，则测试机型-1，若没断，则压力的可能值为[x+1,j-x];
				dp[i][j] = min(dp[i][j], t);
			}
		}
	}
	while (t--) {
		int p, m;
		cin >> p >> m;
		printf("Case %d: %d\n", ++ans, dp[p][m]);
	}
	return 0;
}
