#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll gcd = exgcd(b, a % b, y, x);
	y -= (a / b) * x;
	return gcd;
}
int main()
{
	ll x, y, m, n, l, X = 0, Y = 0;
	cin >> x >> y >> m >> n >> l;
	ll a = n - m;
	ll b = l;
	ll c = x - y ;
	if(a<0){//扩欧只对非负整数有意义 
		a=-a;
		c=-c;
	}
	ll gcd = exgcd(a, b, X, Y);
	if (c % gcd)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	X *= c / gcd;
	ll t = l / gcd;
	cout << (X % t + t) % t << endl;
	return 0;
}
