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
int w[10010];
int main() {
//  freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			int a;
			cin >> a;
			continue;
		}
		for (int j = 1; j <= x; j++) {
			int a;
			cin >> a;
			m[a] = 1;
		}
	}
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (m[a])continue;
		m[a] = 1;
		w[++ans] = a;
	}
	if (!ans)cout << "No one is handsome" << endl;
	else {
		for (int i = 1; i <= ans; i++) {
			if (i == ans)printf("%05d\n",w[i]);
			else printf("%05d ",w[i]);
		}
	}
	return 0;
}
