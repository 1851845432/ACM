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

int dfs(int x) {//���仯���� 
	if (out[x] == 0&& in[x]) {//����Ϊ0��Ϊ���Ӫ���� TIP:����Ϊ0 ����һ������ʳ����������ע����Ȳ�Ϊ0��
		v[x]++;//������һ 
		return v[x];
	}
	for (int i = 0; i < p[x].size(); i++) {
		if(v[p[x][i]])v[x]+=v[p[x][i]];//���������Ѿ��ѹ��ˣ��ͼ�¼������������ 
		else v[x]+=dfs(p[x][i]);//���û�������ͼ��������� 
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
		if (in[i] == 0) { //���Ϊ0���϶�Ϊ������
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


