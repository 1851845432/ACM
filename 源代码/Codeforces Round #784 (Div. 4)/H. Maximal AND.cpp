#include<bits/stdc++.h>
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
const int N=2e5+10;
const int mod=1e9+7;

int main() {
//  freopen("in.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[64]={0};
		for(int i=1;i<=n;i++){
			int x;cin>>x;
			for(int j=0;j<=30;j++){
				if(x&(1<<j))a[j]++;
			}
		}
		int sum=0;
		for(int i=30;i>=0;i--){
//			cout<<n-a[i]<<" "<<k<<endl;
			if(n-a[i]<=k){
				sum+=(1<<i);
				k-=n-a[i];
			}
		}
		cout<<sum<<endl;		
	}

	return 0;
}



