#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e7+10;
int a[N];
long long s[N];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i*m+j]);
			s[i*m+j]=s[(i-1)*m+j]+s[i*m+j-1]-s[(i-1)*m+j-1]+a[i*m+j]; 
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%lld\n",s[x2*m+y2]+s[(x1-1)*m+y1-1]-s[(x1-1)*m+y2]-s[x2*m+y1-1]);
	}
	
	
	
	
	return 0;
}
