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
const int N=1e6+10;
const int mod=1e9+7;

int main() {
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;//ms
		n/=1000;//s
		int h=n/3600%24;
		int m=n/60%60;
		int s=n%60;
		printf("%02d:%02d:%02d\n",h,m,s);
	}
	return 0;
}



