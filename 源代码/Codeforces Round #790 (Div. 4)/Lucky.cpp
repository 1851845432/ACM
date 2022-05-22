#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;

int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		ll ans1=0,ans2=0;
		for(int i=0;i<s.size();i++){
			if(i<3)ans1+=s[i]-'0';
			else ans2+=s[i]-'0';
		}
		puts(ans1==ans2?"YES":"NO");
	}

	return 0;
}



