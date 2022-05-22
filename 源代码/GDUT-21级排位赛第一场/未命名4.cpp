#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#define INF 0x3f3f3f
#define int long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1100;
int p[N];
int ksm(int a, int n, int mod) {
	int sum = 1;
	while (n) {
		if (n & 1)sum = sum * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return sum % mod;
}
signed main() {
	int n, k, a;
	int ans=0;
	while (cin >> n >> k >> a && n && k && a) {
		ans++;
		int c;
		cin >> c;
		for (int i = 1; i <= c; i++) {
			cin >> p[i];
		}
		printf("Case %d:\n",ans);
		for (int i = 1; i <= c; i++) {
			int sum = a * ksm(k, n, p[i]);
			if(i==c){
				cout<<sum%p[i]<<endl;
			}else{
				cout << sum % p[i]<<' ';
			}
			
		}
	}
	return 0;
}


