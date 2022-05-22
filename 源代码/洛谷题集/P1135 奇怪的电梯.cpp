#include<iostream>
#include<queue>
using namespace std;
int n,a,b;
int s[300],v[300];
bool flag=0;
int sum=10086;
queue<struct lt> que;
struct lt{
	int x,set;
}p;
void bfs(){

	while(que.size()){
		int x=que.front().x;
		int bs=que.front().set;
		if(x==b){
			sum=min(sum,bs);
			cout<<sum<<endl;		
			return ;
		}
		struct lt q;
		v[x]=1;
		if(x+s[x]<=n && !v[x+s[x]]){
			q.x=x+s[x];q.set=bs+1;
			que.push(q);
		}
		if(x-s[x]>0 && !v[x-s[x]]){
			q.x=x-s[x];q.set=bs+1;
			que.push(q);
		}
		que.pop();
	}
	cout<<-1<<endl;	
}
int main(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	p.x=a;
	p.set=0;
	que.push(p);
	bfs();
	
	return 0;
}

//void dfs(int x,int ans){
//	if(x==b){
//		flag=1;
//		sum=min(sum,ans);
//		return ;
//	}
//	else if(ans>sum)return ;
//	else{
//		v[x]=1;
//		if(x+s[x]>0 && (x+s[x])<=n && !v[x+s[x]])dfs(x+s[x],ans+1);
//		if(x-s[x]>0 && (x-s[x])<=n && !v[x-s[x]])dfs(x-s[x],ans+1);
//		v[x]=0;
//		}
//	return ;
//}
//int main(){
//
//	cin>>n>>a>>b;
//	for(int i=1;i<=n;i++){
//		cin>>s[i];
//	}
//	dfs(a,0);
//	if(flag)cout<<sum<<endl;
//	else cout<<-1<<endl;
//	return 0;
//}
