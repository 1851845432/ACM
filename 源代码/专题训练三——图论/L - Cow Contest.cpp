#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#define INF 0x3f3f3f
#define ll long long
using namespace std;
const int N = 1e2 + 10;
const int mod = 1e9 + 7;
int n, m;
int p[N][N];
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a,b;
		cin>>a>>b;
		p[a][b]=1;//记录a，b的连通关系 
	}	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(p[i][k] && p[k][j]){
					p[i][j]=1;//floyd算法判断所有奶牛的连通性 
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int num=0;
		for(int j=1;j<=n;j++){
			if(p[i][j] || p[j][i]){//如果i号奶牛与其他j号奶牛的连通关系 
				num++;//若连通则记录连通 
			}
		}
		if(num==n-1){//若知道i号奶牛与其他奶牛的胜负关系，则能判断出奶牛的排名 
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}


