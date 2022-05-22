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
const double eps = 1e-6;
const int N = 1e7 + 10;
const int mod = 1e9 + 7;
inline gcd(int x,int y){
	if(y==0)return x;
	gcd(y,x%y);
}
inline int zys(int x) {
	int ans=0;
	for (int i = 2; i <= sqrt(x); i++) {
		if(x%i==0){
			ans++;
		//	cout<<i<<endl;
			while (x % i == 0)x /= i;	
		}	
	}
	if(x>1)ans++; 
	return ans;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n",zys(a)+zys(b)-zys(gcd(a,b)));
	}
	return 0;
}
