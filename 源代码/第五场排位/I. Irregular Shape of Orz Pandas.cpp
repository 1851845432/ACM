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
struct egde{
	int x,y;
};
vector<egde> q;
int main() {
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			egde a;
			cin>>a.x>>a.y;
			q.push_back(a);
		}
		
	}

	return 0;
}



