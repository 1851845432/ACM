#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		string s[n];
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		int ans=0,minn=INF;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)continue;
				ans=0;
				for(int k=0;k<m;k++){
					ans+=abs(s[i][k]-s[j][k]);
				}
				minn=min(minn,ans);
			} 
		}
		cout << minn << endl;
	}
	return 0;
}
