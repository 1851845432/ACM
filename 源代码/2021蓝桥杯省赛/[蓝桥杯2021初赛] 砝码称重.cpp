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
const int N=1e5+10;
const int mod=1e9+7;
int w[N];
int dp[N];
bool t[N];
int main() {
//	fre();
	int n;
	cin>>n;
	t[0]=1;
	for(int i=1;i<=n;i++)cin>>w[i];
	int cnt=0,k=0;
	for(int i=1;i<=n;i++){
		int k=0;		
		for(int j=0;j<=cnt;j++){
			int a=abs(dp[j]-w[i]);
			int b=abs(dp[j]+w[i]);
			if(!t[a]){
				k++;dp[cnt+k]=a;t[a]=1;
			}
			if(!t[b]){
				k++;dp[cnt+k]=b;t[b]=1;
			}
		}
		cnt+=k;
	}
	cout<<cnt<<endl;
	return 0;
}


