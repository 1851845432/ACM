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
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int a[N];
int main() {
//  freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)cin >> a[i];
		if (n == 1) {
			cout << a[n] << endl;
			continue;
		}
		if (a[1] != n && a[n] != n ) {
			cout << -1 << endl;
			continue;
		}
		stack<int> q;
		q.push(n);
		for (int i = 1; i <= n; i++) {
			if (a[i] == n)continue;
			q.push(a[i]);
		}
		while (q.size()) {
			cout << q.top() << " ";
			q.pop();
		}
		cout << endl;
	}
	return 0;
}
