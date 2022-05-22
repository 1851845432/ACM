#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
using namespace std;
const double eps = 1e-6;
const int N = 4e4 + 10;
const int mod = 1e9 + 7;
int dp[N] = {1};
void init() {
	for (int i = 1; i <= N; ++i) {
		string s = to_string(i);
		if (s != string(s.rbegin(), s.rend()))
			continue;
		for (int j = i; j <= N; ++j)
			dp[j] = (dp[j] + dp[j - i]) % mod;
	}
}
int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	init();
	while (t--) {
		int n;
		cin >> n;
		printf("%d\n", dp[n]);
	}
	return 0;
}
