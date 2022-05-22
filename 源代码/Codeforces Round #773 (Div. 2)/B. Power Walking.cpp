#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#include<set>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		set<int> s;
		for(int i=1;i<=n;i++){
			int x;cin>>x;
			s.insert(x);
		}
		for(int i=1;i<=n;i++){
			cout<<max(i,(int)s.size())<<' ';
		}
		cout<<endl;
	}

	return 0;
}


