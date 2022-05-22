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
vector<int> q[N];
bool v1[N],v2[N];
int n, m;
void dfs(int x){
	v1[x]=1;
	cout<<x<<' ';
	for(int i=0;i<q[x].size();i++){
		if(!v1[q[x][i]]){
			dfs(q[x][i]);
		}
	}
	return ;
	
}
void bfs(int x){
	queue<int> que;
	que.push(x);
	v2[x]=1;
	cout<<x<<' ';
	while(que.size()){
		x=que.front();que.pop();
		for(int i=0;i<q[x].size();i++){
			if(!v2[q[x][i]]){
				v2[q[x][i]]=1;
				cout<<q[x][i]<<' ';
				que.push(q[x][i]);
			}
		}	
	}
}
int main() {
	int t;
	t = 1;
//	cin>>t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			int x,y;
			cin>>x>>y;
			q[x].push_back(y);
		}
		for(int i=1;i<=n;i++){
			sort(q[i].begin(),q[i].end());
		}
		dfs(1);
		cout<<endl;
		bfs(1);
		
	}
	return 0;
}
