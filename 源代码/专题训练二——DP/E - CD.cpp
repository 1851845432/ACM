#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int s[25];
int dp[100000];
int m[100][10000];
int main() {
	int n, num;
	while (~scanf("%d%d", &n, &num)) {
		for (int i = 1; i <= num; i++)cin >> s[i];
		memset(dp, 0, sizeof(dp));
		memset(m, 0, sizeof(m));
		for (int i = 1; i <= num; i++) {
			for (int j = n; j >= s[i]; j--) {
				if (dp[j] < dp[j - s[i]] + s[i]) {
					dp[j] = dp[j - s[i]] + s[i];
					m[i][j] = 1;
				} else m[i][j] = 0;
			}
		}
		int v[1100], top = 0;
		for (int i = num, j = n; i > 0 && j > 0 ; i--) {
			if (m[i][j]) {
				v[++top] = s[i];
				j -= s[i];
			}
		}
		while (top) {
			cout << v[top--] << ' ';
		}
		printf("sum:%d\n", dp[n]);
	}
return 0;
}
