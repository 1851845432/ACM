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
		string a;
		cin >> a;
		unordered_map<char, int> m;
		char ch = a[0];
		bool f = 1;
		for (auto x : a) {
			m[x]++;
			if (ch != x) {
				if (m[ch] <= 1) {
					f = 0;
				}
				m[ch] = 0;
			}
			ch = x;
		}
		if(m[ch]<=1)f=0;
		puts(f ? "YES" : "NO");
	}
	return 0;
}
