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
ll jc[N];
void  init(){
	jc[0]=1;
	for(int i=1;i<=N;i++){
		jc[i]=jc[i-1]*i%mod;
	}
}
ll ksm(ll a,ll n){
	a%=mod;
	ll sum=1;
	while(n){
		if(n&1)sum=(sum*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return sum%mod;
}
int main() {
	init();
		ll a,b,n,ans=0;
		cin>>a>>b>>n;
		for(int i=0;i<=n;i++){
			ll sum=a*i+b*(n-i);
			bool flag=1;
			while(sum){
				if(sum%10!=a && sum%10!=b){
					flag=0;
					break;
				}
				sum/=10;
			}
			if(flag){
				ll inv1=ksm(jc[i],mod-2)%mod;
				ll inv2=ksm(jc[n-i],mod-2)%mod;
				ans+=(jc[n]%mod*inv1%mod*inv2%mod)%mod;
			}
		}
		cout<<ans%mod<<endl;

	return 0;
}



