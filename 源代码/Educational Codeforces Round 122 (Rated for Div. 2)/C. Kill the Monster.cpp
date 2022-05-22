#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int main() {
	int t;
	cin >> t;
	while (t--) {
		ll hc, dc, hm, dm, k, w, a;
		scanf("%lld%lld", &hc, &dc);
		scanf("%lld%lld", &hm, &dm);
		scanf("%lld%lld%lld", &k, &w, &a);
		bool flag = 1;
		for (int i = 0; i <= k; i++) {
			if ((hm-1) / (dc + i * w) <= (hc + (k - i)*a-1) / dm) {
				cout << "YES" << endl;
				flag = 0;
				break;
			}
		}
		if (flag)cout << "NO" << endl;
	}
	return 0;
}
