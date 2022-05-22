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

int main() {
	int n,m,s;
	cin>>n>>m>>s;
	int x=n*m;
	if(x&1 || s>=x)cout<<"YES"<<endl;
	else if(s==1 || (s<4 && (n&1)+(m&1)==0) ){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
	}
	return 0;
}


