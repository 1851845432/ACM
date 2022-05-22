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
#define forr(x) for(int i=1;i<=x;i++)
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;
ll a[N];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main() {
//  freopen("in.txt", "r", stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	} 
	sort(a+1,a+n+1);
	ll minn=INF;
	for(int i=1;i<n;i++){
		minn=min(minn,a[i+1]-a[i]);//公差应该为所以差值的最大公约数！！ 
	}
	if(minn==0){cout<<n;return 0;}//考虑公差为0的情况； 
	ll sum=1LL*(a[n]-a[1])/minn+1;
	printf("%lld",sum);
	return 0;
}



