#include<iostream>
using namespace std;
int main() {
	int n, s[100], dp[100][100];
	for (int i = 0; i < n; i++)cin >> s[i];
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= m; k++) {
				dp[0][j]=(s[0]==k);
				dp[j][0]=1;
				if (s[j] > k) {
					dp[j][k] = dp[j - 1][k];
				} else {
					dp[j][k]=dp[j][k] || dp[j][k-s[j]];
				}

			}
		}
			cout<<dp[n][m]<<endl;
	}

	return 0;
}


//int n,q;
//int s[25];
//bool dfs(int x,int m){
//	if(m==0)return 1;
//	if(x>=n)return 0;
//	bool rec=dfs(x+1,m)||dfs(x+1,m-s[x]);
//	return rec;
//
//}
//int main(){
//	cin>>n;
//	for(int i=0;i<n;i++){
//		cin>>s[i];
//	}
//	cin>>q;
//	for(int i=0;i<q;i++){
//		int m;
//		cin>>m;
//		if(dfs(0,m))cout<<"yes"<<endl;
//		else cout<<"no"<<endl;
//	}
//
//	return 0;
//}
