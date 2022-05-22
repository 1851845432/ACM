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
string s[10] = {"AA", "BB", "CC", "ABAB", "BCBC"};
int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a ;
		cin >> b;
		int la = 0, lb = 0;
		if (a == b) {
			cout << "YES" << endl;
			continue;
		}
		for (int i = 0; i < (int)a.size();) {
			string a1 = a.substr(i, 2);
			string a2 = a.substr(i, 4);
//			cout << a1 << endl << a2 << endl;
			bool f = 0;
			for (int j = 0; j < 5; j++) {
				if (a1 == s[j])a.erase(i, 2), f = 1;
				if (a2 == s[j]) a.erase(i, 4), f = 1;
			}
			if (!f)i++;
		}
		for (int i = 0; i < (int) b.size();) {
			string b1 = b.substr(i, 2);
			string b2 = b.substr(i, 4);
			bool f = 1;
			for (int j = 0; j < 5; j++) {
				if (b1 == s[j])b.erase(i, 2), f = 0;
				if (b2 == s[j])b.erase(i, 4), f = 0;
			}
			if (f)i++;
		}
//		cout << a << " " << b << endl;
		puts( a == b  ? "YES" : "NO");
	}
	return 0;
}
