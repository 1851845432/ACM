#include<iostream>
#include<cstdio>
using namespace std;
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
const int N = 1e6 + 10;
int s[N];
int main() {

	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int n, m;
	n=read();m=read();
	for (int i = 0; i < n; i++) {
		s[i]=read();
	}
	bool y = (s[1] > s[0]);
	if (y)
		for (int i = 0; i < m; i++) {
			int x;
			x=read();
			int ans = 0;
			bool flag = 0;
			int l = 0, r = n - 1, mid;
			while (l <= r) {
				mid = (l + r) / 2;
				ans++;
				if (s[mid] == x) {
					flag = 1;
					break;
				} else if (s[mid] > x)r = mid - 1;
				else l = mid + 1;
			}
			if (flag)
				printf("%d\n", ans);
			else printf("NONE\n");
		} else
		for (int i = 0; i < m; i++) {
			int x;
			x=read();
			int ans = 0;
			bool flag = 0;
			int l = 0, r = n - 1, mid;
			while (l <= r) {
				mid = (l + r) / 2;
				ans++;
				if (s[mid] == x) {
					flag = 1;
					break;
				} else if (s[mid] > x)l = mid + 1;
				else r = mid - 1;
			}
			if (flag)
				printf("%d\n", ans);
			else printf("NONE\n");
		}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
