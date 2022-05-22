#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
const int N = 110;
vector<int> p[N];
queue<int> q;
int in[N], out[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		while (cin >> x && x) {
			p[i].push_back(x);
			in[x]++;
			out[i]++;
		}
	}
	//拓扑排序的模板 
	for (int i = 1; i <= n; i++)if (in[i] == 0)q.push(i);
	while (q.size()) {
		int x=q.front();q.pop();cout<<x<<' ';
		for(int i=0;i<p[x].size();i++){
			in[p[x][i]]--;//走过一次入度减少一 
			if(!in[p[x][i]]){//如果入度为0，则加入队列 
				q.push(p[x][i]);
			}
		}
	}

	return 0;
}


