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
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
int a[N];
int n,m;
struct egde{
	int l,r;
	int gcd;
}t[N<<2];
inline void updata(int node){
	t[node].gcd=__gcd(t[node<<1].gcd,t[node<<1|1].gcd);
}
void build(int node,int l,int r){
	t[node]={l,r};
	if(l==r){
		t[node].gcd=a[l];
		return ;
	}
	int mid=l+r>>1;
	build(node<<1,l,mid);
	build(node<<1|1,mid+1,r);
	updata(node);
}
int ask(int node,int x,int y){
	if(x<=t[node].l && y>=t[node].r){
		return t[node].gcd;
	}
	int gcd=0;
	int mid=(t[node].l+t[node].r)>>1;
	if(x<=mid)gcd=ask(node<<1,x,y);
	if(y>mid)gcd=__gcd(gcd,ask(node<<1|1,x,y));
	return gcd;
}
//线段数
int main() 
{
	scanf("%d%d",&n,&m);
	forr(n){
		scanf("%d",a+i);
	}	
	build(1,1,n);
	forr(m){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",ask(1,l,r));
	}
	return 0;
}

//ST表法 
//int Log[N];
//int f[N][23];
//int gcd(int a, int b) {
//	return b ? gcd(b, a % b) : a;
//}
//int main() {
////  freopen("in.txt", "r", stdin);
////	Log[0] = -1;
//	int n, m;
//	cin >> n >> m;
//	forr(n) {
//		scanf("%d", &f[i][0]);
////		Log[i] = Log[i >> 1] + 1;
//	}
//	for (int j = 1; (1<<j) <= n; j++) {
//		for (int i = 1; i + (1 << (j)) - 1 <= n; i++) {
//			f[i][j] = gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
//		}
//	}
//	forr(m) {
//		int l, r;
//		scanf("%d%d", &l, &r);
//		int s =(int)log2(r-l+1);
//		printf("%d\n", gcd(f[l][s], f[r - (1 << s) + 1][s]));
//	}
//	return 0;
//}
