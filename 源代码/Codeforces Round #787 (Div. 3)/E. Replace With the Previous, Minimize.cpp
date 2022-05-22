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
int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int v[30] = {0};
		for (auto &x : s) {
			while (x > 'a') {
				if (v[x-'a'])x--;
				else if (k) v[x-'a']++, k--, x--;
				else break;
			}
		}
		cout << s << endl;
	}
	return 0;
}
