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
int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		if((a+b)%2==0){
			cout<<((a+b)/2%9*(b-a+1)%9)%9<<endl;
		}else{
			cout<<((a+b)%9*(b-a+1)/2%9)%9<<endl;
		}
	}
	return 0;
}
//int main() {
//	int t;
//	cin>>t;
//	while(t--){
//		ll n,m;
//		cin>>n>>m;	
//		n%=9;
//		m%=9;
//		if(n>m){
//			m+=9; 
//		}
//		ll ans=0;
//		for(int i=n;i<=m;i++){
//			ans+=i;
//		}
//		cout<<ans%9<<endl;
//	}
//	return 0;
//}



