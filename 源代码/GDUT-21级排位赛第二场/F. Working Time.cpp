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
int mi(string a){
	int x=a[0]*10+a[1];
	int y=x*60+a[3]*10+a[4];
	return y;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		string s,e;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>s>>e;
			sum+=(mi(e)-mi(s));
		}
		if(sum>=m*60)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}



