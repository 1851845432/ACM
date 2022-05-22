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
#define fro(x) for(int i=1;i<=x;i++)
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=2e5+10;
const int mod=1e9+7;
int a[N];
int main() {
//  freopen("in.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool f1=0,f0=0;
		fro(n){
			cin>>a[i];
			if(a[i]==1)f0=1;
		}
		sort(a+1,a+n+1);
		fro(n-1){
			if(a[i+1]-a[i]==1)f1=1;
		}	
		if(f1 && f0)puts("NO");
		else puts("YES");
	}

	return 0;
}



