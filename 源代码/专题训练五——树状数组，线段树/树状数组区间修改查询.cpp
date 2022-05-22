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
const int N=1e5+10;
const int mod=1e9+7;
ll a[N],t1[N],t2[N];
 int n,m;
void add1(int x,int k){
	for(;x<=n;x+=x&-x)t1[x]+=k;
}
void add2(int x,int k){
	for(;x<=n;x+=x&-x)t2[x]+=k;
}
ll ask1(int x){
	ll ans=0;
	for(;x;x-=x&-x)ans+=t1[x];
	return ans;
}
ll ask2(int x){
	ll ans=0;
	for(;x;x-=x&-x)ans+=t2[x];
	return ans;
}
ll ask(int x){
	return ask1(x+1)*(x+1)-ask2(x+1);
}
int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=a[i]-a[i-1];
		add1(i,x);//维护差分数组 
		add2(i,i*x); 
	}
	while(m--){
		int q,x,y,k;
		scanf("%d",&q);
		if(q==1){
			scanf("%d%d%d",&x,&y,&k);
			add1(x,k);add1(y+1,-k);
			add2(x,x*k);add2(y+1,-(y+1)*k); 
		}
		else{
			scanf("%d%d",&x,&y);
			cout<<ask(y)-ask(x-1)<<endl;
		}
	}
	return 0;
}



