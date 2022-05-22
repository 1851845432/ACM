#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
using namespace std;
const double eps = 1e-6;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n, m, p;
int a[N];
struct tree {
	int l, r;
	ll sum, lazy, mul; //lazy为加法标记，mul为乘法标记
} t[5 * N];
inline void update(int x) { //维护区间和
	t[x].sum = (t[x << 1].sum + t[x << 1 | 1].sum) % p;
}
inline void lazy(int node) { //维护懒惰标记，先乘后加
	ll lazy = t[node].lazy, mul = t[node].mul;
	int l = node << 1, r = node << 1 | 1; //左右儿子结点
//根据优先度 儿子的值=此刻儿子的值*爸爸的乘法mul+儿子的区间长度*爸爸的加法lazy
	t[l].sum = (t[l].sum * mul + lazy * (t[l].r - t[l].l + 1)) % p;
	t[r].sum = (t[r].sum * mul + lazy * (t[r].r - t[r].l + 1)) % p;
//更新子节点加法标记，注意需要先乘上乘法标记在加
	t[l].lazy = (t[l].lazy * mul + lazy) % p;
	t[r].lazy = (t[r].lazy * mul + lazy) % p;
//更新子节点乘法标记
	t[l].mul = (t[l].mul * mul) % p;
	t[r].mul = (t[r].mul * mul) % p;
//更新父节点的标记
	t[node].lazy = 0;
	t[node].mul = 1;
}
void build(int node, int l, int r) { //建树
	t[node].l = l, t[node].r = r;
//初始化懒惰标记 
	t[node].mul = 1;
	t[node].lazy = 0;
	if (l == r) {
		t[node].sum = a[l] % p;
		return ;
	}
	int mid = (l + r) >> 1;
	build(node << 1, l, mid);
	build(node << 1 | 1, mid + 1, r);
	update(node);
}
void mul(int node, int x, int y, int k) { //区间乘法
	if (x <= t[node].l && y >= t[node].r) {
	//注意区间乘法时，加法标记也需要乘k
		t[node].sum = (t[node].sum * k) % p;
		t[node].mul = (t[node].mul * k) % p;
		t[node].lazy = (t[node].lazy * k) % p;
		return ;
	}
	lazy(node);
	int mid = (t[node].l + t[node].r) >> 1;
	if (x <= mid)mul(node << 1, x, y, k);
	if (y > mid)mul(node << 1 | 1, x, y, k);
	update(node);
}
void add(int node, int x, int y, int k) { //区间加法
	if (x <= t[node].l && y >= t[node].r) {
		t[node].sum = (t[node].sum + (t[node].r - t[node].l + 1) * k) % p;
		t[node].lazy = (t[node].lazy + k) % p;
		return ;
	}
	lazy(node);
	int mid = (t[node].l + t[node].r ) >> 1;
	if (x <= mid)add(node << 1, x, y, k);
	if (y > mid)add(node << 1 | 1, x, y, k);
	update(node);
}
ll ask(int node, int x, int y) { //区间查询
	if (x <= t[node].l && y >= t[node].r) {
		return t[node].sum;
	}
	lazy(node);
	ll ans = 0;
	int mid = (t[node].l + t[node].r) >> 1;
	if (x <= mid)ans = (ans + ask(node << 1, x, y)) % p;
	if (y > mid)ans = (ans + ask(node << 1 | 1, x, y)) % p;
	return ans;
}
//void dfs() {
//	for (int i = 1; i <= n * 2; i++) {
//		printf("t[%d] [%d,%d] sum=%lld lazy=%lld mul=%lld\n", i, t[i].l, t[i].r, t[i].sum, t[i].lazy, t[i].mul);
//	}
//}
int main() {
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++)cin >> a[i];
	build(1, 1, n);
//	dfs();
	while (m--) {
		int x, y, k, key;
		scanf("%d", &key);
		if (key == 1) {
			scanf("%d%d%d", &x, &y, &k);
			mul(1, x, y, k);
//			dfs();
		} else if (key == 2) {
			scanf("%d%d%d", &x, &y, &k);
			add(1, x, y, k);
//			dfs();
		} else {
			scanf("%d%d", &x, &y);
			cout << ask(1, x, y) << endl;
		}
	}
	return 0;
}
