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
int a[N],b[N];
bool solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	for(int i=n;i>1;i-=2){
		if(a[i]<a[i-1]){
			swap(a[i],a[i-1]);
		} 
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i])return 0;
	}
	return 1;
}
int main() {
  freopen("in.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--){
		puts(solve()?"YES":"NO");
	}

	return 0;
}



