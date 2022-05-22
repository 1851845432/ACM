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
int n, k;
int a[N];
bool f(int x) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += a[i] / x;
	}
	if (cnt >= k)return 1;
	else return 0;
}
int main() {
//  freopen("in.txt", "r", stdin);
	cin >> n >> k;
	ll sum = 0;
	for (int i = 1; i <= n; i++)cin >> a[i], sum += a[i];
	if (sum < k)puts("0");
	else {
		int l = 0, r = INF;
		int ans = 0;
		while (l <= r) {
			int mid = l + r >> 1;
			if (f(mid)) {
				ans = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
