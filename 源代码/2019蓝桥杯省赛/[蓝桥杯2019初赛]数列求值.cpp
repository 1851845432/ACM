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
const double eps = 1e-6;
const int N = 1e9+10;
const int mod = 1e9 + 7;
int main() {
//  freopen("in.txt", "r", stdin);
	ll a[10]={0,1,1,1};
	for (int i = 4; i <= 20190324; i++) {
		a[i%4]=(a[(i-1)%4]+a[(i-2)%4]+a[(i-3)%4])%10000;
	}
	cout<<a[20190324%4]<<endl;
	return 0;
}
