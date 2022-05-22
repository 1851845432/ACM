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
int v[10];
bool p(int x){
	while(x){
		int y=x%10;
		if(v[y] || y==0){
			return 0;
		}
		v[y]=1;
		x/=10;
	}
	return 1;
}
int main() {
	for(int i=123;i<=333;i++){
			if(p(i) && p(2*i) && p(3*i)){
				cout<<i<<" "<<2*i<<" "<<3*i<<endl;
			}
			memset(v,0,sizeof(v));
	}
	return 0;
}



