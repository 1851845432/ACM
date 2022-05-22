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
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n, m;
int Log[N], f[N][21];
void init() {//Ô¤´¦Àílog2 
	Log[1] = 0;
	Log[2] = 1;
	for (int i = 3; i <= n; i++) {
		Log[i] = Log[i >> 1] + 1;
	}
}
int main() {
//  freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	init();
	for (int i = 1; i <= n; i++) {
		scanf("%d", &f[i][0]);
	}
	for (int j = 1; j <= 21; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
	for (int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		int s = Log[r - l + 1];
		printf("%d\n", max(f[l][s], f[r - (1 << s) + 1][s]));
	}
	return 0;
}
