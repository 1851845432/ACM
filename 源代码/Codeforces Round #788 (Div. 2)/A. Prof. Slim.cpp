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
int a[N], b[N];
int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			cnt += a[i] < 0;
			a[i] = abs(a[i]);
		}
		bool f = 0;
		for (int i = 1; i <= cnt; i++)a[i] *= -1;
		for (int i = 2; i <= n; i++) {
			if (a[i] < a[i - 1]) {
				f = 1;
				break;
			}
		}
		if (f)puts("NO");
		else puts("YES");
	}
	return 0;
}
