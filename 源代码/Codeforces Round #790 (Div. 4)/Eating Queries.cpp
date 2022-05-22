#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int a[N];
int n, x;
int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int q;
		cin >> n >> q;
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1, greater<int>());
		for (int i = 1; i <= n; i++)a[i] += a[i - 1];
		while (q--) {
			int k;
			cin >> k;
			int sum = lower_bound(a + 1, a + 1 + n, k) - a;
			if (sum > n)sum = -1;
			cout << sum << endl;
		}
	}
	return 0;
}
