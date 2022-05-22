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
int a[N];
int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		s += 'W';
		bool f = 0;
		int r = 0, b = 0;
		for (int i = 0; i <= n; i++) {
			if (s[i] == 'W') {
				if ((!b && r) || (!r && b)) {
					f = 1;
					break;
				}
				b = 0;
				r = 0;
			} else if (s[i] == 'R')r++;
			else b++;
		}
		if (f)cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}
