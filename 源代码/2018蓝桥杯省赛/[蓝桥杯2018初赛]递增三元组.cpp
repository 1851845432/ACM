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
int a[N], b[N], c[N];
int main() {
//  freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)scanf("%d", a + i);
	for (int i = 1; i <= n; i++)scanf("%d", b + i);
	for (int i = 1; i <= n; i++)scanf("%d", c + i);
	a[n + 1] = b[n + 1] = c[n + 1] = INF;
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	sort(c + 1, c + n + 1);
	ll sum = 0;
	int aa = 0, cc = 0;
	for (int i = 1; i <= n; i++) {
		aa = lower_bound(a + 1, a + n + 1, b[i]) - a - 1;
		cc = n - (upper_bound(c + 1, c + n + 1, b[i]) - c - 1);
		sum += 1LL * aa * cc;
	}
	cout << sum << endl;
	return 0;
}
