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
const int N=5e3+10;
const int mod=1e9+7;
int a[N];
int main() {
	int n,k;
	cin>>n>>k;
	if(n==1){
		cout<<"YES"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]>k){
			cout<<"NO"<<endl;
			return 0;
		}
	} 
	cout<<"YES"<<endl;

	return 0;
}



