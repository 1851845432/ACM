#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
using namespace std;
const double eps = 1e-6;
const int N = 5e4 + 10;
const int mod = 1e9 + 7;
int a[N];
int d, n, m;
bool C(int x) {
	int cnt = 0;
	int last = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (a[i] - a[last] < x) {
			cnt++;
		} else {
			last = i;
		}
		if (cnt > m) {
			return 0;
		}
	}
	return 1;
}
int main() {
//  freopen("in.txt", "r", stdin);
	cin >> d >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[n + 1] = d;
	int l = 0, r = d;
	int ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (C(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
