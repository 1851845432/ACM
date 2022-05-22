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
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n, m;
vector<int> q[N];
int A[N];
void dfs(int x, int d) {
	if(A[x])return ;
	A[x]=d;
	for(int i=0;i<q[x].size();i++){
		dfs(q[x][i],d);
	}
}
int main() {
	int t;
	t = 1;
//	cin>>t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			int x, y;
			cin >> x >> y;
			q[y].push_back(x);//反向建边，逆序遍历，最大点能走到的其他点的最大值就是该点 
		}
		for (int i = n; i; i--)dfs(i, i);
		for(int i=1;i<=n;i++)cout<<A[i]<<' ';
		
	}
	return 0;
}
