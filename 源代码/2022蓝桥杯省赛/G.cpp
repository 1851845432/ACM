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
const int mod = 1000000007;
ll ksm(ll a, ll n) {
	ll ans = 1;
	while (n) {
		if (n & 1) ans = (1LL * a * ans) % mod;
		a = (1LL * a * a ) % mod;
		n >>= 1;
	}
	return ans % mod;
}
int main() {
//  freopen("in.txt", "r", stdin);
	ll n;
	cin >> n;
	if (n == 1)cout << 1 << endl;
	else if (n == 2)cout << 2 << endl;
	else cout << ksm(2, n-1) + 1LL << endl;
	return 0;
}
