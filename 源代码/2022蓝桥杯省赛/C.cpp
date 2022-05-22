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
int main() {
//  freopen("in.txt", "r", stdin);
	ll a, b, n;
	cin >> a >> b >> n;
	ll c = 5 * a + 2 * b;
	ll ans = (n / c) * 7;
	n %= c;
	for (int i = 1; n > 0; i++) {
		ans++;
		if (i <= 5) {
			n -= a;
		} else {
			n -= b;
		}
	}
	cout<<ans<<endl;
	return 0;
}
