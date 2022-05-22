#include<iostream>
using namespace std;
const int mod = 998244353;
const int N = 1e7 + 10;
int s[N], a[N];
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int find(int x) {
	if (x != s[x]) s[x] = find(s[x]);
	return s[x];
}
void toget(int x, int y) {
	x = find(x);
	y = find(y);
	s[x] = y;
}
int main() {
	int n, m;
	n = read();
	m = read();
	for (int i = 0; i <= n; i++) s[i] = i;
	int ans = 0;
	while (m--) {
		int op, x, y;
		op = read();
		x = read();
		y = read();
		if (!op) {
			toget(x, y);
		} else {
			if (find(x) == find(y)) {
				ans *= 2;
				ans++;
				ans %= mod;
			} else {
				ans *= 2;
				ans %= mod;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
