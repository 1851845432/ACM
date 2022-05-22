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
#define lnode node<<1
#define rnode node<<1|1
const double eps = 1e-6;
const int N = 1e4 + 10;
const int mod = 1e9 + 7;
int n;
struct tree {
	int l, r,col;
	int mid(){
		return l+r>>1;
	}
} t[N << 4];//�������û��bushi�� 
struct hb{
	int l,r;
}s[N];//��¼ÿ������������ 
int p[N<<1];//��ɢ�� 
bool v[N]; //��¼��ɫ 

void down(int node){//�´����ݣ������ǰ���������������ʹ��������� 
		t[lnode].col=t[rnode].col=t[node].col;
		t[node].col=0;
}
void build(int node, int l, int r) {//�������� 
	t[node].l=l;t[node].r=r;t[node].col=0;
	if (l == r) return ;//��Ϊûʲô��Ҫ��ʼ���ģ�ֱ��return�� 
	int mid = (l + r) >> 1;
	build(node << 1, l, mid);
	build(node << 1 | 1, mid + 1, r);
}

void change(int node, int x, int y, int k) {//�޸�����Ϊ�������ĺ��� 
	if (x <= t[node].l && y >= t[node].r  ) {
		t[node].col=k;
		return ;
	}
	if(t[node].col)	down(node);//�����ǰ���������������´�����û��Ҫ 
	int mid = (t[node].r + t[node].l) >> 1;
	if (x <= mid)change(node << 1, x, y, k);
	if(y>mid) change(node << 1 | 1, x, y, k);
}

void ask(int node,int l ,int r) {//��ѯ������һ���߶������Ѵ��ڵ���ɫ����¼���� 
	if(t[node].l==t[node].r && t[node].col==0)return ;
	if (t[node].col ) {
		 v[t[node].col]=1;
		return ;
	}
	int mid = (t[node].r + t[node].l) >> 1;
	ask(node << 1, t[node].l, mid);
	ask(node << 1 | 1, mid+1, t[node].r);
}
int main() {
	int T,ans=0;
	cin >> T;
	while (T--){
		ans=0;
		int cnt=0;memset(v,0,sizeof(v));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int l,r;
			scanf("%d%d",&l,&r);
			p[++cnt]=l;p[++cnt]=r;//��¼ÿ�����䳤�� 
			s[i].l=l;s[i].r=r;
		}
		sort(p+1,p+cnt+1);//���� 
		int len=unique(p+1,p+cnt+1)-p-1;//��ɢ��  STL�� 
//		for(int i=1;i<=len;i++)printf("p[%d]=%d ",i,p[i]);cout<<endl;//���� ��ɢ��������� 
		build(1,1,len);//���� 
		for(int i=1;i<=n;i++){
			s[i].l=lower_bound(p+1,p+len+1,s[i].l)-p;
			s[i].r=lower_bound(p+1,p+len+1,s[i].r)-p;
			//ת������ɢ�����ֵ���������޸� 
			change(1,s[i].l,s[i].r,i);
		}
//		for(int i=1;i<=len<<1;i++)printf("t[%d] [%d,%d] col=%d \n",i,t[i].l,t[i].r,t[i].col);
		ask(1,1,len);//���� 
		for(int i=1;i<=n;i++){//��¼��ɫ���� 
			if(v[i])ans++;
		}
		cout<<ans<<endl;//��� 
	}
		return 0;
}
