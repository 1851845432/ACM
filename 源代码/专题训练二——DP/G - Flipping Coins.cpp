#include<iostream>
#include<cstdio>
using namespace std;
double dp[500][500];
int main() {
	int n, k;
	cin >> n >> k;
	dp[0][0] = 1.0;
	for (int i = 0; i < k; i++) { //抛硬币是次数
		for (int j = 0; j < n; j++) { //正面向上的硬币的数量
			dp[i + 1][j] += dp[i][j] * 0.5; // 扔一次向下的硬币还是向下的概率
			dp[i + 1][j + 1] += dp[i][j] * 0.5; //硬币向上的概率
		}
		dp[i + 1][n] += dp[i][n] * 0.5; //如果硬币全部向上，再扔一次硬币，还是向上的概率
		dp[i + 1][n - 1] += dp[i][n] * 0.5; //向下的概率
	}
	double XP = 0;
	for (int i = 1; i <= n; i++) XP += dp[k][i] * i;
	printf("%.7lf\n", XP);

	return 0;
}
