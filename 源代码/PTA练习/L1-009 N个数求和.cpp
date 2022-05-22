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
int a[110], b[110];
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
int main() {
//  freopen("in.txt", "r", stdin);
//格式化输入 
	int n;
	cin >> n;
	ll a,b,sa=0,sb=1;
	for (int i = 1; i <= n; i++) {
		scanf("%lld/%lld",&a,&b);
		sa*=b;
		sa+=a*sb;
		sb*=b;
		ll t=gcd(sa,sb);
		sa/=t;
		sb/=t;
	}
//	printf("%lld/%lld\n",sa,sb);
	if(sa%sb==0){
		printf("%lld\n",sa/sb);
	}else if(sa<sb){
		printf("%lld/%lld\n",sa,sb);
	}else{
		printf("%lld %lld/%lld",sa/sb,sa%sb,sb);
	}
	

	
	return 0;
}
