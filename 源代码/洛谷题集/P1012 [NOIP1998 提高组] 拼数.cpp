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
const int N = 2e1 + 10;
const int mod = 1e9 + 7;
vector<string> a;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin>>s;
		a.push_back(s);
	}
	sort(a.begin(),a.end(),[](string &x,string &y){
		return x+y>y+x;//不是直接比较x和y是因为存在300 和 30位置相同的情况：正解为30300；而单纯比较的结果为30030 
	}); 
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
