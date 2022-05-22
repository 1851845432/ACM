#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
using namespace std;
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;

int main() {
  freopen("in.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--){
		int a,b,c,x,y;
		cin>>a>>b>>c>>x>>y;
		int xx=a-x>=0?0:a-x;
		int yy=b-y>=0?0:b-y;
		if(xx+yy+c>=0)puts("YES");
		else puts("NO");
		
		
	}

	return 0;
}



