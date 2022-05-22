#include<iostream>
#include<queue>
using namespace std;
int n,m,sx,sy,ex,ey;
char map[110][110];
bool v[110][110];//��� 
int dx[4]={-1,1,0,0};//�������� 
int dy[4]={0,0,-1,1}; 
//�������
queue <struct zb> que; 
//����ṹ�壬��¼��ǰ�����벽�� 
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
				int tx=x+dx[i],ty=y+dy[i];//ѭ���ж��ĸ����� 
				if(tx>=0 && ty>=0 && tx<n && ty<m && (map[tx][ty]=='.' || map[tx][ty]=='G') && !v[tx][ty]){ //�жϱ߽����ϰ����Ƿ��� 
					struct zb z;//�¿�һ���ṹ���¼���ݣ���ѹ����� 
					z.x=tx;
					z.y=ty;
					z.bs=que.front().bs+1;
					v[tx][ty]=1;
					que.push(z);
				}
		}
		que.pop();	//ÿ�����굯������ 
	}
	cout<<-1<<endl;//����ѭ������û�н������-1�� 
}
int main(){

	cin>>n>>m;
	//������ʼ�����벽�� 
//	struct stemp s; 
	//��ʼ���Թ� 
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
