#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int n = 10;
int a[N] = {0, 10, 10, 8, 8, 6, 3, 4, 3, 2, 1};
int arr[N];
void msort(int star, int end) {
	if (star >= end)return ;
	int mid = star + end >> 1;
	msort(star, mid);
	msort(mid + 1, end);
	int s1 = star, s2 = mid + 1, k = star;
	while (s1 <= mid && s2 <= end) {
		arr[k++] = a[s1] < a[s2] ? a[s1++] : a[s2++];
	}
	while (s1 <= mid)arr[k++] = a[s1++];
	while (s2 <= end)arr[k++] = a[s2++];
	for (int i = star; i <= end; i++) {
		a[i] = arr[i];
	}
}
int main() {
	msort(1, 10);
	for (int i = 1; i <= n; i++)cout << a[i] << " ";
	return 0;
}
