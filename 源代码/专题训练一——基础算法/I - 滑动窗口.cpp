#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e6 + 10;
int s[N];
int q[N];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	int head = 0, tail = -1;
	for (int i = 0; i < n; i++) {
		while (head <= tail && i - k >= q[head])head++;//窗口移动 
		while (head <= tail && s[q[tail]] > s[i]) tail--;//维护队列递增，求最小值（若不递增则出队） 
		q[++tail] = i;
		if (i >= k - 1)cout << s[q[head]] << ' ';
	}
	cout << endl;
	head=0,tail=-1;
	for (int i = 0; i < n; i++) {
		while (head <= tail && i - k >= q[head])head++;
		while (head <= tail && s[q[tail]] < s[i]) tail--;
		q[++tail] = i;
		if (i >= k - 1)cout << s[q[head]] << ' ';
	}

	return 0;
}
