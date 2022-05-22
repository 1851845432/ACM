#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
using namespace std;
inline int read() { int x = 0, f = 1;char ch = getchar();while (ch < '0' || ch > '9') {if (ch == '-')f = -1;ch = getchar();}while (ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();	}return x * f;}
const double eps=1e-6;
const int N=510;
const int mod=1e6+7;
int c[N][N];
void init(){
	c[0][0]=1;
	for(int i=1;i<N;i++){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
}
int main() {
	int t;
	cin>>t;
	init();
	int ans=0;
	while(t--){
		int n,m,k,sum=0;
		cin>>n>>m>>k;
		for(int i=0;i<16;i++){
			int cnt=0,h=n,l=m;
			if(i&1){cnt++,h--;}
			if(i&2){cnt++,h--;}
			if(i&4){cnt++,l--;}
			if(i&8){cnt++;l--;}
			if(cnt&1)sum=(sum-c[h*l][k]+mod)%mod;
			else sum=(sum+c[h*l][k])%mod;
		}
		printf("Case %d: %d\n",++ans,sum);
	
	}

	return 0;
}



