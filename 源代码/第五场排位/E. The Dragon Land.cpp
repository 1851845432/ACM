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
const int N=2e5+10;
const int mod=1e9+7;
ll a[N];
ll dp[N];	
int n;
bool cmp(ll & x, ll &y){
	return x>y;
}

int main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=1;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(dp[i-1]<dp[i-1]+a[i]-k){
			dp[i]=dp[i-1]+a[i]-k;
			k++;
//			cout<<dp[i]<<" "<<k<<endl;
		}else{
			dp[i]=dp[i-1];
//			cout<<dp[i]<<endl;
		}	
	}
	cout<<dp[n]<<endl;

	return 0;
}



