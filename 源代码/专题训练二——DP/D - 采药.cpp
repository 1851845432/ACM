#include<iostream>
using namespace std;
int dp[1100], t[110], v[110];
int main() {
	int T, m;
	cin >> T >> m;
	for (int i = 1; i <= m; i++) {
		cin >> t[i] >> v[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = T; j >= t[i]; j--) {//降维之后记得逆序循环，否则变为完全背包问题 
			if(dp[j-t[i]]+v[i]>dp[j]){
				dp[j]=dp[j-t[i]]+v[i];
			}
		}
	}
	cout<<dp[T]<<endl;
	return 0;
}
