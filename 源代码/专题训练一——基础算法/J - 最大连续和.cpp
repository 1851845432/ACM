#include<iostream>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll s[N], a[N], q[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];//���Ӷκ�����ǰ׺���Ż�
	}
	ll  maxn = -1e9;
	int head = 0,tail = 0;
	for (int i = 1; i <= n; i++) {

		while (head <= tail && q[head] + m < i)head++; //����������m,����ͷ���ӡ�
		maxn = max(maxn, s[i] - s[q[head]]); //�ж���������
		while (head <= tail && s[q[tail]] >= s[i])tail--; //���βԪ�ش��ڲ���Ԫ�أ�Ϊ���ֶ��е�����������β����
		q[++tail] = i; //��¼����Ԫ�ص��±�
	}
	cout << maxn << endl;
	return 0;
}
