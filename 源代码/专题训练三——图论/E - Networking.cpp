#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
#define IL inline
using namespace std;
//prim算法的板子题 
int p[100][100], v[100], d[100];
const int inf = 1e9;
int n,m;
int  prim() {
	int sum = 0;
	memset(v, 0, sizeof(v));
	for (int i = 1; i <= n; i++)d[i] = inf;
	d[1] = 0;
	while (1) {
		int minn = inf, u = -1;
		for (int i = 1; i <= n; i++) {
			if (!v[i] && d[i] < minn) {
				minn = d[i];
				u = i;
			}
		}
		if (u == -1)break;
		v[u] = 1;
		sum += d[u];
		for (int i = 1; i <= n; i++) {
			if (!v[i] && d[i] > p[u][i]) {
				d[i] = p[u][i];
			}
		}
	}
	return sum;
}
int main() {

	while (~scanf("%d%d", &n,&m) && n) {
		if (!m) {cout << 0 << endl;continue;}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				p[i][j] = inf;
			}
		}
		while (m--) {
			int x, y, l;
			scanf("%d%d%d", &x, &y, &l);
			p[x][y] = min(p[x][y], l);
			p[y][x] = min(p[y][x], l);
		}
		cout << prim() << endl;
	}

	return 0;
}


