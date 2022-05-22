#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
using namespace std;
inline int read() { int x = 0, f = 1;char ch = getchar();while (ch < '0' || ch > '9') {if (ch == '-')f = -1;ch = getchar();}while (ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();	}return x * f;}
const double eps=1e-6;
const int N=550;
const int mod=1e9+7;
int s[N][N];
int main() {
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(k==1){
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++){
				cout<<i<<endl;
			}
			continue;
		}
		if(n&1){cout<<"NO"<<endl;continue;}
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				cout<<i+n*(j-1)<<' ';
			}
			cout<<endl;
		}	
	} 

	return 0;
}



