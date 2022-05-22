#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[5];
int s[5][30];
int dp[5000]; //记录时间 
int minn,l,r;
//暴力深搜 
void dfs(int x,int y){
	if(x>a[y]){
		minn=min(minn,max(l,r));
		return ;	
	}
	l+=s[y][x];
	dfs(x+1,y);
	l-=s[y][x];
	r+=s[y][x];
	dfs(x+1,y);
	r-=s[y][x];
	
}
int main(){
		int ans=0;
		
	for(int i=0;i<4;i++){
		cin>>a[i];
	}
	for(int i=0;i<4;i++){
		int sum=0;		
		minn=10086;
		l=0;r=0;
		for(int j=0;j<a[i];j++){
			cin>>s[i][j];
		}
		dfs(0,i);
		ans+=minn;	
	}
	cout<<ans<<endl;
	return 0;
} 


//dp 
//int main(){
//		int ans=0;
//	for(int i=0;i<4;i++){
//		cin>>a[i];
//	}
//	for(int i=0;i<4;i++){
//		int sum=0;
//		for(int j=0;j<a[i];j++){
//			cin>>s[i][j];
//			sum+=s[i][j];
//		}
//		//时间最短即让左右脑花费时间接近 
//		for(int j=0;j<a[i];j++){
//			for(int k=sum/2;k>=s[i][j];k--){
//				dp[k]=max(dp[k],dp[k-s[i][j]]+s[i][j]);
//			}
//		}
//		ans+=sum-dp[sum>>1];
//		memset(dp,0,sizeof(dp)); 	
//	}
//		cout<<ans<<endl;
//	
//	
//	return 0;
//} 


//贪心做不了！！！ 
//int main(){
//	for(int i=0;i<4;i++){
//		cin>>a[i];
//	}
//	for(int i=0;i<4;i++){
//		for(int j=0;j<a[i];j++){
//			cin>>s[i][j];
//		}
//	}
//	int ans=0;
//	for(int i=0;i<4;i++){
//		int l=0,r=a[i]-1;
//		sort(*(s+i),*(s+i)+a[i]);
//		while(l<=r){
//			if(s[i][r]-s[i][l]<0){
//				s[i][l]-=s[i][r];
//				ans+=s[i][r];
//				s[i][r]=0;
//				r--;
//			}
//			else if(a[l]==a[r]){
//				ans+=s[i][l];
//				s[i][l]=0;s[i][r]=0;	
//				l++;r--;
//			}
//			else{
//				s[i][r]-=s[i][l];
//				ans+=s[i][l];
//				s[i][l]=0;
//				l++;
//			}
//		}
//	}
//	cout<<ans<<endl;
//	
//	
//	return 0;
//}
