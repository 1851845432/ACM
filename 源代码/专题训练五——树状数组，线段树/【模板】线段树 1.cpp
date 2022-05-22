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
struct tree{
	int l,r;
	ll sum,lazy;
	//sum维护的值，l，r维护区间，lazy懒惰标记 
}t[5*N];
int a[N];
int n,m;
inline void update(int node){
	t[node].sum=t[node<<1].sum+t[node<<1|1].sum;
}
void build(int node,int l,int r){//建树 
	t[node].l=l,t[node].r=r;
	if(t[node].l==t[node].r){
		t[node].sum=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(node<<1,l,mid);
	build(node<<1|1,mid+1,r);
	update(node);//这里是因为递归后从底部开始维护，回溯时在维护父节点 
}
void lazy(int node){//下传懒惰标记
	if(t[node].lazy){//如果lazy标记存在，则更新左右子节点
		ll lazy=t[node].lazy;
		int l=node<<1,r=node<<1|1;
		t[l].sum+=lazy*(t[l].r-t[l].l+1);
		t[r].sum+=lazy*(t[r].r-t[r].l+1);
		t[l].lazy+=lazy;
		t[r].lazy+=lazy;
		t[node].lazy=0; 
	} 
	
} 
void change(int node,int x,int y,int k){//区间修改 
	if(t[node].l>=x && t[node].r<=y){//如果需要修改的区间覆盖当前结点的区间 
		t[node].sum+=(ll)k*(t[node].r-t[node].l+1);//更新当前结点维护的值 
		t[node].lazy+=k;//打上懒惰标记 
		return ; 
	} 
	lazy(node);//判断当前结点是否存在懒惰标记，若存在则将标记下移 
	int mid=t[node].l+t[node].r>>1;
	if(x<=mid)change(node<<1,x,y,k);
	if(y>mid)change(node<<1|1,x,y,k);
	update(node);//回溯并维护当前结点的区间值 
}
ll ask(int node,int x,int y){//区间查询 
	if(x<=t[node].l && y>=t[node].r)return t[node].sum;//如果当前区间被查询区间覆盖则返回当前区间值 
	lazy(node);//下传懒惰标记
	int mid=t[node].l + t[node].r>>1;
	ll ans=0;
	if(x<=mid)ans+=ask(node<<1,x,y);
	if(y>mid)ans+=ask(node<<1|1,x,y);
	return ans;
} 	
int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,1,n);
	int t,x,y,k;
	while(m--){
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d%d",&x,&y,&k);
			change(1,x,y,k);
		}
		else{
			scanf("%d%d",&x,&y);
			printf("%lld\n",ask(1,x,y));
		}	
	}
	return 0;
}



