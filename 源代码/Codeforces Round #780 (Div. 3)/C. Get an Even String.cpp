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
int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int ans = 0;
		map<char, int> m;
		for (int i = 0; i < s.size(); i++) {
			m[s[i]]++;
			if (m[s[i]] == 2) {
				ans++;
				m.clear();
			}
		}
		cout<<s.size()-2*ans<<endl;
	}
	
	return 0;
}
