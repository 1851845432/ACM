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
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
struct egde {
	int x, num, i;
};
int main() {
//  freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<egde> a(n + 1);
		a[0].num=INF;
		for (int i = 1; i <= n; i++) {
			a[i].i = i;
			cin >> a[i].num;
		}
		sort(a.begin(), a.end(), [](egde & x, egde & y) {
			return x.num > y.num;
		});
		ll ans = 0, sum = 0;
		for (int i = 1; i <= n; i++) {
			if (i % 2)a[i].x = ++ans;
			else a[i].x = -ans;
			sum += 2LL * abs(ans) * a[i].num;
		}
		cout<<sum<<endl;
		sort(a.begin(),a.end(),[](egde &x, egde & y){
			return x.i<y.i;
		});
		cout<<0<<" ";
		for(int i=1;i<=n;i++){
			cout<<a[i].x<<" ";
		}cout<<endl;
		
	}
	return 0;
}
