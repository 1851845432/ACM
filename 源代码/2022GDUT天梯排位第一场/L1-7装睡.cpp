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
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;
struct pop{
	char name[10];
	int a,b;
}s[14];
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%s%d%d",s[i].name,&s[i].a,&s[i].b);
		if((s[i].a<15 || s[i].a>20) || (s[i].b<50 || s[i].b>70)){
			printf("%s\n",s[i].name);
		}
	}

	return 0;
}



