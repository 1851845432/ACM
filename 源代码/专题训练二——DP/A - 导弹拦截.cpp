#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 1e5 + 10;
int s[N], dp[N], up[N];
bool cmp(const int &a, const int &b) {
	return a > b;
}
int main() {
	int n, i = 0;
	while (scanf("%d", &s[i]) != EOF) {
		i++;
	}
	n = i;
	int top = 1, tail = 1;
	dp[top] = s[0];
	up[tail] = s[0];
	for (int i = 1; i < n; i++) {
		if (s[i] <= dp[top]) {
			dp[++top] = s[i];
		} else {
			dp[upper_bound(dp + 1, dp + top + 1, s[i], cmp) - dp ] = s[i];
		}
		if (s[i] > up[tail]) {
			up[++tail] = s[i];
		} else {
			up[lower_bound(up + 1, up + tail + 1, s[i]) - up] = s[i];
		}
	}
	cout << top << endl<<tail;



	return 0;
}
