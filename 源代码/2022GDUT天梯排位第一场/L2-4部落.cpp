#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#include<set>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=1e4+10;
const int mod=1e9+7;
int f[N];
int fd(int x){
	if(f[x]==x)return f[x];
	else return f[x]=fd(f[x]);
}
void get(int x,int y){
	x=fd(x);
	y=fd(y);
	if(x!=y){
		f[x]=y;
	}
}
int q[N];
set<int> p;
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=N;i++)f[i]=i;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>q[i];
			p.insert(q[i]);
			if(i>1){
				get(q[1],q[i]);
			}
		}
	}
	cout<<p.size()<<' '<<
	int Q;
	cin>>Q;
	while(Q--){
		
	}

	return 0;
}



