#include<bits/stdc++.h>
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
vector<ll>ans;
void f(ll n) {
	ll a = 1;
	while (n % 2 == 0)n /= 2, a *= 2;
	while (n % 3 == 0)n /= 3, a *= 3;
	if (n == 1) {
		ans.push_back(a);
		return ;
	}
	ll num = 1;
	while (num <= n)num *= 3;
	num /= 3;
	ans.push_back(a * num);
	n -= num;
	f(a * n);
}
void ff(int n){
	if()
}
int main() {
//	freopen("in.txt", "r", stdin);
	freopen("distribution.in", "r", stdin);
	freopen("distribution.out", "w", stdout);
	ll t;
	cin >> t;
	while (t--) {
		ans.clear();
		ll n;
		cin >> n;
		ff(n);
//		f(n);
//		cout << ans.size() << endl;
//		for (auto x : ans) {
//			cout << x << " ";
//		}
//		cout << endl;
	}
	return 0;
}
