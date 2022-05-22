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
int main() {
//  freopen("in.txt", "r", stdin);
	char c;
	char ch;
	int a = 0, f = 1, sum = 0, x = 0;
	bool d = 0;
	while (cin >> c) {
		if (c == '-') {
			int y = f * a;
			if (d) sum -= y;
			else sum += y;
			f = -1;
			a = 0;
		} else if (c >= '0' && c <= '9') {
			a = a * 10 + (c - '0');
		} else if (c == '+') {
			int y = f * a;
			if (d) sum -= y;
			else sum += y;
			a = 0;
			f = 1;
		} else if (c == '=') {
			int y = f * a;
			if (d) sum -= y;
			else sum += y;
			a = 0;
			f = 1;
			d = 1;
		} else {
			ch = c;
			int y = f * a;
			if (y == 0)y = 1;
			if (d)x -= y;
			else x += y;
			f = 1;
			a = 0;
		}
	}
	sum -= (f * a);
	if (sum == 0)printf("%c=0.000", ch);
	else printf("%c=%.3lf", ch, -1.0 * sum / x);
	return 0;
}
