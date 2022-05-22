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
const int N = 500 + 10;
const int mod = 1e9 + 7;
int n, m, s, e;
int v[N], d[N], a[N], f[N], r[N], cnt[N];
int p[N][N];
vector<int> q;
void djstl() {
	memset(d, INF, sizeof(d));
	memset(v, 0, sizeof(v));
	d[s] = 0;
	//初始化，路径数，父节点，人数
	cnt[s] = 1, f[s] = s;
	r[s] = a[s];
	while (1) {
		int u = -1, minn = INF;
		for (int i = 0; i < n; i++) {
			if (!v[i] && minn > d[i]) {
				minn = d[i];
				u = i;
			}
		}
		if (u == -1)break;
		v[u] = 1;
		for (int i = 0; i < n; i++) {
			if (!v[i] && d[i] > d[u] + p[u][i]) {//松弛
				d[i] = p[u][i] + d[u];
				f[i] = u;
				r[i] = r[u] + a[i];
				cnt[i] = cnt[u];
//				cout<<u<<" "<<i<<" "<<d[i]<<endl;
			} else if (!v[i] && d[i] == d[u] + p[u][i]) {
				cnt[i] += cnt[u];
				if (r[i] < r[u] + a[i]) { //更新人数
					r[i] = r[u] + a[i];
					f[i] = u;
				}
			}
		}
	}
}
int main() {
//  freopen("in.txt", "r", stdin);
	cin >> n >> m >> s >> e;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(p, INF, sizeof(p));
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		p[b][a] = p[a][b] = min(p[a][b], c);
	}
	djstl();
	cout << cnt[e] << " " << r[e] << endl;
	stack<int> st;
	int k = e;
	while (k != s) {
		st.push(k);
		k = f[k];
	}
	st.push(s);
	while (st.size()) {
		k = st.top();
		st.pop();
		if (st.size() == 0)cout << k << endl;
		else cout << k << " ";
	}
	return 0;
}
