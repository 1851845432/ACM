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
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		ll b, d2, nb, c, d3, nc;
		cin >> b >> d2 >> nb >> c >> d3 >> nc;
		ll bn, cn;
		bn = b + d2 * (nb - 1);
		cn = c + d3 * (nc - 1);
		if (c < b || bn < cn)puts("0");
		else if ((b - c) % d2 || d3 % d2)puts("0");
		else if (c - d3 < b || cn + d3 > bn)puts("-1");
		else {
			ll ans = 0;
			for (ll i = 1; i * i <= d3; i++) {
				if (d3 % i == 0) {
//					cout << lcm(d2, i) << endl;
					if (lcm(i, d2) == d3) {
						ans += (d3 / i) * (d3 / i);
						ans %= mod;
					}
					if (d3 /  i != i && lcm(d3 / i, d2) == d3) {
						ans += (d3 / (d3 / i)) * (d3 / (d3 / i));
						ans %= mod;
					}
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
