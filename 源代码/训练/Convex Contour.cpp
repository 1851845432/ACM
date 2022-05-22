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
const double pi = acos(-1.0);
double cal(char ch) {
	if (ch == 'S')return 3;
	else if (ch == 'T') {
		return 2+sqrt(2-sqrt(3)) ;
	} else {
		return 1 + pi/2.0;
	}
}
int main() {
	freopen("in.txt", "r", stdin);
	int n;
	cin>>n;
	char s[n + 1];
	scanf("%s", s);
	if (n == 1) {
		if(s[0]=='S')cout<<4<<endl;
		else if(s[0]=='T')cout<<1+2*sqrt(1.25)<<endl;
		else cout<<pi<<endl;
	}
	double ans = (n - 2) * 2;
	ans += cal(s[1]);
	ans += cal(s[n]);
	cout << ans << endl;
	return 0;
}
