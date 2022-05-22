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
const int N=5e5+10;
const int mod=1e9+7;
int t[N],n,m,a[N];
void add(int x,int k){
	for(;x<=n;x+=x&-x)t[x]+=k;
}
int ask(int x){
	int ans=0;
	for(;x;x-=x&-x)ans+=t[x];
	return ans;
}
int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		add(i,a[i]-a[i-1]);
	}
	while(m--){
		int t;cin>>t;
		if(t==1){
			int x,y,k;
			cin>>x>>y>>k;
			add(x,k);add(y+1,-k);
		}
		else{
			int x;
			cin>>x;
			cout<<ask(x)<<endl;
		}
	}

	return 0;
}



