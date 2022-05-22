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
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int w, l;
		cin >> w >> l;
		set<int> st;
		if((w+l)&1)st.insert(2);
		int a = gcd(w, l - 2);
		int b = gcd(w - 2, l);
		int c = gcd(w - 1, l - 1);
		st.insert(a);
		st.insert(b);
		st.insert(c);
		for (int i = 1; i * i <= a; i++) {
			if (a % i == 0) {
				st.insert(i);
				st.insert(a / i);
			}
		}
		for (int i = 1; i * i <= b; i++) {
			if (b % i == 0) {
				st.insert(i);
				st.insert(b / i);
			}
		}
		for (int i = 1; i * i <= c; i++) {
			if (c % i == 0) {
				st.insert(i);
				st.insert(c / i);
			}
		}
		cout << st.size() << " ";
		for (auto x : st) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
