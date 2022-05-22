#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int a[N];
int main() {
	int t;
//	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		multiset<ll> st;
		for (int i = 1; i <= n; i++) {
			ll a;
			cin>>a;
			st.insert(a);
		}
		int ans = 0;
		for (auto &k:st) {
			ll w=k*x;
			auto it= st.find(w);
			if(it ==st.end())ans++;
			else st.erase(it);
		}
		cout << ans << endl;
	}
	fclose(stdin);
	return 0;
}
