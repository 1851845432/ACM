#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
const int N = 2e5 + 10;
int p[N];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int x = log2(n - 1);
		int y = 1 << x;
		for (int i = y - 1; i >= 0; i--)cout << i << ' ';
		for (int i = y; i < n; i++)cout << i << ' ';
		cout << endl;
	}

	return 0;
}


