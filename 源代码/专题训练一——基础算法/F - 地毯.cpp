#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e3 + 10;
int a[N][N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		a[x1][y1]++;
		a[x2 + 1][y1]--;
		a[x1][y2 + 1]--;
		a[x2 + 1][y2 + 1]++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1]);
		}
		printf("\n");
	}


	return 0;
}
