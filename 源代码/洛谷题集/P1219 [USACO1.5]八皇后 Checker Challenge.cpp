#include<iostream>
using namespace std;
int n;
int s[30][30];
int a[30],v[30];
int c[30],d[30];
int ans=0;
void dfs(int x){
	if(x>n){
		ans++;
		if(ans<=3){
			for(int i=1;i<=n;i++){
				cout<<a[i]<<' ';
			}
			cout<<endl;
		}
		return ;
	}
		for(int j=1;j<=n;j++){
				if((!v[j]) && (!c[x+j]) && (!d[x-j+n])){//判断不在对角线 ？平行线？ 
					a[x]=j;
					s[x][j]=1;c[x+j]=1;d[x-j+n]=1;
					v[j]=1;
					dfs(x+1);
					v[j]=0;					
					s[x][j]=0;c[x+j]=0;d[x-j+n]=0;
					}
			}
}
int main(){
	cin>>n;
	dfs(1);
	cout<<ans<<endl;
	
	
	return 0;
} 
