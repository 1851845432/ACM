#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#define X first
#define Y second
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=20+10;
const int mod=1e9+7;
int a[N][N],s[N];
int dp[N];
int v[N];
void prin(int x ){
	if(x==0)return ;
	prin(v[x]);
	cout<<x<<" ";
}
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		dp[i]=s[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int maxx=0;
	int t;
	for(int i=1;i<=n;i++){//dp[i]记录全部到i结点的地雷的最大数量 
		for(int j=1;j<i;j++){//每个结点更新判断一次 
			if(a[j][i] && dp[i]<dp[j]+s[i] ){
				dp[i]=dp[j]+s[i];
				v[i]=j;
			}
			if(maxx<dp[i]){
				maxx=dp[i];
				t=i;
			}
		}
	}
	prin(t);cout<<endl; 
	cout<<maxx<<endl;
	return 0;
}



