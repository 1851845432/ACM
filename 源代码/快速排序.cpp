#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int a[N] = {0, 10, 10, 8, 8, 6, 3, 4, 3, 2, 1};
int n = 10;
void my_sort(int l, int r) {
	if (l >= r)return ;
	int i = l, j = r;
	int mid = a[i];
	while (i < j) {
		while (i < j && a[j] >= mid)j--;
		if (i < j)swap(a[i++], a[j]);
		while (i < j && a[i] <= mid)i++;
		if (i < j)swap(a[i], a[j--]);
	}
	a[i] = mid;
	my_sort(l, i - 1);
	my_sort(j + 1, r);
}
int main() {
//	freopen("in.txt", "r", stdin);
	my_sort(1, 10);
	for (int i = 1; i <= 10; i++)cout << a[i] << " ";
	return 0;
}
