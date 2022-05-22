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
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;
struct egde{
	int zb,w,id;
} ;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<egde> p(m);
		for(int i=0;i<m;i++){
			cin>>p[i].zb>>p[i].w;
			p[i].id=i+1; 
		}
		int sum=0;
		sort(p.begin(),p.end(),[](egde &a , egde &b){
			return a.w<b.w;
		});
		
//		for(auto x:p){
//			cout<<x.zb<<' '<<x.w<<endl;
//		}
		
		for(int i=0;i<m;i++){
			if(i<2*n)sum+=p[i].w;
			else p.pop_back();
		}
		sort(p.begin(),p.end(),[](egde &a , egde &b){
			return a.zb<b.zb; 
		});
		cout<<sum<<endl;
		for(int i=0;i<n;i++){
			cout<<p[i].id<<' '<<p[2*n-i-1].id<<endl;
		}
	}

	return 0;
}



