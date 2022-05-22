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
int t[N], a[N], b[N];
int n;
void add(int x) {
	for (; x <= n; x += x & -x)t[x]++;
}
ll ask(int x) {
	ll sum = 0;
	for (; x; x -= x & -x)sum += t[x];
	return sum;
}
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = lower_bound(b + 1, b + n + 1, a[i]) - b;
		add(l);
		ans += i - ask(l);
	}
	cout << ans << endl;
	return 0;
}
