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
int p[N], cnt;
vector<int> ans[N], s[N];
void dfs(int u, int f) {
	s[f].push_back(u);
	if (ans[u].empty()) {
		cnt++;
		return ;
	}
	dfs(ans[u][0], f);
	for (int i = 1; i < ans[u].size(); i++)dfs(ans[u][i], ans[u][i]);
}
int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int u;
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			ans[i].clear();
			s[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
			if (p[i] == i)u = i;
			else ans[p[i]].push_back(i);
		}
		dfs(u, u);
		cout << cnt << endl;
		for (int i = 1; i <= n; i++) {
			if (!s[i].empty()) {
				cout << s[i].size() << endl;
				for (auto x : s[i])cout << x << " ";
				cout << endl;
			}
		}
//		puts("");
	}
	return 0;
}
