#include<bits/stdc++.h>
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
const int N = 5e3 + 10;
const int mod = 1e9 + 7;
int dp[N];
int main() {
//  freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vector<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		int l, w;
		cin >> l >> w;
		q.push_back({l, w});
	}
	sort(q.begin(), q.end(), [](pair<int, int> & a, pair<int, int> & b) {
		if (a.first == b.first)return a.Y > b.Y;
		return a.X > b.X;
	});
//	for(auto it: q){
//		cout<<it.X<<" "<<it.Y<<endl;
//	}
	int ans = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0 ; j < i; j++) {
			if (q[i].second > q[j].second) {//如果不能都比i大则需要准备 
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		ans = max(dp[i], ans);
	}
	cout << ans + 1 << endl;
	return 0;
}
