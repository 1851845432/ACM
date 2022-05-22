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
const int N=1e5+10;
const int mod=1e9+7;
int a[N],b[N];
int main() {
//  freopen("in.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		forr(n)cin>>a[i],b[i]=a[i];
		if(n>=2*x)puts("YES");
		else {
			sort(b+1,b+n+1);
			bool f=1;
			for(int i=n-x+1;i<=x;i++){
				if(a[i]!=b[i]){
					f=0;break;
				}
			}
			if(f)puts("YES");
			else puts("NO");
		}
	}

	return 0;
}



