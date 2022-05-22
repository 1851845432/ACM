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
int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		unordered_map<char,int> m;
		for(auto x:s){
			if(m[x])continue;
			m[x]++;
		}
		bool f=1;
		int n=m.size();
		for(int i=0;i<s.size();i++){
			if(s[i]!=s[i%n]){
				f=0;break;
			}
		}
		puts(f?"YES":"NO");
	}
	
	return 0;
}
