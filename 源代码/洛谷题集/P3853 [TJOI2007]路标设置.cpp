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
int d, n, k;
int a[N];
bool f(int x) {
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] - a[i - 1] > x) {
			cnt += (a[i] - a[i - 1]) / x;
			if ((a[i] - a[i - 1]) % x == 0)cnt--;
			if (cnt > k)return 0;
		}
	}
	return 1;
}
int main() {
//  freopen("in.txt", "r", stdin);
	cin >> d >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	int l = 0, r = d;
	while (l <= r) {
		int mid = l + r >> 1;
		if (f(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
