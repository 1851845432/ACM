#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#define INF 0x3f3f3f
#define ll long long
using namespace std;
const int N = 3e3;
const int mod = 1e9 + 7;
int n,m,s,t;
int p[N][N],d[N],v[N],f[N];
int djtsl(){
	memset(v,0,sizeof(v));
	memset(d,INF,sizeof(d));
	d[s]=0;
	while(1){
		int u=-1,minn=INF;
		for(int i=1;i<=n;i++){
			if(!v[i] && d[i]<minn){
				minn=d[i];
				u=i;
			}
		}
		if(u==-1)break;
		v[u]=1;
		for(int i=1;i<=n;i++){
			if(!v[i] && d[i]>d[u]+p[u][i]){
				d[i]=d[u]+p[u][i];
				f[i]=u;
			}
		}
	}
	return d[t];
}
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	cin>>n>>m>>s>>t;
	memset(p,INF,sizeof(p));
	for(int i=0;i<m;i++){
		int a,b,l;
		cin>>a>>b>>l;
		p[a][b]=min(p[a][b],l);
		p[b][a]=min(p[b][a],l);
	}
	cout<<djtsl()<<endl;
	
	

	return 0;
}


