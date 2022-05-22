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
/*
存在z在<x,y>之间插入时，不改变题差值，所以考虑1和x插入的位置考虑贡献。 
*/
int main() {
  freopen("in.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		ll ans=0;
		int mi=INF,mx=-INF;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mi=min(mi,a[i]);
			mx=max(mx,a[i]);
			if(i>=2)ans+=abs(a[i]-a[i-1]);
		}
		if(mi>1)ans+=min((mi-1)*2,min(a[1],a[n])-1);
		if(x>mx) ans+=min((x-mx)*2,x-max(a[1],a[n]));
		cout<<ans<<endl;
	}

	return 0;
}

