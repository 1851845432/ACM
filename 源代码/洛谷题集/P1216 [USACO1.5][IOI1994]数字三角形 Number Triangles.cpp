#include<iostream>
using namespace std;
int m[1010][1010], dp[1010][1010] = {0};

//简单的dp做法
int main() {
	int r;
	cin >> r;
	int maxn=0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> m[i][j];
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = m[i][j]+max(dp[i - 1][j], dp[i - 1][j - 1]);
			maxn=max(dp[i][j],maxn);
		}
	}
	cout << maxn << endl;
	return 0;
}
