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
ll ksm(ll a, ll n) {
	ll ans = 1;
	while (n) {
		if (n & 1)ans = ans * a;
		a = (a * a);
		n >>= 1;
	}
	return ans;
}
int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		if (b.size() == 1 && b[0] == 'a') {
			cout << 1 << endl;
		} else {
			unordered_map<char, int> m;
			int ans = 0;
			for (auto x : b) {
				m[x]++;
			}
			if (m['a']) {
				cout << -1 << endl;
			} else {
				cout << ksm(2ll, 1ll * a.size()) << endl;
			}
		}
	}
	return 0;
}
