#include<iostream>
using namespace std;
int s[10]={1}, v[10];
int n;
void dfs(int x, int ans) {
	if (ans == n) {
		for (int k =1; k < x - 1; k++) {
			cout << s[k] << "+";
		}
		cout << s[x - 1] << endl;
		return;
	}
	for (int i = s[x-1]; i < n; i++) {//��֤����һ�����ڵ���ǰ�� 
		if (!s[x] && ans+i<=n) {//���ǰ��ͼӺ������n���򷵻� 
			s[x] = i;
			dfs(x + 1, ans + s[x]);
			s[x] = 0;
		}
	}
	return;
}
int main() {
	cin >> n;
	dfs(1, 0);
	return 0;
}
