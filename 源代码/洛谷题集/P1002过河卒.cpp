#include<iostream>
using namespace std;
bool s[50][50];
long long dp[50][50];
const int a[] = { -2,2 };
const int b[] = { -1,1 };
int main()
{
	int n, m,x,y;
	cin >> n >> m>>x>>y;
	n += 1; m += 1; x += 1; y += 1;
	s[x][y] = 1;//���??��λ��
	//���������ߵ�λ�ý��б��
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (x + a[i] >= 0 && x + a[i] <= n)s[x + a[i]][y + b[j]] = 1;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (y + a[i] >= 0 && y + a[i] <= m)s[x + b[j]][y + a[i]] = 1;
	//��״̬����f(i,j)=f(i?1,j)+f(i,j?1)  ��ʼ����
	dp[0][1] = 1;//��ʼ��
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j])continue;//���������ס������
			else  dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout << dp[n][m] << endl;
	return 0;
 }


