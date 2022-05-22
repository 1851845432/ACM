#include<iostream>
using namespace std;
char s[110][110];
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={-1,0,1,-1,1,-1,0,1};
int ans;	
int n,m;
void dfs(int x,int y){
	s[x][y]='.';
			for(int i=0;i<8;i++){
				int nx=x+dx[i],ny=y+dy[i];
				if(nx>0 && ny>0 && nx<=n && ny<=m && s[nx][ny]=='W')
				dfs(nx,ny);
			}

		return ;
}
int main(){

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i][j];
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='W'){
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
