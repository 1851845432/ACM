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
const int N=5e5+10;
const int mod=1e9+7;
ll a[N];
ll s[N];
int main() {
	int n;
	cin>>n;
	ll minn=INF;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		minn=min(minn,s[i]);
	}
	if(minn<=0){
		cout<<-minn<<endl;
	}
	else{
		cout<<0<<endl;
	}

	

	return 0;
}



