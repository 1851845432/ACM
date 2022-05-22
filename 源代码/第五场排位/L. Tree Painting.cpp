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
const int N=2e5+10;
const int mod=1e9+7;
int in[N];
int main() {
	int n;
	cin>>n;
	int maxx=0;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		in[a]++;
		in[b]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(in[i]==1){
			ans++;
		}
	}
	if(ans&1){
		cout<<ans/2+1<<endl;
		
	} else{
		cout<<ans/2<<endl;
	}

	
	return 0;
}



