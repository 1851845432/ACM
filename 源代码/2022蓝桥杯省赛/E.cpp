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
const int mod = 1000000007;
int a[N], b[N];
int ss[N];
int main() {
//  freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	int ma, mb;
	cin >> ma;
	for (int i = ma; i >= 1; i--)scanf("%d", a + i);
	cin >> mb;
	for (int i = mb; i >= 1; i--)scanf("%d", b + i);
	int x = max(ma, mb);
	ll sum = 0;
	for (int i = 1; i <= ma; i++) {
		ss[i] = ss[i - 1] * ss[i] % mod;
		ss[i] %= mod;
	}
	for (int i = x; i >= 1; i--) {
		int ans = 0;
		ans = a[i] - b[i];
		ans *= ss[i - 1];
		ans %= mod;
		sum += ans;
		sum %= mod;
	}
	cout << sum << endl;
	return 0;
}
