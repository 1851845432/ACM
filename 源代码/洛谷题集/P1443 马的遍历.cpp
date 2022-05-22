#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n,m,sx,sy;
int s[500][500];
int dx[]={2,1,-1,-2,2,1,-1,-2};//日字型 
int dy[]={1,2,2,1,-1,-2,-2,-1};
queue<struct zb> que;
struct zb{//记录坐标 
	int x,y;
}p; 
void BFS(){
	while(que.size()){
		int x=que.front().x;
		int y=que.front().y;
		for(int i=0;i<8;i++){
			int tx=x+dx[i];
			int ty=y+dy[i];
			if(tx>0 && ty>0 && tx<=n && ty<=m && s[tx][ty]==0){//判断是否越界或访问过 
				struct zb q;
				q.x=tx;
				q.y=ty;
				s[tx][ty]=s[x][y]+1;
				que.push(q);
			}
		}
		que.pop();		
	}
	
	
}
int main(){
	cin>>n>>m>>sx>>sy;
	p.x=sx;p.y=sy;
	que.push(p);//初始化马的起始状态 
	BFS(); 
	s[sx][sy]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==sx && j==sy);
			else if(s[i][j]==0)s[i][j]=-1;
			printf("%-5d",s[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
} 
