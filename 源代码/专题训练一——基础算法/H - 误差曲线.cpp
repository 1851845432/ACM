#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e4 + 8;
int n;
double a[N], b[N], c[N];
inline double f(double x) {
	double maxn = -1e9;
	for (int i = 0; i < n; i++) {
		maxn = max(maxn, (a[i] * x * x + b[i] * x + c[i]));
	}
	return maxn;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		double esp = 1e-9;
		double l = 0, r = 1000;
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf%lf", &a[i], &b[i], &c[i]);
		}
		while (r - l >= esp) {
			double mar = (r - l) / 3.0;
			double ml, mr ;
			ml = l + mar;
			mr = r - mar;
			if (f(ml) > f(mr))l = ml;
			else r = mr;
		}
		printf("%.4lf\n", f(l));
	}
	return 0;
}
