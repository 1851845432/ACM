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
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
inline bool pd(int x) {
	if (x <= 0)return 0;
	while (x) {
		if (x % 10 == 2 || x % 10 == 4) {
			return 0;
		}
		x /= 10;
	}
	return 1;
}
int main() {
//  freopen("in.txt", "r", stdin);
//	int n = 2019;
//	ll ans = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			for (int k = j + 1; k <= n; k++) {
//				if (i + j + k == n) {
//					if (pd(i) && pd(j) && pd(k)) {
//						ans++;
//					}
//				}
//			}
//		}
//	}
	cout << 40785;
	return 0;
}
