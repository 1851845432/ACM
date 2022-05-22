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
#define INF 0x3f3f3f3f
#define ll long long
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define forr(x) for(int i=1;i<=x;i++)
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=1e6+10;
const int mod=1000000007;
int ans=0;
int dp[110][110];
void dfs(int n,int m,int s){
	if(n==0 && m==0){
		if(s==0){
			ans++;
			ans%=mod;	
		}
		return ;
	}
	if(n<0 || m<0 || s==0)return ;
	dfs(n-1,m,s*2);
	dfs(n,m-1,s-1);
}
int main() {
//  freopen("in.txt", "r", stdin);
	int n,m;
	cin>>n>>m;
	dfs(n,m,2);
	cout<<ans<<endl;
	return 0;
}



