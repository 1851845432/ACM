#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int n;
double p;
double a[N], b[N];
bool f(double x) {
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i]*x <= b[i])continue;
		sum += a[i] * x - b[i];
	}
	return p * x >= sum;
}
int main() {
//  freopen("in.txt", "r", stdin);
	cin >> n >> p;
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		sum += a[i];
	}
	if (sum <= p) {
		cout << -1 << endl;
		return 0;
	}
	double l = 0, r = 1e10;
	while (r - l >= eps) {
		double mid = (l + r) / 2;
		if (f(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout<<l<<endl;
	return 0;
}
