#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 110;
int dp[N], m[N], p[N];//dp[i]��¼����i���͹ݵ�������� 
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(dp, 0, sizeof(dp));//��ʼ��dp���飬��ֹ����һ������Ӱ�� 
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) {
			cin >> m[i];
		}
		int maxx = 0;
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
			dp[i] = p[i];//ÿ���͹ݵ��������һ��������������� 
		}
		for (int i = 1; i <= n; i++) {//����ȫ���͹� 
			for (int j = 1; j <= i; j++) {//�����ӵ�1������i���͹ݵ�������� 
				if (m[i] - m[j] > k) {//������Ϸ�Χ 
					dp[i] = max(dp[i], dp[j] + p[i]);//����ѡ��ѡ�����Ž� 
				}
				maxx = max(maxx, dp[i]);//��¼�������ֵ 
			}
		}
		cout << maxx << endl;
	}
	return 0;
}
