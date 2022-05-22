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
int a[N];
int main() {
//  freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	int cnt = 1;
	while (t--) {
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
		}
		sort(a + 1, a + n + 1);
		int l = unique(a + 1, a + n + 1) - a - 1;
		if (l == 1) {
			if (a[1] == 1)ans = 1;
			printf("Case %d: %d\n", cnt++, ans);
			continue;
		}
		int gcd = a[2] - a[1];
		for (int i = 3; i <= l; i++) {
			gcd = __gcd(gcd, a[i] - a[i - 1]);
		}
//		cout<<"Gcd=="<<gcd<<endl;
		if (gcd == 1) { //存在连续的数-1
			ans = -1;
			printf("Case %d: %d\n", cnt++, ans);
			continue;
		}
		ans=((a[1]-1)/gcd+1)*gcd-a[1];
		for(int i=2;i*i<=n;i++){
			if(gcd%i==0){
				ans=min(ans,((a[1]-1)/i+1)*i-a[1]);
			}
		}
		printf("Case %d: %d\n", cnt++, ans);
	}
	return 0;
}
