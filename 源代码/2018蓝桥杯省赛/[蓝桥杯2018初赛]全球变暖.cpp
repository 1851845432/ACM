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
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
char a[N][N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n;
bool f = 0;
void dfs(int x, int y) {
	a[x][y] = '@';
	bool fl = 0;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 1 && tx <= n && ty >= 1 && ty <= n && a[tx][ty] == '.') {
			fl = 1;
		}
	}
	if (!fl)f = 1;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 1 && tx <= n && ty >= 1 && ty <= n && a[tx][ty] == '#') {
			dfs(tx, ty);
		}
	}
}
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == '#') {
				dfs(i, j);
				ans++;
				if (f)cnt++;
				f = 0;
			}
		}
	}
	cout << ans-cnt << endl;
	return 0;
}
