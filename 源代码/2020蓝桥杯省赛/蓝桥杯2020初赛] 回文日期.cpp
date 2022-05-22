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
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isHF(int x) {
	x = x % 10 * 1000 + x / 10 % 10 * 100 + x / 100 % 10 * 10 + x / 1000;
//	cout<<x<<endl;
	int m = x / 100;
	int d = x % 100;
	if (x % 4 == 0 && x % 100 != 0 || x % 400 == 0) {
		mon[2] = 29;
	} else {
		mon[2] = 28;
	}
	if (m >= 1 && m <= 12 && d >= 1 && d <= mon[m]) {
		return 1;
	} else {
		return 0;
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		ll a;
		cin >> a;
		ll y = a / 10000;
		for (ll i = y + 1; i <= 8999; i++) {
			if (isHF(i)) {
				cout << i * 10000 + i % 10 * 1000 + i / 10 % 10 * 100 + i / 100 % 10 * 10 + i / 1000 << endl;
				break;
			}
		}
		for (ll i = y + 1; i <= 8999; i++) {
			if (isHF(i) && i / 1000 == i / 10 % 10 && i / 100 % 10 == i % 10 && i/10%10 !=i%10) {
				cout << i * 10000 + i % 10 * 1000 + i / 10 % 10 * 100 + i / 100 % 10 * 10 + i / 1000 << endl;
				break;
			}
		}
	}
	return 0;
}
