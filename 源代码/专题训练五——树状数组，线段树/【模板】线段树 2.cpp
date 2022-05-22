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
	ll sum, lazy, mul; //lazyΪ�ӷ���ǣ�mulΪ�˷����
} t[5 * N];
inline void update(int x) { //ά�������
	t[x].sum = (t[x << 1].sum + t[x << 1 | 1].sum) % p;
}
inline void lazy(int node) { //ά�������ǣ��ȳ˺��
	ll lazy = t[node].lazy, mul = t[node].mul;
	int l = node << 1, r = node << 1 | 1; //���Ҷ��ӽ��
//�������ȶ� ���ӵ�ֵ=�˿̶��ӵ�ֵ*�ְֵĳ˷�mul+���ӵ����䳤��*�ְֵļӷ�lazy
	t[l].sum = (t[l].sum * mul + lazy * (t[l].r - t[l].l + 1)) % p;
	t[r].sum = (t[r].sum * mul + lazy * (t[r].r - t[r].l + 1)) % p;
//�����ӽڵ�ӷ���ǣ�ע����Ҫ�ȳ��ϳ˷�����ڼ�
	t[l].lazy = (t[l].lazy * mul + lazy) % p;
	t[r].lazy = (t[r].lazy * mul + lazy) % p;
//�����ӽڵ�˷����
	t[l].mul = (t[l].mul * mul) % p;
	t[r].mul = (t[r].mul * mul) % p;
//���¸��ڵ�ı��
	t[node].lazy = 0;
	t[node].mul = 1;
}
void build(int node, int l, int r) { //����
	t[node].l = l, t[node].r = r;
//��ʼ�������� 
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
void mul(int node, int x, int y, int k) { //����˷�
	if (x <= t[node].l && y >= t[node].r) {
	//ע������˷�ʱ���ӷ����Ҳ��Ҫ��k
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
void add(int node, int x, int y, int k) { //����ӷ�
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
ll ask(int node, int x, int y) { //�����ѯ
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
