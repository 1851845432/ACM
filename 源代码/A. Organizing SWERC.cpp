#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin>>n;
		int a[15] = {0}, b[15] = {0};
		for (int i = 1; i <= n; i++) {
			int x, y;
			cin >> x >> y;
			a[y] = max(a[y], x);
			b[y]++;
		}
		bool f = 0;
		int sum = 0;
		for (int i = 1; i <= 10; i++) {
			if (!b[i])f = 1;
			sum += a[i];
		}
		if (f)puts("MOREPROBLEMS");
		else {
			cout << sum << endl;
		}
	}
	return 0;
}
