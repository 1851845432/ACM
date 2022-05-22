#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define ll long long
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define forr(x) for(int i=1;i<=x;i++)
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
string s, c("0123456789ABCDEF");
int ans;
bool f = 0;
struct egde {
	char ch;
	string s;
	int cnt;
} q[N];
string Get(int cnt) {
	string a = "";
	if (cnt <= 2)f = 1;
	while (cnt) {
		a += c[cnt % 16];
		cnt /= 16;
	}
	reverse(a.begin(), a.end());
	return a;
}
int main() {
//  freopen("in.txt", "r", stdin);
	while (cin >> s) {
		int n = s.size(), cnt = 1;
		ans = 0;
		f = 0;
		for (int i = 1; i < n; i++) {
			if (s[i] == s[i - 1])cnt++;
			else q[ans++] = egde{s[i - 1], Get(cnt), cnt}, cnt = 1;
		}
		q[ans++] = egde{s[n - 1], Get(cnt), cnt};
		int u = 0;
		for (int i = 0; i < ans; i++) {
//			cout<<u<<endl;
			if (q[i].cnt == 1) {//只有单个字符
				u = i;
				if (i < ans && q[i].ch > q[i + 1].ch) break;//如果变优则直接退出
			} else if (q[i].cnt == 2)u = i;//两个字符
			else if (q[i].s == "1" + string(q[i].s.size() - 1, '0'))u = i;//三个字符删去会变短
			if (!f)break;
		}
		q[u].cnt--;
		q[u].s = Get(q[u].cnt);
		for (int i = 0; i < ans; i++) {
			if (q[i].cnt == 0)continue;
			if (q[i].cnt == 1)cout << q[i].ch;
			else cout << q[i].ch << q[i].s;
		}
		cout << endl;
	}
	return 0;
}
