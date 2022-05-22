#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
using namespace std;
const double eps = 1e-6;
const int N = 1e2 + 10;
const int mod = 1e9 + 7;
ll a[N];
int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll last = 0;
		ll ans = 0;
		bool f = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", a + i);
		}
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		for (int i = n - 1; i >= 1; i--) {
			while (a[i] >= a[i + 1] && a[i] !=0) {
				ans++;
				a[i] >>= 1;
			}
			if(a[i]>=a[i+1]){
				f=1;break;
			}
		}
		if (f)cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}
