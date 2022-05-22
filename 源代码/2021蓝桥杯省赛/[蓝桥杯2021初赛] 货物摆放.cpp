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
	ll n = 2021041820210418;
	int ans = 0;
	vector<ll> q;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if(i*i==n){
				q.push_back(i);
				break;
			}
			q.push_back(i);
			q.push_back(n / i);
		}
	}
	int l=q.size();
	for(int i=0;i<l;i++){
		for(int j=0;j<l;j++){
			if(n%(q[i]*q[j])==0){
//			cout<<q[i]<<" "<<q[j]<<endl;
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
