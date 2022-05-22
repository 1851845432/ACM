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
int a[N], b[N];
void add(int x) {
	int jw = 0;
	for (int i = 1; i <= N; i++) { //因为确定位数，所以直接暴力至最高，无需判断最高位
		b[i] += a[i] + jw;
		jw = b[i] / 10;
		b[i] %= 10;
	}
}
void  mul(int x) {
	int jw = 0;
	for (int i = 1; i <= N; i++) {
		a[i] = a[i] * x + jw; //由于只需要乘以一位数，所以可以简便写法
		jw = a[i] / 10;
		a[i] %= 10;
	}
}
int main() {
	int n;
	cin >> n;
	a[1] = 1;
	for (int i = 1; i <= n; i++) {
		mul(i);
		add(i);
	}
	bool f = 0;
	for (int i = N; i >= 1; i--) {
		if (b[i] != 0)f = 1;
		if (f)cout << b[i];
	}
	return 0;
}
