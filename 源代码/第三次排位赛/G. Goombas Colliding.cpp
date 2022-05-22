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
const int N=1e4+10;
const int mod=1e9+7;
struct egde{
	ll p,d;
} q[N];
int main() {
	ll L,g;
	cin>>L>>g;
	for(int i=1;i<=g;i++){
		cin>>q[i].p>>q[i].d;
	}
	sort(q+1,q+g+1,[](egde &a ,egde &b){
		return a.p<b.p; 
	});
	ll sum=0;
	for(int i=1;i<=g;i++){
		if(q[i].d==0){
			sum=max(sum,q[i].p);
		}else{
			sum=max(sum,L-q[i].p);
		}
	} 
	cout<<sum<<endl;
	return 0;
}


