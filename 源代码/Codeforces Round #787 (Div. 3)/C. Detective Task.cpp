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
		string s;
		cin >> s;
		int n = s.size();
		if (n == 1)cout << n << endl;
		else if (s.find('0') == -1 && s.find('1')==-1)cout << n << endl;
		else {
			int ans = 0;
			n--;
			if (s.find('0') != -1)n = s.find('0');
			for (int i = n; i>=0; i--) {
				ans++;
				if (s[i] == '1')break;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
