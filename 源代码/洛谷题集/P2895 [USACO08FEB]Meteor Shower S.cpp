#include<iostream>
#include<queue>
using namespace std;
int dx[] = {0,-1,1,0,0 };
int dy[] = {0,0,0,-1,1 };//上下左右
int mc[500][500];
bool v[400][400];
struct lx {
	int x, y, t;
}niu;
queue<lx> que;
int main() {
	int n;
	int x, y, t;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> t;
		for (int j = 0; j < 5; j++) {
			int tx = x + dx[j], ty = y + dy[j];//历遍5个点 
			if (tx >= 0 && ty >= 0 && tx <= 300 && ty <= 300 && (!mc[tx][ty] || t<mc[tx][ty])) {//注意：还需判断流星落下的时间是否比之前输入的小，更新数据 
				if (t == 0)mc[tx][ty] = -1;//如果时间为0，则记录为-1 
				else mc[tx][ty] = t;
			}
		}
	}
	niu.x = 0; niu.y = 0; niu.t = 0; v[0][0] = 1;
	que.push(niu);
	int nx = 0;
	int ny = 0;
	while (que.size()) {
		for (int i = 1; i < 5; i++) {
			nx = que.front().x + dx[i];
			ny = que.front().y + dy[i];
			if (nx < 0 || ny < 0)continue;//牛牛可以跑出农场，也就是可以大于300 所以不需要判断是否大于300 
			if (que.front().t + 1 < mc[nx][ny] && !v[nx][ny]) {
				struct lx niu1;
				niu1.x = nx; niu1.y = ny; niu1.t = que.front().t + 1;
				v[nx][ny] = 1;//标记已走过 
				que.push(niu1);
			}
			if (!mc[nx][ny]) {
				cout << que.front().t + 1 << endl;
				return 0;
			}
		}
		que.pop();
	}
	cout << -1 << endl;
	return 0;
}
