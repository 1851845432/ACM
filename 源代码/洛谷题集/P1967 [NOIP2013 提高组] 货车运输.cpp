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
const int N = 1e4 + 10;
const int mod = 1e9 + 7;
int n, m;
int q[N][N];
int v[N],d[N];
void prim(){
	for(int i=1;i<=n;i++){
		v[i]=0;
		d[i]=INF; 
	}
	d[1]=0;
	while(1){
		int u=-1,minn=INF;
		for(int i=1;i<=n;i++){
			
		}
	}
}
int main() {
	int t;
	t = 1;
	while (t--) {
		memset(q,INF,size(q));
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			int x,y,z;
			q[x][y]=q[y][x]=z;
	 	}
	 	prim();
	 	int a;
	 	cin>>a;
	 	while(a--){
		 	int x,y;
		 	cin>>x>>y;
		 	
		 }
	}
	return 0;
}
