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
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int a[N], b[N];
int main() {
//  freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)scanf("%d", a + i);
		for (int i = 1; i <= m; i++)scanf("%d", b + i);
		ll sum = 0;
		for (int i = 1, aa = 1, bb = 1; i <= n + m; i++) {
			if (aa > n)sum += 1LL * i * b[bb++];
			else if (bb > m)sum += 1LL * i * a[aa++];
			else {
				if (a[aa] > b[bb]) {
					sum += 1LL * i * a[aa++];
				} else {
					sum += 1LL * i * b[bb++];
				}
			}
		}
		printf("Case %d: %lld\n", tt, sum);
	}
	return 0;
}
