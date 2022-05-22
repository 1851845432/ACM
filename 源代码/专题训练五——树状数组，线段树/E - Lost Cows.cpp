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
const int N=8e3+10;
const int mod=1e9+7;
int n,a[N],t[N],res[N];
void add(int x,int k){
	for(;x<=n;x+=x&-x)t[x]+=k;
}
int ask(int x){
	int ans=0;
	for(;x;x-=x&-x)ans+=t[x];
	return ans;
}
int main() {
	cin>>n;
	for(int i=2;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)add(i,1);
	for(int i=n;i>=1;i--){
		int k=a[i];
		int l=0,r=n;
		while(l<r){
			int mid=l+r+1>>1;
			if(ask(mid)>k)r=mid-1;
			else l=mid;
		}
		res[i]=l+1;
		add(l+1,-1);
	}
	for(int i=1;i<=n;i++){
		cout<<res[i]<<endl;
	}

	return 0;
}


