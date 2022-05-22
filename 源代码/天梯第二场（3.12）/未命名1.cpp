#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#define X first
#define Y second
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int t[110][110][11];
int a[110];
int main() {
	int n;
	cin >> n;
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	int ans = 0;
	for (int i = 1; i <= maxx; i++) {
		for (int j = 1; j <= 10; j++) {
			for (int k = 1; k <= n; k++) {
				if (i <= a[k]) {
					if (i == maxx) {
						ans += 2;
					} else ans++;
					t[k][i][j] = ans;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("#%d\n", i);
		for (int j = 1; j <= a[i]; j++) {
			for (int k = 1; k <= 10; k++) {
				cout << t[i][j][k] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
