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
const int N=1e3+10; 
const int mod=1e9+7;
int a[N];
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int x,sum=0;
		if(n%3==1){
			x=1;
		}else{
			x=2;
		}
		while(n!=sum){
			cout<<x;
			sum+=x;
			x=3-x;
		}
		cout<<endl;	
	} 

	return 0;
}



