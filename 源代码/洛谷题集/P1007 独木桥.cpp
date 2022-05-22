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
const int N=5e3+10;
const int mod=1e9+7;
int a[N];
int main() {
	int l;
	cin>>l;
	int n;
	cin>>n;
	if(n==0){
		cout<<0<<" "<<0<<endl;
		return 0;
	}
	int minn=-INF,maxx=-INF;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=max(minn,min(a[i],l-a[i]+1));
		maxx=max(maxx,max(a[i],l-a[i]+1));
	}
	
	cout<<minn<<" "<<maxx<<endl;

	return 0;
}



