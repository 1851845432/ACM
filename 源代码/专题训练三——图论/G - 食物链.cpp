#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#define IL inline
using namespace std;
const int N = 1e5 + 10;
int n, m, ans = 0;
vector<int>p[N];
int v[N], in[N], out[N];

int dfs(int x) {//记忆化搜索 
	if (out[x] == 0&& in[x]) {//出度为0，为最高营养级 TIP:出度为0 但不一定就是食物链，还得注意入度不为0；
		v[x]++;//链数加一 
		return v[x];
	}
	for (int i = 0; i < p[x].size(); i++) {
		if(v[p[x][i]])v[x]+=v[p[x][i]];//如果这个点已经搜过了，就记录下这个点的链数 
		else v[x]+=dfs(p[x][i]);//如果没搜索过就继续往下搜 
	}
	return v[x];
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		p[a].push_back(b);
		in[b]++;
		out[a]++;
	}
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) { //入度为0，肯定为生产者
			ans+=dfs(i);
//			queue<int> que;
//			que.push(i);
//			while (que.size()) {
//				int x = que.front();
//				que.pop();
//				if (out[x] == 0 && in[x]) {
//					ans++;
//				}
//				for (int j = 0; j < p[x].size(); j++) {
//						que.push(p[x][j]);
//					}
//				}
			}
		}
		
	cout << ans << endl;
	return 0;
}


