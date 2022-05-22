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
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 2e3 + 50;
const int mod = 1e9 + 7;
int d[N], v[N];
int s[N][N];
int n;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int djtsl() {
	memset(d, INF, sizeof(d));
	memset(v, 0, sizeof(v));
	d[1] = 0;
	while (1) {
		int u = -1, minn = INF;
		for (int i = 1; i <= n; i++) {
			if (!v[i] && d[i] < minn) {
				u = i;
				minn = d[i];
			}
		}
		if (u == -1)break;
		v[u] = 1;
		for (int i = 1; i <= n; i++) {
			if (!v[i] && d[i] > d[u] + s[u][i]) {
				d[i] = d[u] + s[u][i];
			}
		}
	}
	return d[n];
}
int main() {
	n = 2021;
//	memset(s, INF, sizeof(s));
	for (int i = 1; i <= n; i++) {
		for (int j = i+ 1; j <= n; j++) {
			if (abs(i - j) <= 21) {
				s[i][j] = s[j][i] = lcm(i, j);
			} else {
				s[i][j] = s[j][i]=INF;
			}
		}
	}
	cout << djtsl() << endl;;
	return 0;
}
