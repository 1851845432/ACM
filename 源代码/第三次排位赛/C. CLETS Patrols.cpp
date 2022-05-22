#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#define X first
#define Y second
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=2e2+10;
const int mod=1e9+7;
int n,m;
 struct egde{
 	double a[N][N];
 	egde (){
	 	memset(a,0,sizeof(a));
	 }
	 void build(){
	 	for(int i=1;i<=n;i++)a[i][i]=1;
	 }
	 
 } a;
 egde operator* (const egde&x,const egde &y){
 	egde tem;
 	for(int i=1;i<=n;i++){
	 	for(int j=1;j<=n;j++){
		 	for(int k=1;k<=n;k++){
			 	tem.a[i][j]=tem.a[i][j]+x.a[i][k]*y.a[k][j];
			 }
		 }
	 }
	 return tem;
 }
 egde ksm(){
 	egde ans;ans.build();
 	while(m){
	 	if(m&1)ans=ans*a;
	 	a=a*a;
	 	m>>=1;
	 }
	 return ans;
 }
int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a.a[i][j];
		}
	}	
	a=ksm();
	for(int i=1;i<=n;i++){
		cout<<a.a[1][i]<<endl;
	}
	return 0;
}



