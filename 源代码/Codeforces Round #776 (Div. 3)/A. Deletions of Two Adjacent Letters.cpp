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

int main() {
	int t;
	cin >> t;
	while (t--) {
		bool f=1;
		char a;
		char s[55];
		cin >> s+1 >> a;
		for(int i=1;s[i];i++){
			if(s[i]==a && i&1 ){
				f=0;
				cout<<"YES"<<endl; 
				break;
			}
		}
		if(f)cout<<"NO"<<endl;
	}
		
	return 0;
}
