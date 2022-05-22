#include<iostream>
#include<queue>
using namespace std;
int map[10][10],v[10][10];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int sx,sy,ex,ey;
int n,m,t;
int ans;
struct mg{
	int x,y;
};
queue <mg> que; 
int main(){
	cin>>n>>m>>t;
	cin>>sx>>sy>>ex>>ey;
	for(int i=0;i<t;i++){
		int x,y;
		cin>>x>>y;
		map[x][y]=-1;
	} 	
	
	
}
