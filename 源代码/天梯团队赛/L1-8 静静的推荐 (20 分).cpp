#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
#define ll long long
int main() {
//	freopen("in.txt","r",stdin);
	int n, k, s;
	cin >> n >> k >> s;
	vector<pair<int, int> > w, q;
	int ans=0;
	map<int, int> m;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		if (a < 175)continue;
		if(b>=s)ans++;
		else m[a]++;
	}
//	cout<<m.size()<<endl;
	for(auto [x,y]:m){
		if(y>=k)ans+=k;
		else ans+=y;
	}
	cout<<ans<<endl;
	return 0;
}
