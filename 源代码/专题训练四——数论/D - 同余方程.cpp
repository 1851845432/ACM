#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
using namespace std;
inline int read() { int x = 0, f = 1;char ch = getchar();while (ch < '0' || ch > '9') {if (ch == '-')f = -1;ch = getchar();}while (ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();	}return x * f;}
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;
int exgcd(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int gcd = exgcd(b, a % b, y, x);
	y -= (a / b) * x;
	return gcd;
}
int main() {
	int t;t=1;
//	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		int x=1,y=0;
		int gcd=exgcd(a,b,x,y);
		int t=b/gcd;
		cout<<(x%t+t)%t;
	}

	return 0;
}



