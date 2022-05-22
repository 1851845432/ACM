#include<iostream>
#include<cstdio>
using namespace std;
double dp[500][500];
int main() {
	int n, k;
	cin >> n >> k;
	dp[0][0] = 1.0;
	for (int i = 0; i < k; i++) { //��Ӳ���Ǵ���
		for (int j = 0; j < n; j++) { //�������ϵ�Ӳ�ҵ�����
			dp[i + 1][j] += dp[i][j] * 0.5; // ��һ�����µ�Ӳ�һ������µĸ���
			dp[i + 1][j + 1] += dp[i][j] * 0.5; //Ӳ�����ϵĸ���
		}
		dp[i + 1][n] += dp[i][n] * 0.5; //���Ӳ��ȫ�����ϣ�����һ��Ӳ�ң��������ϵĸ���
		dp[i + 1][n - 1] += dp[i][n] * 0.5; //���µĸ���
	}
	double XP = 0;
	for (int i = 1; i <= n; i++) XP += dp[k][i] * i;
	printf("%.7lf\n", XP);

	return 0;
}
