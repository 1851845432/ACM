#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#define X first
#define Y second
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int a[N], b[N];
int t[N];
int n;
ll ans;
void add(int x, int k) {
	for (; x <= n; x += x & -x)t[x] += k;
}
ll ask(int x) {
	ll sum = 0;
	for (; x; x -= x & -x)sum += t[x];
	return sum;
}
int main() {
	IOS
	int o;
	cin >> o;
	while (o--) {
		memset(t,0,sizeof(t));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			a[x] = i;
		}
		ans = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			add(a[x], 1);
			ans += i - ask(a[x]);
		}
		cout << ans << endl;
	}
	return 0;
}
