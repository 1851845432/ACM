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
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int a[N];
int main() {
//  freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		memset(a,0,sizeof(a));
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin>>a[i];
		}
		if (n == 1) {
			if (a[n] == 1) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
			continue;
		}
		sort(a+1,a+n+1,[](int &x,int &y){
			return x>y;
		});
		bool f=0; 
		if(a[1]-a[2]>=2)f=1;
		if(f){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
		
		
		
	}
	return 0;
}
