#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5 + 10;
int  t[N], q[N];
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}
int main() {
	int n;
	n = read();
	int s;
	for (int i = 1; i <= n; i++) {
		s= read();
		t[s] = i;
	}
	int top = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		x = read();
		if(t[x]>q[top])q[++top]=t[x];
		else q[lower_bound(q+1,q+top+1,t[x])-q]=t[x];
	}
	printf("%d", top);
	return 0;
}
