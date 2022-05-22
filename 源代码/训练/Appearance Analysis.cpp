#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 150 + 10;
const int mod = 1e9 + 7;
string s[N];
string t[N];
string mp[20000][N];
map<string, bool> p;
int c, r;
int ans = -1;
void xz2(int x) {
	string s1 = t[x], s2 = t[x];
	reverse(s1.begin(), s1.end());
	if (p.count(s1) || p.count(s2)) return ;
	else p[s2] = 1;
}
void xz1(int x) {
	char a[N][N];
	string s1, s2, s3 = t[x], s4 = t[x];
	//90
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			a[j][c - i - 1] = mp[x][i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			s1 += a[i][j];
		}
	}
	s2 = s1, reverse(s2.begin(), s2.end());
	reverse(s3.begin(), s3.end());
	if (p.count(s1) || p.count(s2) || p.count(s3) || p.count(s4)) return ;
	else p[s4] = 1;
//	cout << t[x] << endl << s1 << endl << s2 << endl << s3 << endl;
}
int main() {
	freopen("in.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	getchar();
	string a(m, '#');
	for (int i = 0; i < n; i++) {
		getline(cin, s[i]);
		if (s[i] == a)r++;
	}
	for (int i = 0; i < m; i++) {
		if (s[1][i] == '#')c++;
	}
	r = (n - r) / (r - 1);
	c = (m - c) / (c - 1);
//	cout << r << " " << c << endl;
	for (int i = 1; i < n; i += r + 1) {
		for (int j = 1; j < m; j += c + 1) {
//			cout << i << " " << j << endl;
			ans++;
			for (int x = 0; x < r; x++) {
				for (int y = 0; y < c; y++) {
					mp[ans][x] += s[i + x][j + y];
					t[ans] += s[i + x][j + y];
				}
			}
		}
	}
	for (int i = 0; i <= ans; i++) {
		if (r == c)	xz1(i);
		else xz2(i);
	}
	cout << p.size() << endl;
//	for (int i = 0; i <= ans; i++) {
//		for (int j = 0; j < r; j++) {
//			cout << mp[i][j] << endl;
//		}
//		cout << endl;
//	}
	return 0;
}
