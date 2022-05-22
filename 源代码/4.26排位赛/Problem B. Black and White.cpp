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
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int main() {
//  freopen("in.txt", "r", stdin);
//	freopen("black.in", "r", stdin);
//	freopen("black.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	a--;
	b--;
	int n = 2 * max(a, b) + 1;
	cout << 6 << " " << n << endl;
	string s1(n, '@');
	string s2(n, '.');
	for (int i = 1; i <= n; i++)cout << "@";
	cout << endl;
	for (int i = 1; i <= n; i++) {
		if (i & 1)cout << "@";
		else if (b) {
			cout << ".";
			b--;
		} else {
			cout << "@";
		}
	}
	cout << endl;
	for (int i = 1; i <= n; i++)cout << "@";
	cout << endl;
	for (int i = 1; i <= n; i++)cout << ".";
	cout << endl;
	for (int i = 1; i <= n; i++) {
		if (i & 1)cout << ".";
		else if (a) {
			cout << "@";
			a--;
		} else {
			cout << ".";
		}
	}
	cout << endl;
	for (int i = 1; i <= n; i++)cout << ".";
	cout << endl;
	return 0;
}
