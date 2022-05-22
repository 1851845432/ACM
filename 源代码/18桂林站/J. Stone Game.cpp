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
int a[N], b[N];
int main() {
//  freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	int cnt = 1;
	while (t--) {
		int n;
		cin >> n;
		ll sum = 0;
		for (int i = 1; i <= n; i++) scanf("%d", a + i), sum += a[i], b[i] = INF;
//		cout<<sum<<endl;
		if (n == 1) {
			puts(a[1] & 1 ? "Alice" : "Bob");
			continue;
		}
		vector<int> w;
		a[0] = a[n + 1] = INF;
		for (int i = 1; i <= n; i++) {
			if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
				b[i] = 0;
				w.push_back(i);
			}
		}
//		for(auto x:w){
//			cout<<x<<" ";
//		}
//		cout<<endl;
		for (auto x : w) {
			for (int j = x + 1; j <= n && a[j] > a[j - 1]; j++)b[j] = b[j - 1] + 1;
			for (int j = x - 1; j >= 1 && a[j] > a[j + 1]; j--) {
				if (a[j] > a[j - 1] && a[j] > a[j + 1]) { //¼«´ó
					b[j] = max(b[j - 1], b[j + 1]) + 1;
				} else {
					b[j] = b[j + 1] + 1;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			sum -= b[i];
		}
//		cout<<endl;
//		cout<<sum<<endl;
		printf("Case %d: %s\n", cnt++, sum & 1 ? "Alice" : "Bob");
	}
	return 0;
}
