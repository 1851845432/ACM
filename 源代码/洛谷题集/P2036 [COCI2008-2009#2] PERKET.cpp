#include<iostream>
#include<math.h>
using namespace std;
int s[20],b[20],v[20];
int n;
int minn=100086;
int ss=1,bb=0;
void dfs(int x){
	if(x>n)return ;//如果超过可以选择的数量则结束 
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;//标记 
			ss*=s[i];bb+=b[i];
			minn=min(minn,abs(ss-bb));
			dfs(x+1);
			ss/=s[i];bb-=b[i];
			v[i]=0;//回溯 
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>b[i];
	}
	dfs(1);
	cout<<minn<<endl;
	return 0;
} 
 
