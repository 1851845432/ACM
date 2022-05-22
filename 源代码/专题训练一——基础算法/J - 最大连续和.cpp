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
		s[i] = s[i - 1] + a[i];//求子段和利用前缀和优化
	}
	ll  maxn = -1e9;
	int head = 0,tail = 0;
	for (int i = 1; i <= n; i++) {

		while (head <= tail && q[head] + m < i)head++; //如果区间大于m,将队头出队。
		maxn = max(maxn, s[i] - s[q[head]]); //判断区间最大和
		while (head <= tail && s[q[tail]] >= s[i])tail--; //如队尾元素大于插入元素，为保持队列单调递增，队尾出列
		q[++tail] = i; //记录插入元素的下标
	}
	cout << maxn << endl;
	return 0;
}
