#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define ll long long
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define forr(x) for(int i=1;i<=x;i++)
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 4e4 + 10;
const int mod = 32768;
int a[N];
int main() {
//  freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	ll sum=0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		int ans=INF;
		for(int j=0;j<=15;j++){
			for(int k=0;k<=15;k++){
				if(((x+j)<<k)%mod==0){
					ans=min(ans,j+k);
				}
			}
		}
		cout<<ans<<" ";
	}
	
	return 0;
}
