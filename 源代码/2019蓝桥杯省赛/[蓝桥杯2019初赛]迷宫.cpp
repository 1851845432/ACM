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
#define INF 0x3f3f3f3f
#define ll long long
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define forr(x) for(int i=1;i<=x;i++)
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
char s[35][55];
string q[30];
bool v[35][55];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char t[] = {'D', 'L', 'R', 'U'};
struct egde {
	int x, y;
	string t;
};
int main() {
	freopen("in.txt", "r", stdin);
	int n = 30, m =50;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> s[i][j];
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout<< s[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	queue<egde> que;
	que.push({1,1,""});
	while(que.size()){
		egde z=que.front();que.pop();
		if(z.x==n && z.y==m){
			cout<<z.t<<endl;
			continue;
		}
		for(int i=0;i<4;i++){
			int x=z.x+dx[i];
			int y=z.y+dy[i];
			if(x>=1 && x<=n && y>=1 && y<=m && s[x][y]=='0' && !v[x][y]){
				v[x][y]=1;
				string a=z.t+t[i];
				que.push({x,y,a});
			}
		}
	}
	return 0;
}
