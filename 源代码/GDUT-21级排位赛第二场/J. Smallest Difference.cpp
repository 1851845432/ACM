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
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int w[N];
int a[N];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		memset(w,0,sizeof(w));
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			w[a[i]]++;
		}
		sort(a+1,a+n+1);
		int l=unique(a+1,a+n+1)-a-1;
		int maxx=0;
		for(int i=1;i<=l;i++){
			if(a[i]+1==a[i+1] && i+1<=l){
				maxx=max(maxx,w[a[i]]+w[a[i+1]]);
			}else{
				maxx=max(maxx,w[a[i]]);
			}
		}
		cout << maxx << endl;
	}
	return 0;
}
