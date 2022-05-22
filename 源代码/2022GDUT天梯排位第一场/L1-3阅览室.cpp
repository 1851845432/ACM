#include<stdio.h>
#include<string.h>
struct edge {
	int s, e;
} d[1100];
int  time(char *s) {
	int ans = 0;
	ans = ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + (s[4] - '0');
	return ans;
}
char s[10];
int main() {
	int n;
	scanf("%d", &n);
	while (n) {
		int book;
		scanf("%d", &book);
		char ch;
		getchar();
		scanf("%c", &ch);
		getchar();
		if (ch == 'S') {
			scanf("%s", s);
			getchar();
			d[book].s = time(s);
			//	printf("%d\n",d[book].s);
		} else {
			scanf("%s", s);
			getchar();
			d[book].e = time(s);
				//printf("%d\n",d[book].e);
		}
		if (!book) {
			int sum = 0, ans = 0;
			for (int i = 1; i <= 1000; i++) {
				if (d[i].s && d[i].e) {
					ans++;
					sum += d[i].e-d[i].s;
				}
			}
			if (sum == 0) {
				printf("0 0\n");
			} else {
				int ave = (int)((1.0*sum/ ans) + 0.5);
				printf("%d %d\n", ans, ave);
			}
			n--;
			memset(d, 0, sizeof(d));
		}
	}
	return 0;
}
