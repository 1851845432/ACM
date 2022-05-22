#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;
char s[25][25];

int main() {
	int t;
	cin>>t;
	int num=0;
	while(t--){
		int a[25]={0};
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>s[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s[i][j]=='*'){
					a[i]++;
				}
			}
		}
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=n;i>=1;i--){
			if(a[i]==a[n]){
				ans++;
			}
		}
		if(ans==3)
		printf("Case %d: Eight\n",++num);
		else
		printf("Case %d: Zero\n",++num);
		
	}

	return 0;
}



