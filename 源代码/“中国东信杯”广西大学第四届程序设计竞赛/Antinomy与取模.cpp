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
using namespace std;
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;
ll gcd(ll x,ll y){
    return y==0?x:gcd(y,x%y);
// 	if(y==0) return x;
// 	else gcd(y,x%y);
}

ll lcm(ll x,ll y){
	return x/gcd(x,y)*y;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		ll a,b,l,r;
		cin>>a>>b>>l>>r;
		ll x=lcm(a,b);
		if(x>r){
			cout<<-1<<endl;
			continue;
		}
		for(int i=1;i*x<=r;i++){
			ll y=1LL*i*x;
			if(y>=l && y<=r){
				cout<<y<<endl;
				break;
			}
			if(y>r){
				cout<<-1<<endl;
			}
		}
	}
	return 0;
}



