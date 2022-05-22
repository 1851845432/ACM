#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5 + 10;
int a[N];
long long s[N];
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = a[i] + s[i - 1];
	}
	for (int i = 0; i < q; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%lld\n", s[y] - s[x - 1]);

	}


	return 0;
}
