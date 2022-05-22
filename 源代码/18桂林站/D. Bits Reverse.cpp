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
#define INF 0x3f3f3f3f
#define ll long long
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define forr(x) for(int i=1;i<=x;i++)
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int main() {
//  freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	for (int  tt = 1 ; tt <= t; tt++) {
		ll x, y;
		cin >> x >> y;
		ll ans = 0;
		int a[65] = {0}, b[65] = {0};
		for (int i = 0; i < 64; i++) {
			if (x & (1ll << i)) {
				a[i] = 1;
			}
			if (y & (1ll << i)) {
				b[i] = 1;
			}
		}
		vector<int> aa, bb;
		for (int i = 0; i < 64; i += 2) {
			if (a[i])aa.push_back(i);
			if (b[i])bb.push_back(i);
		}
		if (aa.size() != bb.size()) {
			ans = -1;
			printf("Case %d: %d\n", tt, ans);
			continue;
		}
		for (int i = 0; i < aa.size(); i++) {
			ans += (abs(aa[i] - bb[i]) / 2);
		}
		aa.clear(), bb.clear();
		for (int i = 1; i < 64; i += 2) {
			if (a[i])aa.push_back(i);
			if (b[i])bb.push_back(i);
		}
		if (aa.size() != bb.size()) {
			ans = -1;
			printf("Case %d: %d\n", tt, ans);
			continue;
		}
		for (int i = 0; i < aa.size(); i++) {
			ans += (abs(aa[i] - bb[i]) / 2);
		}
		printf("Case %d: %lld\n", tt, ans);
	}
	return 0;
}
