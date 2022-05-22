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
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int main() {
	map<char, int> q;
	string a ;
	cin >> a;
	int num = 0;
	for (int i = 0; i < a.size(); i++) {
		q[a[i]]++;
		if (a[i] >= 'a' && a[i] <= 'z')num++;
	}
	//ÅÐ¶Ï·ûºÅ 
	if (q['<'] != q['>'] || q['<'] == 0 || q['>'] == 0 || q['/'] == 0 || q['<'] != q['/'] * 2 || num < q['<']) {
		printf("Impossible\n");
		return 0;
	}
	//ÅÐ¶Ï×ÖÄ¸ 
	for (auto [x, y] : q) {
		if (x >= 'a' && x <= 'z') {
			if (y % 2) {
				printf("Impossible\n");
				return 0;
			}
		}
	}
	vector<string> s;
	string t;
	for (auto & [x, y] : q) {
		if (x >= 'a' && x <= 'z') {
			y /= 2;
			while (y) {
				if (q['<'] == 2) {
					t += x;
				} else {
					t += x;
					s.push_back(t);
					t.clear();
					q['<']-=2;
				}
				y--;	
			}	
		}
	}
	if(t.size())s.push_back(t);
	for (auto x : s) {
		cout << "<" << x << ">" << "</" << x << ">";
	}
	return 0;
}
