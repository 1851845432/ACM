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
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
ll lose[N], win[N], use[N];
ll dp[N];
int main() {
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> lose[i] >> win[i] >> use[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = x; j >= use[i]; j--) {
			dp[j] = max(dp[j] + lose[i], dp[j - use[i]] + win[i]);
		}
		for (int j = use[i] - 1; j >= 0; j--) {
			dp[j] += lose[i]; //所以打不过的情况也要全部记录
		}
	}
	cout << dp[x] * 5 * 1LL << endl;
	return 0;
}
