#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int inf = 1e8;
const int N = 5e3 + 10;
int s[N][N];//邻接矩阵存储图 
int v[N], d[N];//v为标记是否加入新的集合中，d表示为最小生成树的权值 
int n, m;
void prim() {
	//对标记重新初始化 
	memset(v, 0, sizeof(v));
	//初始化最小树的权值 
	for (int i = 1; i <= n; i++) d[i] = inf;
	d[1] = 0; //以1为根起点
	while (1) {
		int u = -1;
		int minn = inf;
		//遍历已选集合的所有出度中最小的边 
		for (int i = 1; i <= n; i++) {
			if (!v[i] && d[i] < minn) {
				minn = d[i];
				u = i;
			}
		}
		if (u == -1)break; //已找到所有结点
		v[u] = 1; //标记树的新节点
		//遍历更新新集合中相应权值的大小 
		for (int i = 1; i <= n; i++) {
			if (!v[i] && d[i] > s[u][i]) {
				d[i] = s[u][i];
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	//对邻接矩阵初始化
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			s[i][j] = inf;
		}
	}
	//防止重边的出现，保存最小值，并记录是否连通 
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		s[x][y] = min(s[x][y], z);
		s[y][x] = min(s[y][x], z);
		v[x] = v[y] = 1;
	}
	//如果未被标记则代表为连通输出orz 
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			cout << "orz" << endl;
			return 0;
		}
	}
	//prim算法求最小生成树 
	prim();
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] == inf) {//如果存在无法连通的情况，距离为inf 
			cout << "orz" << endl;
			return 0;
		}
		sum += d[i];
	}
	cout << sum << endl;

	return 0;
}
