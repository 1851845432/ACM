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
const int N=1e2+10;
const int mod=1e9+7;
char s[N][N];
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s[i][j]='.';
		}
	} 
	if(n&1){
		for(int i=1;i<=n;i++){
			if(i&1)s[i][1]='#';
			else s[i][n]='#';
		}
	}else{
		for(int i=1;i<=n;i+=2){
			s[i][1]=s[i][n]='#';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<s[i][j];	
		}
		cout<<endl;
	}

	return 0;
}



