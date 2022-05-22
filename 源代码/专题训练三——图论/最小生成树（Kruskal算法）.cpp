#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 2e5 + 10;
int n, m, ans;
long long sum;
int fa[50100];
struct edge {
	int x, y;
	long long val;
} t[N];
bool cmp(const edge &x, const edge &y) {
	return x.val < y.val;
}
int find(int x ) {
	if (fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
}
void kruskal() {
	for (int i = 1; i <= m; i++) {
		int x = find(t[i].x);
		int y = find(t[i].y);
		if (x == y) continue;
		sum += t[i].val;
		fa[x] = y;
		ans++;
		if (ans == n - 1)break;
	}
	cout << sum << endl;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)fa[i] = i;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%lld", &t[i].x, &t[i].y, &t[i].val);
	}
	sort(t + 1, t + m + 1, cmp);
	kruskal();

	return 0;
}
