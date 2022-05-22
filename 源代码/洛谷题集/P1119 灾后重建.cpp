#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define ll long long
#define endl "\n"
#define  P pair<int,int>
using namespace std;
using namespace std;
const double eps = 1e-6;
const int N = 200 + 10;
const int mod = 1e9 + 7;
int n, m, x, y, tt;
int t[N];
int p[N][N];
inline int rd() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
inline void updade(int k) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
		}
	}
}
int main() {
//  freopen("in.txt", "r", stdin);
	cin >> n >> m;
	memset(p,INF,sizeof(p));
	for (int i = 0; i < n; i++)t[i] = rd(),p[i][i]=0;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		a = rd();
		b = rd();
		c = rd();
		p[a][b] = p[b][a] = c;
	}
	int q;
	q = rd();
	int cnt = 0;
	while (q--) {
		x = rd(), y = rd(), tt = rd();
		while (t[cnt] <= tt && cnt < n) {
			updade(cnt);
			cnt++;
		}
		if (t[x] > tt || t[y] > tt || p[x][y] == INF) {
			printf("-1\n");
		} else {
			printf("%d\n", p[x][y]);
		}
	}
	return 0;
}
