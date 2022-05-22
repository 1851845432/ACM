#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define ll long long  
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = (1 << 32) - 1;
//ll ksm(int a, int n) {
//	ll ans = 1;
//	while (n) {
//		if (n & 1)ans = 1ll * ans * a;
//		a *= a;
//		n >>= 1;
//	}
//	return ans;
//}
//ll _hash(char ch, int i, int n) {
//	int x = (int)ch;
//	return 1ll * x * ksm(31, n - i - 1);
//}
int main() {
//  freopen("in.txt", "r", stdin);
	//freopen("in.out","w",stdout);
//	string s;
//	cout<<(int)'f'<<" "<<(int)'E'<<endl;
//	cout<<(int)'e'<<" "<<(int)'d'<<endl;
//	cout<<(int)'H'<<" "<<(int)'s'<<endl;
//	cout<<(int)'I'<<" "<<(int)'T'<<endl;
//	while (getline(cin,s)) {
//		ll ans = 0;
//		int n = s.size();
//		for (int i = 0; i < n; i++) {
//			ans += _hash(s[i],i,n);
//		}
//		cout<<ans<<endl;
//	}
	string s[2];
	s[0] = "Hs";
	s[1] = "IT";
	int k;
	cin >> k;
	int n;
	if (k & 1)n = (k + 1) >> 1;
	else n = k >> 1;
	//二进制枚举
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))cout << s[1];
			else cout << s[0];
		}
		cout << endl;
	}
	return 0;
}
