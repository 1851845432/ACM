#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
#define P pair<int,int>
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 100003;
int n, m;
int h[N], d[N], ans[N], v[N];
struct egde {
	int to, next;
} p[4 * N];
int cnt;
void add(int u, int v) {
	p[++cnt].to = v;
	p[cnt].next = h[u];
	h[u] = cnt;
}
void djtsl() {
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
		v[i] = 0;
	}
	d[1] = 0;
	ans[1]=1;
	priority_queue<P,vector<P>,greater<P> > q;
	q.push({0,1});
	while (q.size()) {
		int x=q.top().second;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		for (int i = h[x]; i; i=p[i].next) {
			int y=p[i].to;
			if( d[y]>d[x]+1){
				d[y]=d[x]+1;
				ans[y]=ans[x];
				q.push({d[y],y});
			}else if(d[y]==d[x]+1){
				ans[y]+=ans[x];
				ans[y]%=mod;
			}
		}
	}
}
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	djtsl();
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
