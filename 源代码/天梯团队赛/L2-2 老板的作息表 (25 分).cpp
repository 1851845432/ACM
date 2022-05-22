#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
#define ll long long
struct egde {
	int ha, ma, sa, hb, mb, sb;
};
int main() {
//	freopen("in.txt","r",stdin);
	int n;
	cin >> n;
	vector<egde>q;
	int ha, ma, sa, hb, mb, sb;
	for (int i = 1; i <= n; i++) {
		scanf("%d:%d:%d - %d:%d:%d", &ha, &ma, &sa, &hb, &mb, &sb);
		q.push_back({ha, ma, sa, hb, mb, sb});
	}
	sort(q.begin(),q.end() ,[](egde & a, egde & b) {
		if (a.ha == b.ha) {
			if (a.ma == b.mb) {
				return a.sa < b.sb;
			}
			return a.ma < b.mb;
		}
		return a.ha < b.ha;
	});
	
//	puts("");
//	for(int i=1;i<=n;i++){
//		printf("%02d:%02d:%02d - %02d:%02d:%02d\n", q[i].ha, q[i].ma, q[i].sa, q[i].hb, q[i].mb, q[i].sb);
//	}
//	puts("");
	if (q[0].ha != 0 || q[0].ma != 0 || q[0].sa != 0) {
		printf("00:00:00 - %02d:%02d:%02d\n", q[0].ha, q[0].ma, q[0].sa);
	}
	for (int i = 1; i < n; i++) {
		if (q[i].ha == q[i - 1].hb && q[i].ma == q[i - 1].mb && q[i].sa == q[i - 1].sb) {
			continue;
		}
		printf("%02d:%02d:%02d - %02d:%02d:%02d\n", q[i - 1].hb, q[i - 1].mb, q[i - 1].sb, q[i].ha, q[i].ma, q[i].sa);
	}
	n--;
	if (q[n].hb != 23 && q[n].mb != 59 && q[n].sb != 59) {
		printf("%02d:%02d:%02d - 23:59:59\n", q[n].hb, q[n].mb, q[n].sb);
	}
	return 0;
}
