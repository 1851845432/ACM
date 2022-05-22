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
const int N=1e5+10;
const int mod=1e9+7;
int s[N];
int a[N];
int main() {
	int n;
	cin>>n;
	int ans=0;
	int maxx=0;
	for(int i=1;i<=n;i++){
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		maxx=max(maxx,x1);
		maxx=max(maxx,x2);
		a[x1]=1;
		a[x2]=-1;
	}
	int sum=0;
	for(int i=1;i<maxx;i++){
		 a[i]+=a[i-1];
		 sum+=a[i];
	}
	cout<<sum<<endl;
	return 0;
}
/*
3
1 2 3 4
2 4 3 5
2 4 5 7
*/


