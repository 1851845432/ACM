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
int a[300];
int main() {
//  freopen("in.txt", "r", stdin);
	int n;
	scanf("%d",&n);
	int ans = 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			a[++ans] = i;
		}
	}
	if (ans == 0) {
		cout << 1 << endl << n << endl;
		return 0;
	}
	if (ans == 1) {
		cout << 1 << endl << a[ans] << endl;
		return 0;
	}
	int mx = 0, u = 0;
	for (int i = 1; i <= ans; i++) {
		int len = 1;
		int sum=a[i]; 
		for (int j = i; j < ans; j++) {
			if (a[j+1] - a[j] == 1 && n%(sum*a[j+1])==0) {
				sum*=a[j+1];
				len++;
			} else {
				break;
			}
		}
		if (len > mx) {
			mx = len;
			u = i;
		}
	}
	cout << mx << endl;
	for (int i = u; i < u + mx; i++) {
		cout << a[i];
		if (i != u + mx - 1)cout << "*";
	}
	return 0;
}
