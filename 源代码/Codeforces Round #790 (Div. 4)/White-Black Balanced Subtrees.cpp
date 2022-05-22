#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e4 + 10;
const int mod = 1e9 + 7;
int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> f(n + 1);
		for (int i = 2; i <= n; i++)cin >> f[i];
		string s;
		cin >> s;
		s = " " + s;
		vector<int> w(n + 1);
		for (int i = 1; i <= n; i++) {
			if (s[i] == 'W')w[i] = 1;
			else w[i] = -1;
		}
		int ans = 0;
		for (int i = n; i >= 1; i--) {
			if (w[i] == 0)ans++;
			w[f[i]] += w[i];
		}
		cout << ans << endl;
	}
	return 0;
}
