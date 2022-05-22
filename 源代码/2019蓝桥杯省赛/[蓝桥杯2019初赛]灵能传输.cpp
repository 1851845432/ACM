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
const int N = 3e5 + 10;
const int mod = 1e9 + 7;
inline int rd() {
	int f = 1, x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			f = -1;
			ch = getchar();
		}
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar();
	}
	return f * x;
}
ll a[N];
int main() {
//  freopen("in.txt", "r", stdin);
	int t;
	t=rd();
	while(t--){
		int n;
		n=rd();
		ll minn=INF;
		for(int i=1;i<=n;i++){
			a[i]=rd();
			minn=min(minn,abs(a[i]));
		}
		for(int i=2;i<n;i++){
			minn=max(minn,max(abs(-2*a[i]),max(abs(a[i-1]+a[i]),abs(a[i+1]+a[i]))));
		}
		cout<<minn<<endl;
	}
	return 0;
}
