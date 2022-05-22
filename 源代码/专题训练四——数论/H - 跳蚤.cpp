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
ll ksm(ll a,ll n){
	ll ans=1;
	while(n){
		if(n&1)ans*=a;
		a*=a;
		n>>=1;
	}
	return ans;
}
int main() {
	int t;t=1;
//	cin>>t;
	while(t--){
	ll n,m;
	cin>>n>>m;
	ll mm=m;
	ll ans=ksm(m,n);
	for(ll i=2;i*i<=mm;i++){
		if(m%i==0){
			ll temp=ksm(i,n);
			ans=ans/temp*(temp-1);
			while(m%i==0)m/=i;
		}
	}
	
	if(m>1)ans=ans/ksm(m,n)*(ksm(m,n)-1);
	cout<<ans<<endl;
	}
	
	return 0;
}


