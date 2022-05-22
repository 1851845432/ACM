#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
int n, k;
string num;
ll dp[50][20];
ll s(int l, int r) {
	ll sum = 0;
	for (int i = l; i <= r; i++) {
		sum = sum * 10 + (num[i] - '0');
	}
	return sum;
}
int main() {
	cin >> n >> k >> num;
	for (int i = 0; i < n; i++) dp[i][0] = s(0, i);
	for (int i = 0; i < n; i++) { //�ڵڼ�λ��ǰ����˺�
		for (int j = 1; j <= k; j++) { //������ٸ��˺�
			for (int l = 0; l < i; l++) { //����˺ŵ�λ��
				dp[i][j]=max(dp[i][j],dp[l][j-1]*s(l+1,i));
			}
		}
	}
	cout<<dp[n-1][k]<<endl;


	return 0;
}
