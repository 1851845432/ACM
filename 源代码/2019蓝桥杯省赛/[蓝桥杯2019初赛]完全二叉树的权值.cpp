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
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int main() {
//  freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	int u = 0;
	int d = 1;
	ll maxx = -100000000000;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		sum += x;
		if (i == pow(2, d) - 1) {
			if (sum > maxx) {
				maxx = sum;
				u = d;
			}
			sum = 0;
			d++;
		}
	}
	cout << u  << endl;
	return 0;
}
