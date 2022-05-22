#include<iostream>
using namespace std;
char s[25][25];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int w, h;
int ans;
void	dfs(int x, int y) {
	if (s[x][y] == '#') {
		return ;
	}
	s[x][y] = '#';
	ans++;
	for (int i = 0; i < 4; i++) {
		int	tx = x + dx[i], ty = y + dy[i];
		if (tx >= 0 && tx < h && ty >= 0 && ty < w) {
			dfs(tx, ty);
		}
	}
}
int main() {

	int starx, stary;
	while (1) {
		cin >> w >> h;
		if(w==0 || h==0){
			break;
		}
		ans=0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> s[i][j];
				if (s[i][j] == '@') {
					starx = i;
					stary = j;
				}
			}
		}
		dfs(starx, stary);
		cout << ans << endl;
	}

	return 0;
}
