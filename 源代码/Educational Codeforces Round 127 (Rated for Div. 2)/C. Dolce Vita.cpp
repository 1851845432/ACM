#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
ll a[N];
int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		ll sum = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {
			sum += a[i];
			if (sum > k)break;
			ans += (k - sum) / i + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
