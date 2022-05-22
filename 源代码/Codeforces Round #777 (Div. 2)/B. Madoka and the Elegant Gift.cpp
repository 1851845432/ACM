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
typedef pair<int, int> PII;
const double eps = 1e-6;
const int N = 1e2 + 10;
const int mod = 1e9 + 7;
int a[N][N];		
int n, m;
void solve(){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m-1;j++){
			int sum=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
			if(sum==3){
				cout<<"NO"<<endl;
				return ;
			}
		}
	}
	cout<<"YES"<<endl;
	
}
int main() {
	int t;
	cin >> t;
	while (t--) {

		cin >> n >> m;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				a[i][j] = s[j] - '0';
			}
		}
		solve();
	}
	return 0;
}
