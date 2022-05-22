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
const int N = 3e4 + 10;
int f[N];//记录父节点 
int _find(int x) {
	if (x != f[x]) f[x] = _find(f[x]);
	return f[x];
}
void teget(int x, int y) {
	x = _find(x);
	y = _find(y);
	if (x != y)f[x] = y;
}

int main() {
	int n, m;
	while (~scanf("%d%d", &n, &m)) {
		if (n == 0 && m == 0) {
			return 0;
		}
		for (int i = 0; i <= n; i++)f[i] = i;//初始化 

		for (int i = 1; i <= m; i++) {
			int a, b, k;
			cin >> k;//社团人数 
			for (int j = 0; j < k; j++) {
				if (j == 0)cin >> a;//已输入的第一个人作为每个连通块的根结点 
				else {
					cin >> b;
					teget(a, b);//合并根结点所在的集合 
				}

			}

		}
		int ans = 1;
		for (int i = 1; i <= n; i++) {//暴力遍历与0结点所在集合的个数 
			if (_find(i) == _find(0))ans++;
		}
		cout << ans << endl;
	}

	return 0;
}


