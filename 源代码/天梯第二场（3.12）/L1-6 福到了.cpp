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
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
char s[110][110];
char a[110][110];
int main() {
	char c;
	int n;
	scanf("%c%d",&c,&n);
	getchar();
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%c",&a[i][j]);
		}
		a[i][j]=0;
		getchar();
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(strcmp(a[i]+1,a[n-i+1]+1)){
			flag=0;	
		}
		for(int j=1;j<=n;j++){
			if(a[i][j]=='@')a[i][j]=c;
			s[n-i+1][n-j+1]=a[i][j];
		}
	}
	if(flag)cout<<"bu yong dao le"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;j++){
			printf("%c",s[i][j]);
		}
		cout<<endl;
	}
	

	return 0;
}
