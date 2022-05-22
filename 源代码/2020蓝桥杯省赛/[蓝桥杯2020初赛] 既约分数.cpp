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
#define INF 0x3f3f3f3f
#define ll long long
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=2e3+10;
const int mod=1e9+7;
int prime[N];
bool v[N];	
int ans=0;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main() {
//  freopen("in.txt", "r", stdin);
	for(int i=1;i<=2020;i++){
		for(int j=1;j<=2020;j++){
			if(gcd(i,j)==1){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
		

	return 0;
}



