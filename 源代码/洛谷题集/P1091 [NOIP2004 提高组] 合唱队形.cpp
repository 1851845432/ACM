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
const int N = 1e2 + 10;
const int mod = 1e9 + 7;
int a[N];
int up[N], dw[N];
int main() {
//  freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	//以i结尾的最大上升
	for (int i = 1; i <= n; i++) {
		up[i] = 1;
		for (int j = 1; j <= i - 1; j++) {
			if (a[j] < a[i] && up[i] <= up[j] + 1) {
				up[i] = up[j] + 1;
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		cout << up[i] << " ";
//	}
//	cout << endl;
	//以i开始的最大下降
	for (int i = n ; i >= 1; i--) {
		dw[i] = 1;
		for (int j = i + 1; j <= n; j++) {
			if (a[i] > a[j] && dw[i] <= dw[j] + 1) {
				dw[i] = dw[j] + 1;
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		cout << dw[i] << " ";
//	}
//	cout << endl;
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		maxx = max(maxx, dw[i] + up[i] - 1);
	}
	cout << n - maxx << endl;
	return 0;
}
