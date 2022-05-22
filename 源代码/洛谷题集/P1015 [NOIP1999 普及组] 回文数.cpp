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
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e2 + 10;
const int mod = 1e9 + 7;
vector<int> a, b;
int main() {
	int k;
	cin >> k;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')a.push_back(s[i] - '0');
		else a.push_back(s[i] - 'A' + 10);//注意对十六进制数进行转换
	}
	b = a;
	reverse(a.begin(), a.end());
//	for (int i = 0; i < a.size(); i++)cout << a[i];
//	for (int i = 0; i < b.size(); i++)cout << b[i];
	int ans = 0;
	if (a == b) {
		printf("STEP=%d\n", ans);
		return 0;
	}
	while (ans <= 30) {
		ans++;
		int jw = 0;
		for (int i = 0; i < a.size(); i++) {
			a[i] += b[i] + jw;
			jw = a[i] / k;
			a[i] %= k;
		}
		if (jw)a.push_back(jw);
		b = a;
		reverse(b.begin(), b.end());
		if (a == b) {
			printf("STEP=%d\n", ans);
			return 0;
		}
	}
	cout << "Impossible!" << endl;
	return 0;
}
