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
int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n, k, x;
		cin >> n >> k;
		map<int, int> m;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x);
			m[x]++;
			m[x - 1] += 0;
		}
		int l = 0, r = -1, last = -1;
		for (auto [a, b] : m) {
			if (b < k){last=-1;continue;}
			if (last == -1)last = a;
			if ((a - last) > (r - l))l = last, r = a;
		}
		if (r == -1)cout << -1 << endl;
		else cout << l << " " << r << endl;
	}
	return 0;
}
