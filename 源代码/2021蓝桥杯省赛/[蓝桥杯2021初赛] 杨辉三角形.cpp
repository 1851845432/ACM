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
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
ll a[N+10][N+10];
ll b[N*N];
void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (i == 1 || j == i) {
				a[i][j] = 1;
			} else {
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
		}
	}
	int ans=0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			b[++ans]=a[i][j];
		}
	}
}
int main() {
//	fre();
	int t;
	init();
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		for(int i=1;;i++){
			if(b[i]==n){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
