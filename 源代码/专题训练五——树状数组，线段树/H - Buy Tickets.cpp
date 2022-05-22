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
const double eps=1e-6;
const int N=2e5+10;
const int mod=1e9+7;
int n; 
int pos[N],val[N],ans[N];
struct tree{
	int l,r,sum;
	int mid(){
		return l+r>>1;
	}
}t[N<<2];

inline void update(int node){
	t[node].sum=t[node<<1].sum+t[node<<1|1].sum;
}
void build(int node,int l,int r){
	t[node].l=l;t[node].r=r; 
	if(l==r){
		t[node].sum=1;
		return ;
	}
	int mid=t[node].mid();
	build(node<<1,l,mid);
	build(node<<1|1,mid+1,r);
	update(node);
}
//单点修改 
void change(int node,int x,int y){
	if(t[node].l==t[node].r){
		t[node].sum=0;//标记这个点被插队 
		ans[t[node].l]=y;//记录下该位置的人 
		return ;
	}
	if(x<=t[node<<1].sum) change(node<<1,x,y);//如果想插入的位置小于子节点的可插空数 
	else change(node<<1|1,x-t[node<<1].sum,y); //否则需要减去左结点能插空的人数，得到相对右结点的插空位置 
	update(node);
}

int main() {
	while(~scanf("%d",&n)){
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++){
			scanf("%d%d",&pos[i],&val[i]);
		}
		build(1,1,n);
	//	for(int i=1;i<=n<<1;i++)printf("t[%d] [%d,%d] sum=%d \n",i,t[i].l,t[i].r,t[i].sum);
		for(int i=n;i>=1;i--){//因为后面插完队后不会被前面的影响，所以逆序改变 
			change(1,pos[i]+1,val[i]);
		}
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}



