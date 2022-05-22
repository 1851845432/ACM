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
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
int a[N];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if(n>19){
			cout<<"NO"<<endl;
			continue;
		}else{
			cout<<"YES"<<endl;
			ll ans=1;
			for(ll i=1;i<=n;i++){
				if(i==n)cout<<ans<<endl;
				else  cout<<ans<<" ";
				ans*=3;
			}
		}

	}
	return 0;
}
