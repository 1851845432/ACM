#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define ll long long
#define endl "\n"
using namespace std;
const double eps=1e-6;
const int N=5e4+10;
const int mod=1e9+7;
int p[N],l[N];
int dp[N][N];
int main() {
//  freopen("in.txt", "r", stdin);
//	freopen("A.in", "r", stdin);
//	freopen("A.out", "w", stdout);
	int n,t;
	cin>>n>>t;
	for(int i=1;i<n;i++)cin>>p[i];
	for(int i=2;i<n;i++)cin>>l[i];
	t-=n-1;
	int minn=INF;
	for(int i=1;i<n;i++){
		for(int j=2;j<=n;j++){
			for(int k=1;k<=i;k++){
				dp[j][]
			}
		}
	}

	return 0;
}



