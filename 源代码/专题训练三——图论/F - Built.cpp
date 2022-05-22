#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#define IL inline
typedef long long ll;
using namespace std;
//kruskal算法 
const int N = 1e5 + 10;
ll n,ans,sum;
struct edge {//记录边的结构体，p1，p2分别记录转换成结点的图，d表示为边的权值 
	ll p1, p2, d;
} p[2*N];
struct dian {//记录点的结构体 ，以下标id表示为图的结点 
	ll x, y, id;
} a[N];
bool cmpx(dian a, dian b) {//对x坐标排序 
	return a.x < b.x;
}
bool cmpy(dian a, dian b) {//对y坐标排序 
	return a.y < b.y;
}
bool cmp(edge a, edge b) {//对边长坐标排序 
	return a.d < b.d;
}
int f[N];//记录父节点 
int fd(ll x) {//查找父节点 
	if (x == f[x])return x;
	return f[x] = fd(f[x]);
}
void tg(int x, int y) {//合并结点 
	x = fd(x);
	y = fd(y);
	if (x != y)f[y] = x;
}
int kruskal() {//算法实现 
	int num=0;
	for (int i = 1; i <= ans; i++) {
		int x=fd(p[i].p1),y=fd(p[i].p2);
		if(x==y)continue;
		f[x]=y;
		sum+=p[i].d;
		num++;
		if(num==n-1)break;
	}
	return sum;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &a[i].x, &a[i].y);//输入点的坐标 
		a[i].id = i;//记录其为图的结点 
		f[i] = i;//初始化父节点 
	}
	sort(a + 1, a + n + 1, cmpx);//对x排序 
	for (int i = 1; i < n; i++) {//分别记录两个结点的x的所表示边的权值 
		p[++ans].p1 = a[i].id;
		p[ans].p2 = a[i + 1].id;
		p[ans].d = abs(a[i].x - a[i + 1].x);
	}
	sort(a + 1, a + n + 1, cmpy);
	for (int i = 1; i < n; i++) {//分别记录两个结点的y的所表示边的权值 
		p[++ans].p1 = a[i].id;
		p[ans].p2 = a[i + 1].id;
		p[ans].d = abs(a[i].y - a[i + 1].y);
	}
	sort(p+1,p+ans+1,cmp);//对其边的全部权值进行排序 ，转换为了kruskal求最小生成树问题 
	cout<<kruskal()<<endl;
	
	return 0;
}


