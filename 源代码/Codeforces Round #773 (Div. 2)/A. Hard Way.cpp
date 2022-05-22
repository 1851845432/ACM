#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;
struct xoy{
	int x,y;
}p[4]; 
int main() {
	int t;
	cin>>t;
	while(t--){
		int ans=0; 
		for(int i=1;i<=3;i++){
			cin>>p[i].x>>p[i].y;
		}
		sort(p+1,p+4,[](xoy &a, xoy &b){
			return a.y>b.y;
		});
		if(p[1].y==p[2].y){
			ans=abs(p[1].x-p[2].x);
		}
		cout<<ans<<endl;
	}

	return 0;
}


