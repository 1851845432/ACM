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
#define forr(i,l,r) for(int x=l;x<=r;x++)
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e3 + 10;
const int M = 2e4 + 10;
const int mod = 998244353;
int a[N];
int dp[N][M << 1];
int main() {
//  freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; i++)scanf("%d", a + i);
	for (int i = 1; i <= n; i++) {
		ans++;
		for (int j = i - 1; j; j--) {
			int gc = a[i] - a[j] + 20000; //20000是转移负公差
			dp[i][gc] += dp[j][gc] + 1;//第一维为第i个位置，第二维转移公差
			dp[i][gc] %= mod;
			ans += dp[j][gc] + 1;
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}
