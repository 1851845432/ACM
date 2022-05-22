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
int a[N];
int main() {
	char s;
	int i = 0;
	while (cin >> s && s != 'E') {
		i++;
		if (s == 'W') a[i] = 1;
		else a[i] = 2;
	}
	i = 0;
	int w = 0, l = 0;
	while (1) {
		i++;
		if (a[i] == 1)w++;
		else if (a[i] == 2)l++;
		if (a[i] == 0) {
			cout << w << ":" << l << endl << endl;
			w = 0;
			l = 0;
			break;
		}
		if (abs(w - l) >= 2 && (w >= 11 || l >= 11)) {
			cout << w << ":" << l << endl;
			w = 0;
			l = 0;
		}
	}
	i = 0;
	while (1) {
		i++;
		if (a[i] == 1)w++;
		else if (a[i] == 2)l++;
		if (a[i] == 0) {
			cout << w << ":" << l << endl << endl;
			w = 0;
			l = 0;
			break;
		}
		if (abs(w - l) >= 2 && (w >= 21 || l >= 21)) {
			cout << w << ":" << l << endl;
			w = 0;
			l = 0;
		}
	}
	return 0;
}
