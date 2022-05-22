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
const int N=3e6+10;
const int mod=1e9+7;
ll inv[N];
int main() {
	int t;t=1;
//	cin>>t;
	inv[1]=1;
	while(t--){
		ll n,p;
		cin>>n>>p;
		cout<<1<<endl;
		for(int i=2;i<=n;i++){
			inv[i]=(p-p/i)*inv[p%i]%p;
			cout<<inv[i]<<endl;
		}
	}

	return 0;
}



