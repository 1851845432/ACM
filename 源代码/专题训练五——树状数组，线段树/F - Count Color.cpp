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
int n, T, o;
struct tree {
	int l, r;
	int num, lazy;
} t[N << 2];
inline void update(int node) {
	t[node].num = (t[node << 1].num | t[node << 1 | 1].num);
}
void build(int node, int l, int r) {
	t[node].l = l, t[node].r = r;
	if (l == r) {
		t[node].num = 1 << 1;
		return ;
	}
	int mid = (l + r) >> 1;
	build(node << 1, l, mid);
	build(node << 1 | 1, mid + 1, r);
	update(node);
}
void lazy(int node) {
	if (t[node].lazy) {
		int l = node << 1, r = node << 1 | 1;
		t[l].num = 1 << t[node].lazy;
		t[r].num = 1 << t[node].lazy;
		t[l].lazy = t[node].lazy;
		t[r].lazy = t[node].lazy;
		t[node].lazy = 0;
	}
}
void change(int node, int x, int y, int k) {
	if (x <= t[node].l && y >= t[node].r) {
		t[node].num = 1 << k;
		t[node].lazy = k;
		return ;
	}
	lazy(node);
	int mid = (t[node].r + t[node].l) >> 1;
	if (x <= mid)change(node << 1, x, y, k);
	if(y>mid) change(node << 1 | 1, x, y, k);
	update(node);
}
int ask(int node, int x, int y) {
	if (x <= t[node].l && y >= t[node].r) {
		return t[node].num;
	}
	lazy(node);
	int ans = 0;
	int mid = (t[node].r + t[node].l) >> 1;
	if (x <= mid)ans = ans | ask(node << 1, x, y);
	if(y>mid) ans = ans | ask(node << 1 | 1, x, y);
	return ans;
}
int main() {
	cin >> n >> T >> o;
	build(1, 1, n);
	while (o--) {
		int x, y, z;
		getchar();
		char ch = getchar();
		if (ch == 'C') {
			scanf("%d%d%d", &x, &y, &z);
			if (x > y)swap(x, y);
			change(1, x, y, z);
		} else {
			scanf("%d%d", &x, &y);
			if (x > y)swap(x, y);
			int a = ask(1, x, y);
			int ans = 0;
			while (a) {
				ans += a & 1;
				a >>= 1;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
