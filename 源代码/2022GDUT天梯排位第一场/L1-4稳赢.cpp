#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
string a = "ChuiZi";
string b = "JianDao";
string c = "Bu";
int main() {
	int k, ans = 0;
	cin >> k;
	k++;
	string s;
	while (cin >> s) {
		ans++;
		if(s=="End")break;
		if (k == 0) {
			cout << k << endl;
		}
		if (ans % k) {
			if (s == a) {
				cout << c << endl;
			} else if (s == b) {
				cout << a << endl;
			} else if (s == c) {
				cout << b << endl;
			}
		}
		else{
			cout<<s<<endl;
		}
	}
	return 0;
}
