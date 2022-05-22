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
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int a[N];
int main() {
//  freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		ll la = 0, lb = 0;
		ll mx = 0;
		for (int i = 1, j = n; i <= j; i++) {
			la += a[i];
			while (i < j && lb < la) {
				lb += a[j--];
			}
			if (la == lb) {
				mx = max(mx, i + 1ll * (n - j));
			}
		}
		cout << mx << endl;
	}
	return 0;
}
