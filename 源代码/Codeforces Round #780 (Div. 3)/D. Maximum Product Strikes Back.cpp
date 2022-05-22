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
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int a[N];
int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] == 0) {
				v.push_back(i);
			}
		}
		v.push_back(n + 1);
		int l = 1, r = n;
		int ansl = 0, ansr = n, m2 = 0;
		for (auto it : v) {
			r = it - 1;
//			cout<<l<<" "<<r<<endl;
			if (l > r){l = it + 1;continue;}
			int f = 1, ans2 = 0;
			for (int i = l; i <= r; i++) {
				if (a[i] < 0)f = -f;
				if (abs(a[i]) == 2)ans2++;
				if (f > 0 && ans2 > m2) {
					m2 = ans2, ansl = l - 1, ansr = n - i;
				}
			}
			ans2 = 0, f = 1;
			for (int i = r; i >= l; i--) {
				if (a[i] < 0)f = -f;
				if (abs(a[i]) == 2)ans2++;
				if (f > 0 && ans2 > m2) {
					m2 = ans2, ansl = i - 1, ansr = n - r;
				}
			}
			l = it + 1;
		}
		cout << ansl << " " << ansr << endl;
	}
	return 0;
}
