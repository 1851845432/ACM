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
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
int main() {
	freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	double a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x >= 60)a++;
		if (x >= 85)b++;
	}
	a=a/n*100;
	b=b/n*100;
	printf("%d\%\n", (int)(a+0.5));
	printf("%d\%\n", (int)(b+0.5));
	return 0;
}
