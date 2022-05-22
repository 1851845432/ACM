#include<iostream>
#include<queue>
using namespace std;
int n,m,sx,sy,ex,ey;
char map[110][110];
bool v[110][110];//标记 
int dx[4]={-1,1,0,0};//上下左右 
int dy[4]={0,0,-1,1}; 
//定义队列
queue <struct zb> que; 
//定义结构体，记录当前坐标与步数 
struct zb
{
	int x,y,bs;
}p;
void BFS(){
	while(que.size()){
		int x=que.front().x;
		int y=que.front().y;
	//	cout<<x<<' '<<y<<' '<<que.front().bs<<endl;
		if(x==ex && y==ey){
			cout<<que.front().bs<<endl;
			return ;
		}
		for(int i=0;i<4;i++){
				int tx=x+dx[i],ty=y+dy[i];//循环判断四个方向 
				if(tx>=0 && ty>=0 && tx<n && ty<m && (map[tx][ty]=='.' || map[tx][ty]=='G') && !v[tx][ty]){ //判断边界与障碍与是否标记 
					struct zb z;//新开一个结构体记录数据，并压入队列 
					z.x=tx;
					z.y=ty;
					z.bs=que.front().bs+1;
					v[tx][ty]=1;
					que.push(z);
				}
		}
		que.pop();	//每次用完弹出队首 
	}
	cout<<-1<<endl;//历遍循环还是没有解则输出-1； 
}
int main(){

	cin>>n>>m;
	//定义起始坐标与步数 
//	struct stemp s; 
	//初始化迷宫 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			if(map[i][j]=='S'){
				p.x=i;
				p.y=j;
				p.bs=0;
				v[i][j]=1;
				que.push(p);
			}
			if(map[i][j]=='G'){
				ex=i;ey=j;
			}
		}
	}
	BFS(); 
		
	return 0;
} 
