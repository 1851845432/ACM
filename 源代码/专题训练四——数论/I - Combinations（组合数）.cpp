#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
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

int main() {
	ll n,m;
	while(~scanf("%lld%lld",&n,&m) && n+m){
		ll sum=1;
		if(2*m>n){
			m=n-m;
		}
		for(ll i=1,j=n;i<=m;i++,j--){
			sum=sum*j/i;
		}
		printf("%lld things taken %lld at a time is %lld exactly.\n",n,m,sum);
	}

	return 0;
}



