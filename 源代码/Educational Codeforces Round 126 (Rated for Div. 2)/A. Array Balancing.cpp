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
const int N=50+10;
const int mod=1e9+7;
int a[N],b[N]; 
int main() {
//  freopen("in.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		ll sum=0;
		for(int i=1;i<n;i++){
			int x=abs(a[i]-a[i+1])+abs(b[i]-b[i+1]);
			int y=abs(a[i]-b[i+1])+abs(b[i]-a[i+1]);
			if(x<y){
				sum+=1ll*x;
			}else{
				sum+=1ll*y;
				swap(a[i+1],b[i+1]);
			}
		}
		cout<<sum<<endl; 
		
	}

	return 0;
}



