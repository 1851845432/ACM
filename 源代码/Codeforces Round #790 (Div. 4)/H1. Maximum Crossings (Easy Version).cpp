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
int t[N];
int n;
void add(int x) {
	for (; x <= n; x += x & -x)t[x]++;
}
ll ask(int x) {
	ll ans = 0;
	for (; x; x -= x & -x)ans += t[x];
	return ans;
}
int main() {
	freopen("in.txt", "r", stdin);
	int o;
	cin >> o;
	while (o--) {
		cin >> n;
		ll ans = 0;
		memset(t, 0, sizeof(t));
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			add(x);
//			cout << ask(x - 1) << " ";
			ans += i - 1 - ask(x - 1);
		}
		cout << ans << endl;
	}
	return 0;
}
