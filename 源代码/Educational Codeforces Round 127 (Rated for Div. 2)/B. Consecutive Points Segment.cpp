#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
using namespace std;
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;
int a[N];
int main() {
  freopen("in.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		puts(a[n]-a[1]-1>n?"NO":"YES");	
	} 

	return 0;
}



