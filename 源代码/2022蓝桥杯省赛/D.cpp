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
#define INF 0x3f3f3f3f
#define ll long long
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define forr(x) for(int i=1;i<=x;i++)
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=1e4+10;
const int mod=1e9+7;
int main() {
//  freopen("in.txt", "r", stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cout<<max(i-1,n-i)*2<<endl;
	}

	return 0;
}


