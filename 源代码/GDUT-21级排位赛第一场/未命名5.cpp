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
int a[15];
int main() {
	int t;
	cin>>t;
	int ans=0;
	
	while(t--){
		int x1,x2,x3,x4,x5;
		int sum=0;
		for(int i=1;i<=10;i++){
			cin>>a[i];
			sum+=a[i];
		}
		sort(a+1,a+11);
		x3=sum/4-(a[1]+a[10]);
		x1=a[2]-x3;
		x5=a[9]-x3;
		x2=a[1]-x1;
		x4=a[10]-x5;
		printf("Case %d: %d %d %d %d %d\n",++ans,x1,x2,x3,x4,x5);
		
	}

	return 0;
}



