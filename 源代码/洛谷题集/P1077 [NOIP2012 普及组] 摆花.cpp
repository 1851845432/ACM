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
const int N=1e2+10;
const int mod=1e6+7;
int a[N];
int dp[N];
int main() {
//  freopen("in.txt", "r", stdin);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0]=1;
	//状态转移方程的意为：摆完第i种花时，花盆总数恰好为j盆，第三个for为第i种花有多少 盆 
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			for(int k=1;k<=min(j,a[i]);k++){
				dp[j]=(dp[j]+dp[j-k])%mod;
			}
		}
	}
	cout<<dp[m]<<endl;
	return 0;
}



