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
int f[N];
int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = 1;
		memset(f, 0, sizeof(f));
		for (int i = 2; i <= n; i++) {
			int x;
			cin >> x;
			f[x]++;
		}
		sort(f + 1, f + n + 1, greater<int>());
		priority_queue<int, vector<int>, less<int> > q;
		//×¢Éä
		for (int i = 1; i <= n; i++) {
			if (f[i]) {
				ans++;
				q.push(f[i] + i - 1);
			} else {
				break;
			}
		}
		while (ans < q.top()) {
			int x = q.top() - 1;
			q.pop();
			q.push(x);
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
