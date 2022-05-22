#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
#define IL inline
using namespace std;
const int N = 1e5 + 10;
int p[N], f[N];
int fd(int x){
	if(x==f[x])return x;
	return f[x]=fd(f[x]);
}
void tg(int x,int y){
	x=fd(x);y=fd(y);
	if(x!=y)f[x]=y;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) f[i]=i;
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		tg(x,y);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(p[i]==i)ans++;//如果数字原本就在符合的位置 
		else if(fd(p[i])==fd(i))ans++;//或者相应的数字和位置的连通的则一定可以交换 
	}
	cout<<ans<<endl;
	return 0;
}


