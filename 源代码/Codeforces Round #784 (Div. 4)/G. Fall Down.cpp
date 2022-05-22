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
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		char p[n + 10][m + 10];
		for (int i = 1; i<= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> p[i][j];
			}
		}
		for (int j = 1; j <= m; j++) {
			int x = n;
			for (int i = n; i >= 1; i--) {
				if (p[i][j] == 'o') {
					x = i - 1;
				} else if (p[i][j] == '*') {
					swap(p[i][j], p[x][j]);
					x--;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << p[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
