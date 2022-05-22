#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 110;
const int mod = 1e9 + 7;
int a[N][N], b[N][N], c[N][N];
int main() {
	int ra, ca;
	cin >> ra >> ca;
	for (int i = 1; i <= ra; i++) {
		for (int j = 1; j <= ca; j++) {
			cin >> a[i][j];
		}
	}
	int rb, cb;
	cin >> rb >> cb;
	for (int i = 1; i <= rb; i++) {
		for (int j = 1; j <= cb; j++) {
			cin >> b[i][j];
		}
	}
	if (ca == rb) {
		cout << ra << ' ' << cb << endl;
		for (int i = 1; i <= ra; i++) {
			for (int j = 1; j <= cb; j++) {
				int num = 0;
				for (int k = 1; k <= ca; k++) {
					num += a[i][k] * b[k][j];
				}
				c[i][j] = num;
			}
		}
		for (int i = 1; i <= ra; i++) {
			for (int j = 1; j <= cb; j++) {
				if(j==cb){
					cout<<c[i][j];
					break;
				}
				cout << c[i][j] << ' ';
			}
			cout << endl;
		}
	} else {
		printf("Error: %d != %d\n", ca, rb);
	}
	return 0;
}
