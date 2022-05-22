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
const int N = 1e2 + 10;
const int mod = 1e9 + 7;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dp[N][N];
int a[N][N];
int n, m;
int dfs(int x, int y) {
	if (dp[x][y])return dp[x][y];
	dp[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty] < a[x][y]) {
				dfs(tx, ty);
				dp[x][y] = max(dp[x][y], dp[tx][ty] + 1);
		}
	}
	return dp[x][y];
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = max(ans, dfs(i, j));
		}
	}
	cout << ans << endl;
	return 0;
}
