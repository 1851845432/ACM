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
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
bool p(string a, string b) {
	if (a.size() != b.size()) return 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) {
			return 0;
		}
	}
	return 1;
}
string add(string a) {
	bool f = 1;
	for (int i = 0; i < a.size(); i++) {
		if (f && a[i] == '9') { //如果需要进位并且该位为9
			a[i] = '0';
			f = 1;
		} else if (f) {
			a[i] = a[i] + 1;
			f = 0;
			return a;
		}
	}
	if (f) {
		a = a + '1';
	}
	return a;
}
int main() {
	string a, b;
	cin >> a >> b;
	//反转求高精
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		ans += a[i] - '0';
		ans %= 9;
	}
	int k = ans;
	while (!p(a, b)) { //如果a，b不相等
		a = add(a); //a++
		k++;
		k %= 9;
		ans = ans * k % 9;
		if (ans == 0) {
			break;
		}
	}
	if (ans == 0)cout << 9 << endl;
	else cout << ans << endl;
	return 0;
}
