#include<iostream>
#include<queue>
using namespace std;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};//иообвСср
int mc[400][400];
queue<struct lx> que; 
struct lx{
	int x,y,t;
}niu;
int main(){
	int n;
	int x,y,t;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y>>t;
		if(!mc[x][y])mc[x][y]=t;
		for(int j=0;j<4;j++){
			int tx=x+dx[j],ty=y+dy[j];
			if(!mc[tx][ty])mc[tx][ty]=t;	
		}
	}
	niu.x=0;niu.y=0;niu.t=0;
	que.push(niu);
		int nx;
		int ny;
	while(que.size()) {
		if(!mc[nx][ny]){
			cout<<que.front().t<<endl;
			return 0;
		}
		for(int i=0;i<4;i++){
			nx=que.front().x+dx[i];
			ny=que.front().y+dy[i];
			if(nx>0 && ny>0 && nx<=300 && ny<=300 && que.front().t<mc[nx][ny]){
				struct lx niu1;
				niu1.x=nx;niu1.y=ny;niu1.t=que.front().t+1;
				que.push(niu1);
			}	
		}
		que.pop();
		
	}
	cout<<-1<<endl;
	return 0;
} 
