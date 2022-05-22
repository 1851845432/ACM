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
int main() {
//  freopen("in.txt", "r", stdin);
	string s;
	cin >> s;
	int v[20] = {0};
	for (auto ch : s) {
		v[ch - '0']++;
	}
	vector<int>a, b;
	for (int i = 9; i >= 0; i--) {
		if (v[i])a.push_back(i);
	}
	for (auto ch : s) {
		int x = ch - '0';
		for (int i = 0; i < a.size(); i++) {
			if (x == a[i]) {
				b.push_back(i);
			}
		}
	}
	printf("int[] arr = new int[]{");
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
		if (i != a.size() - 1)cout << ",";
	}
	cout << "};" << endl;
	printf("int[] index = new int[]{");
	for (int i = 0; i < b.size(); i++) {
		cout << b[i];
		if (i != b.size() - 1)cout << ",";
	}
	cout << "};" << endl;
	return 0;
}
//18575912565
//int[] arr = new int[]{9,8,7,6,5,2,1};
//int[] index = new int[]{6,1,4,2,4,0,6,5,4,3,4};
