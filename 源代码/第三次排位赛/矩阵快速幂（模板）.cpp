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
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e2 + 10;
const int mod = 1e9 + 7;
 ll  n, k;
struct egde {
	ll m[N][N];
	egde() {//将结构体初始化的矩阵全部赋值为0 
		memset(m, 0, sizeof (m));
	}
	inline void  build() {//构建单位矩阵 相当于快速幂初始化时的sum=1;
		for (int i = 1; i <= n; i++) {
			m[i][i] = 1;
		}
	}
} e;
 egde operator *(const egde &a, const egde &b) {//重载结构体的乘法为矩阵乘法 
	egde x;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				x.m[i][j] = (x.m[i][j] + a.m[i][k] * b.m[k][j]%mod) % mod;
			}
		}
	}
	return x;
}
egde ksm() {
	egde ans;
	ans.build();//构建单位矩阵，相当于ans=1; 
	while (k) {
		if (k & 1)ans = ans * e;
		e = e * e;
		k >>= 1;
	}
	return ans;
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> e.m[i][j];
		}
	}
	e = ksm();
	for (int i = 1; i <= n; cout << endl, i++) {
		for (int j = 1; j <= n; j++) {
			printf("%lld ", e.m[i][j]);
		}
	}
	
	return 0;
}
