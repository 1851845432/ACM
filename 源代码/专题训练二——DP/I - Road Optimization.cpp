#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[550], b[550];
int dp[550][550];
int main() {
	int n, l, k;
	cin >> n >> l >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	memset(dp, 0x3f, sizeof(dp));
	dp[1][1] = 0;
	a[n + 1] = l;
	//dp[i][j]表示选到第i个位置，选了j个速度时的，时间的最小值 
	for (int i = 2; i <= n + 1; i++) {
		for (int j = 1; j <= i; j++) {
			for (int x = 1; x < i; x++) {//遍历所以可能的端点 
				dp[i][j] = min(dp[i][j], dp[x][j - 1] + (a[i] - a[x]) * b[x]);
			}
		}
	}
	int minn = 1e9 + 10;
	for (int i = 0; i <= k; i++) minn = min(minn, dp[n + 1][n + 1 - i]);
	cout << minn << endl;
	return 0;
}
