#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
int main() {
//	freopen("in.txt", "r", stdin);
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	vector<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j <= n and s[j] == s[i])j++;
		if (j - i >= 3 && j != n) q.push_back({i, j - 1});
		i = j - 1;
	}
	if (!q.size()) {
		cout << 0 << endl;
	} else if (q[0].first == 1 && q[0].second == n) {
		cout << n / 3 << endl;
		for (int i = 2; i <= n; i += 3) {
			cout << i << " ";
		}
		cout << endl;
	} else {
		cout << q.size() << endl;
		for (auto [x, y] : q) {
			cout<<x<<" "<<y<<endl;
			for (int i = x + 2; i <= y; i += 2) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
