#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define  PII pair<int,int>
#define forr(x) for(int i=1;i<=x;i++)
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 5e5 + 10;
const int mod = 1e9 + 7;
int head[N], d[N],vis[N];
int cnt;
int n, m, s;
struct node {
	int to, next, w;
} e[N];
inline void add(int u, int v, int w) {
	e[++cnt].to = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}
void djstl() {
	for(int i=1;i<=n;i++)d[i]=INF;
	d[s]=0;
	priority_queue<PII ,vector<PII>,greater<PII> > q;
	q.push({0,s});
	while(q.size()){
		PII p=q.top();
		q.pop();
		int u=p.Y;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(d[v]>d[u]+e[i].w){
				d[v]=d[u]+e[i].w;
				q.push({d[v],v});
			}
		}
	}
}
//void spfa() {
//	memset(d,INF,sizeof(d));
//	memset(vis,0,sizeof(vis));
//	queue<int> q;
//	q.push(s);
//	vis[s]=1;
//	d[s]=0;
//	while(q.size()){
//		int u=q.front();q.pop();
//		vis[u]=0;
//		for(int i=head[u];i;i=e[i].next){
//			int v=e[i].to;
//			if(d[v]>d[u]+e[i].w){
//				d[v]=d[u]+e[i].w;
//				if(!vis[v]){
//					vis[v]=1;
//					q.push(v);
//				}
//			}
//		}
//	}
//}
int main() {
//  freopen("in.txt", "r", stdin);
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
//	spfa();
	djstl();
	for (int i = 1; i <= n; i++) {
		cout << d[i] << " ";
	}
	return 0;
}
