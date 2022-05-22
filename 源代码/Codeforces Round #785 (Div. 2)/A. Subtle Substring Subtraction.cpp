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
int a[N];
int main() {
  freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += s[i] - 'a'+1;
		}
		if (n % 2 == 0) {
			printf("Alice %d\n", sum);
		} else {
			int x=s[0]>s[n-1]?s[n-1]-'a'+1:s[0]-'a'+1;
			sum-=x;
			printf("%s %d\n",sum>x?"Alice":"Bob",abs(sum-x));
		}
	}
	return 0;
}
