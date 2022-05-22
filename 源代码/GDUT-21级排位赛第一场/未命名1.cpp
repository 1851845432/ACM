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

int main() {
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int h1,m1,s1,h2,m2,s2;
		cin>>h1>>m1>>s1;
		cin>>h2>>m2>>s2;
		m1+=h1*60;
		m2+=h2*60;
		s1+=m1*60;
		s2+=m2*60;
		if(s1==s2){
			printf("Case %d: Yes\n",i);
		}else{
			printf("Case %d: No\n",i);
		}
	}

	return 0;
}



