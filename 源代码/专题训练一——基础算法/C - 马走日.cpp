#include<iostream>
#include<cstring>
using namespace std;
int dx[] = {2, 1, -1, -2, 2, 1, -1, -2}; //ÈÕ×ÖÐÍ
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int s[20][20];
int ans;
int n, m, x, y;
void dfs(int x, int y,int bs) {
	if(bs==0){
		ans++;
		return ;
	}
	for (int i = 0; i < 8; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 0 && tx < n && ty >= 0 && ty < m && !s[tx][ty]) {
			s[tx][ty] = 1;
			dfs(tx, ty,bs-1);
			s[tx][ty] = 0;
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> x >> y;
		memset(s,0,sizeof(s));
		ans=0;
		s[x][y]=1;
		dfs(x, y,n*m-1);
		cout << ans << endl;
	}
	return 0;
}
