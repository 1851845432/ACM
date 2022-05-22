#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define ll long long
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define forr(x) for(int i=1;i<=x;i++)
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 3e5 + 10;
const int mod = 1e9 + 7;
int a[N];
int n;
ll f(int x) {
	ll c1 = 0, c2 = 0;
	for (int i = 1; i <= n; i++) {
		c1 += (x - a[i]) & 1, c2 += (x - a[i]) >> 1;
	}
	if (c1 > c2) {
		return 2 * c1 - 1;
	} else {
		return  c1*2+(c2-c1)*2/3*2+(c2-c1)*2%3;
	}
}
int main() {
//  freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		int maxx = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			maxx = max(maxx, a[i]);
		}
		cout << min(f(maxx), f(maxx + 1)) << endl;
	}
	return 0;
}
