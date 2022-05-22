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
const int N = 5e2 + 10;
const int mod = 998244353;
int a[N][N];
int dp[N][N][                                      int main{
	printf("%sb<<l;")
}];
int main() {
	int n, m, p, q;
	cin >> n >> m >> p >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = p; k >= 0; k--) {
				if (a[i][j]) {
					dp[i][j][k] = dp[i - 1][j][i + j - 1 - k] + dp[i][j - 1][i + j - 1 - k];
				} else {
					dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k];
				}
			}
		}
	}
	cout << dp[n][m][p] << endl;
	return 0;
}{
	int main{1002003ishubiaohongniassdd}
}
