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
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int ans;
int a[N];
void dfs(int x, int y) {
	if (y==0)return ;
	ans++;
	a[ans]=x/y;
//	cout << x / y << ' ' << x << ' ' << y << ' ' << x % y << endl;
	dfs(y, x % y);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		ans = 0;
		memset(a,0,sizeof(a));
			dfs(x, y);
			cout << ans-1 << ' ';
			for(int i=1;i<=ans;i++){
				cout<<a[i]<<' ';
			}
			cout<<endl;
	}
	return 0;
}
