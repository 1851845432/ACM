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
const int N = 20 + 10;
const int mod = 1e9 + 7;
int k[N];
string s[N];
int n;
int maxx, ans;
int check(int a, int b) {
//	cout << s[a] << " " << s[b] << endl;
	int la = s[a].size();
	int lb = s[b].size();
	for (int i = la - 1; i >= 0; i--) {
		if (s[a][i] == s[b][0]) {
			int l = i;
			for (int j = 0; j < lb; j++) {
				if (s[a][l] == s[b][j]) {
					l++;
				} else {
					break;
				}
			}
			if (l == la)return l - i;
		}
	}
	return 0;
}
void dfs(int x) {
	for (int i = 1; i <= n; i++) {
		int len = check(x, i); //返回相等的长度
//		cout << len << endl;
		if (len == s[x].size())continue;
		if (k[i] && len) {
			k[i]--;
			ans += s[i].size() - len;
//			cout << s[x] << " " << s[i] << endl;
			dfs(i);
			ans -= s[i].size() - len;
			k[i]++;
		}
	}
	maxx = max(maxx, ans);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		k[i] = 2;
	}
	char ch;
	cin >> ch;
	for (int i = 1; i <= n; i++) {
		if (s[i][0] == ch) {
			ans = s[i].size();
			k[i]--;
			dfs(i);
			k[i]++;
			maxx = max(maxx, ans);
		}
	}
	cout << maxx << endl;
	return 0;
}
