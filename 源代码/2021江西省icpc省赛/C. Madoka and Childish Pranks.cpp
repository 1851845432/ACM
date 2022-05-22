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
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
typedef pair<int,int> PII;
const double eps = 1e-6;
const int N = 1e2 + 10;
const int mod = 1e9 + 7;
int a[N][N];
struct egde{
	PII a,b;
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin>>n>>m;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++) {
			char s[N];
			cin >> s + 1;
			for (int j = 1; j <= m; j++) {
				a[i][j] = s[j] - '0';
			}
		}
		if (a[1][1]) {
			cout << -1 << endl;
			continue;
		}
		vector<egde> q;
		for (int i = n; i >= 1; i--) {
			for (int j = m; j >= 1; j--) {
				if (a[i][j]) {
					egde x;
					if (i == 1) {
						x.a={i,j-1};
						x.b={i,j};
					}else{
						x.a={i-1,j};
						x.b={i,j};
					}
					q.push_back(x);
				}
			}
		}
		cout<<q.size()<<endl;
		for(auto x:q){
			cout<<x.a.X<<' '<<x.a.Y<<' '<<x.b.X<<' '<<x.b.Y<<endl;
		}
		
	}
	return 0;
}
