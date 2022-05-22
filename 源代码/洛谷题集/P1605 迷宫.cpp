#include<iostream>
using namespace std;
int map[10][10],v[10][10];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int sx,sy,ex,ey;
int n,m,t;
int ans;
void dfs(int x,int y){
	if(x==ex && y==ey){
		ans++;
		return ;
	}
	map[x][y]=1;
	for(int i=0;i<4;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if(tx>0 && ty>0 && tx<=n && ty<=m && !map[tx][ty])  {
			map[tx][ty]=1;
			dfs(tx,ty);
			map[tx][ty]=0;
		}
	} 
	
	
}
int main(){
	cin>>n>>m>>t;
	cin>>sx>>sy>>ex>>ey;
	for(int i=0;i<t;i++){
		int x,y;
		cin>>x>>y;
		map[x][y]=-1;
	} 
	dfs(sx,sy);
	cout<<ans<<endl;
	
	
	
	return 0;
} 
