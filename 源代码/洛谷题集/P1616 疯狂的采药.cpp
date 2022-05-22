#include<iostream>
using namespace std;
const int N = 1e7 + 10;
long long dp[N], s[N],v[N];//注意数据范围，记得long long 
int main() {
	int t, m;
	cin >> t >> m;
	for (int i = 0; i < m; i++) {
		cin >> s[i]>>v[i]; 
	}
	for (int i = 0; i < m; i++) {
		for(int j=s[i];j<=t;j++){
			dp[j]=max(dp[j],dp[j-s[i]]+v[i]);
		}
	}
	cout<<dp[t]<<endl;
	return 0;
}
