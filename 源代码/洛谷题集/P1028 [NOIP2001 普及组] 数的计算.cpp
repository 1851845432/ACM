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
const int N=1e3+10;
const int mod=1e9+7;
int dp[N];
//递推：dp[x]=dp[1]+....+dp[x/2]; 
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i/2;j++){
			dp[i]+=dp[j];//递推 
		}
		dp[i]++;//加上本身 
	}
	cout<<dp[n]<<endl;
	return 0;
}



