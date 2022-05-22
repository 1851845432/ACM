#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int main() {
	freopen("in.txt", "r", stdin);
	IOS
	int t;
	cin>>t;
	while (t--) {
		int n;
		string s;
		char ch;
		int k;
		cin>>n>>s>>k;
		vector<bool> m(30, 0);
		for (int i = 1; i <= k; i++) {
			cin>>ch;
			m[ch - 'a'] = 1;
		}
		int ans = 0;
		int last = 0;
		for (int i = 1; i < n; i++) {
			if (m[s[i] - 'a']) {
				ans = max(ans, i - last);
				last = i;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
