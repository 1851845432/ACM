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
int a[N][N];
int n, m;
ll ans = 0;
void f(int x, int y, int dx, int dy) {
	if (x <= 0 || y <= 0 || x > n || y > m)return ;
	ans += a[x][y];
	f(x + dx, y + dy,dx,dy);
}
int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		ll  maxx = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				ans = 0;
				f(i, j, 1, 1);
				f(i+1, j-1, 1, -1);
				f(i-1, j+1, -1, 1);
				f(i-1, j-1, -1, -1);
				maxx = max(maxx, ans);
			}
		}
		cout << maxx << endl;
	}
	return 0;
}
