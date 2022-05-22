#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 1e9
#define ll long long
#define endl "\n"
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
ll p[N], d[N];
ll s[N];
int main() {
//	freopen("in.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)scanf("%lld", p + i), s[i] = s[i - 1] + p[i];
	for (int i = 1; i <= m; i++)scanf("%lld", d + i);
	s[n + 1] = s[n];
	d[0] = -INF;
	d[m + 1] = INF;
	m++;
	ll ans = 0;
	sort(d + 1, d + 1 + m);
	for (int i = 1; i <= n; i++) {
		int x = lower_bound(d + 1, d + m + 1, (i - 1) * 100) - d;
		int y = d[x - 1];
		x = d[x];
		if (x == i * 100 - 100 || y == i * 100 - 100)continue;
		int len = (x - y - 1) / 200;
		int z = min({ n, i + len, (x + 99) / 100 });
		ans = max(ans, s[z] - s[i - 1]);
	}
	cout << ans << endl;
	return 0;
}
