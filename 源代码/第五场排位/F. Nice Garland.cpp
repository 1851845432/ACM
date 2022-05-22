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
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
string s[6] = {"RGB", "RBG", "GBR", "GRB", "BRG", "BGR"};
int v[6];
int main() {
	int n;
	cin >> n;
	string a;
	cin >> a;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j] != s[i][j % 3])v[i]++; //记录六种情况需要改变的次数
		}
	}
	int minn = 0;
	for (int i = 0; i < 6; i++) {
		if (v[minn] > v[i])minn = i;//记录最小改变的排列下标 
	}
	cout<<v[minn]<<endl;
	for(int i=0;i<n;i++){
		cout<<s[minn][i%3];
	} 
	cout<<endl;
	return 0;
}
