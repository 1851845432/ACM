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
ll a[N];
struct egde {
	int x, y, z;
};
int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		forr(n) {
			cin >> a[i];
		}
		//如果最后两个递减则肯定不能实现操作 
		if(a[n]<a[n-1]){cout<<-1<<endl;continue;}
		if(a[n]>=0){
			cout<<n-2<<endl;
			for(int i=1;i<=n-2;i++){
				printf("%d %d %d\n",i,n-1,n);
			}
		} else{
			bool f=1;
			for(int i=1;i<=n-2;i++){
				if(a[i]>a[i+1]){
					f=0;break;
				}
			}
			if(f)cout<<0<<endl;
			else cout<<-1<<endl;
		}
		
	}
	return 0;
}
