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
#define INF 0x3f3f3f3f
#define ll long long
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define forr(x) for(int i=1;i<=x;i++)
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=5e2+10;
const int mod=1e9+7;
int s[N][N];
ll sum[N][N];

int main() {
//  freopen("in.txt", "r", stdin);
	ll n,m,k;
	cin>>n>>m>>k;
	ll ans=0;
	vector<pair<int,int> > w;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&s[i][j]);
			sum[i][j]=sum[i-1][j]+sum[i][j-1]+s[i][j]-sum[i-1][j-1];
			w.push_back({i,j});
		}
	}
	int l=w.size();
	for(int i=0;i<l;i++){
		for(int j=0;j<l;j++){
			int x1=w[i].first,y1=w[i].second;
			int x2=w[j].first,y2=w[j].second;
			if(x1>x2 || y1>y2)continue;
			ll ss=sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
			if(ss<=k)ans++;
		}
	}
	cout<<ans<<endl;
	
	

	return 0;
}



