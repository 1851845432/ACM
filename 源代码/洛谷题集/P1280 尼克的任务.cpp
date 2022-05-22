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
const double eps = 1e-6;
const int N = 1e4 + 10;
const int mod = 1e9 + 7;
int n, k;
vector<int> q[N];
int dp[N];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int p, t;
		cin >> p >> t;
		q[p].push_back(t);//记录p时间开始时的任务时长 
	}
	//考虑无后效性，倒着搜 
	for (int i = n; i > 0; i--) {//dp[i]表示i分钟时所能获得的最大空闲时间 
		if(q[i].size()){//如果i分钟时有任务 
			for(int j=0;j<q[i].size();j++){//状态转移每个任务的最大空暇时间 
				dp[i]=max(dp[i],dp[i+q[i][j]]);
			}
		}
		else{//如果i分钟时没用任务，则空闲时间加一 
			dp[i]=dp[i+1]+1;
		} 
	}
	cout<<dp[1]<<endl;
	return 0;
}
