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
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;
int s[5][5]; 
bool v[20];
bool get(){
	bool flag=1;
	for(int i=0;i<4;i++){
		int sumx=0,sumy=0;
		for(int j=0;j<4;j++){
			sumx+=s[i][j];
			sumy+=s[j][i];
		}
		if(sumx!=sumy || sumx!=34){
			flag=0;
		}
	}
	return flag;
}
int dfs(int x){
	if(x==16){
		if(get())return 1;
		return 0;
	}else{
		if(s[x/4][x%4]==-1){//对4除模 即可表示二维数组与对应的编号之间的行列关系 
			for(int i=1;i<=16;i++){
				if(!v[i]){
					v[i]=1;
					s[x/4][x%4]=i;
					if(dfs(x+1))return 1;
					s[x/4][x%4]=-1;
					v[i]=0;
				}
			}
		}
		else if(dfs(x+1)) return 1;
	}
	return 0;
}
int main() {
	int t;
	cin>>t;
	int ans=0;
	while(t--){
		memset(v,0,sizeof(v));
		memset(s,0,sizeof(s)); 
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cin>>s[i][j];
				if(s[i][j]!=-1)v[s[i][j]]=1;
			}
		}
		dfs(0);
		printf("Case %d:\n",++ans);
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(j==3)cout<<s[i][j]<<endl;
				else cout<<s[i][j]<<' ';
			}
		}
		
	}

	return 0;
}


