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
const int N=1e3+10;
const int mod=1e9+7;
int a[N];
int main() {
	int n;
	cin>>n;
		cout<<n/2+1<<endl;
		if(n&1){
			for(int i=1;i<=n;i+=2){
				if(i==n)cout<<i<<endl;
				else cout<<i<<" ";
			}
		}else{
			for(int i=1;i<=n+1;i+=2){
				if(i==n+1)cout<<n<<endl;
				else cout<<i<<" ";
			}
		}
	return 0;
}



