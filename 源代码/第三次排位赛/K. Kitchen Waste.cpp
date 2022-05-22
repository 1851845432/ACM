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
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
int a[N], b[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= m; i++)cin >> b[i];
	int sum = 0;
	int i=1,j=1;
	while(n){
		if(a[i]<=b[j]){
			b[j]-=a[i];
			i++;
			n--;
		}else{
			sum+=b[j];
			b[j]=0;
			j++;
		}
	}
	for(int i=1;i<=m;i++){
		sum+=b[i];
	}

	cout << sum << endl;
	return 0;
}
