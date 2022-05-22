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
#define INF 0x3f3f3f3f
#define ll long long
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define forr(x) for(int i=1;i<=x;i++)
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 2e3 + 10;
const int mod = 1e9 + 7;
int dp[N][N];
int main() {
//  freopen("in.txt", "r", stdin);
	string a, b;
	cin >> a >> b;
	int la = a.size(), lb = b.size();
	for (int i = 1; i <= la; i++)dp[i][0] = i;
	for (int i = 1; i <= lb; i++)dp[0][i] = i;
	for (int i = 1; i <= la; i++) {
		for (int j = 1; j <= lb; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
				continue;
			}
			dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
		}
	}
	cout << dp[la][lb] << endl;
	return 0;
}
