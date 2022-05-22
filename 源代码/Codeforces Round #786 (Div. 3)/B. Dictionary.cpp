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
	int ans = 1;
	unordered_map<string, int> m;
	for (char i = 'a'; i <= 'z'; i++) {
		for (char j = 'a'; j <= 'z'; j++) {
			if (i == j)continue;
			string s;s+=i;s+=j;
			m[s] = ans++;
		}
	}
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin>>s;
		cout << m[s] << endl;
	}
	return 0;
}
