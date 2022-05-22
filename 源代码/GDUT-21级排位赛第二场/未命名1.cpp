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
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int a[N];
int main() {
	IOS
	int t;
	cin >> t;
	while (t--) {
		set<int> s;
		map<int, int> m;
		int n, q;
		cin >> n >> q;
		s.insert(0);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			s.insert(a[i]);
			m[a[i]]++;
		}
		while (q--) {
			int f;
			cin >> f;
			if (f == 1) {
				int x, y;
				cin >> x >> y;
				if (m[a[x]] == 1 && a[x]) {
					s.erase(a[x]);
				}
				m[a[x]]--;
				a[x] = y;
				m[a[x]]++;
				s.insert(a[x]);
			} else {
				cout << s.size() - 1 << endl;
			}
		}
	}
	return 0;
}

