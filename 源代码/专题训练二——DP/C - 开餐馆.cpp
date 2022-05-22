#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 110;
int dp[N], m[N], p[N];//dp[i]记录到第i个餐馆的最大利润 
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(dp, 0, sizeof(dp));//初始化dp数组，防止被上一次数据影响 
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) {
			cin >> m[i];
		}
		int maxx = 0;
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
			dp[i] = p[i];//每个餐馆的最低利润一定是它本身的利润 
		}
		for (int i = 1; i <= n; i++) {//遍历全部餐馆 
			for (int j = 1; j <= i; j++) {//遍历从第1个到第i个餐馆的最大利润 
				if (m[i] - m[j] > k) {//如果符合范围 
					dp[i] = max(dp[i], dp[j] + p[i]);//更新选或不选的最优解 
				}
				maxx = max(maxx, dp[i]);//记录更新最大值 
			}
		}
		cout << maxx << endl;
	}
	return 0;
}
