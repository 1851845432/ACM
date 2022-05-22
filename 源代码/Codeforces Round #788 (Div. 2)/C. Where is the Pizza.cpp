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
int a[N], b[N], d[N], f[N];
bool  v[N], st[N];
int main() {
	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)scanf("%d", a + i), v[i] = 0, st[i] = 0;
		for (int i = 1; i <= n; i++)scanf("%d", b + i), f[a[i]] = b[i];
		for (int i = 1; i <= n; i++) {
			scanf("%d", d + i);
			if (d[i]) {
				st[a[i]] = st[b[i]] = 1;
			}
		}
		ll ans = 1;
		for (int i = 1; i <= n; i++) {
			if (!v[i]) {
				int cnt = 0;
				int fl = 0;
				int j = i;
				while (!v[j]) {
					v[j] = 1;
					cnt++;
					fl |= st[j];
					j = f[j];
				}
				if (cnt != 1 && !fl )ans = ans * 2ll % mod;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
