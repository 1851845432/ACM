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
const int N=1+10;
const int mod=1e9+7;
int a[N];
int main() {
	int n=2021;
	for(int i=0;i<=9;i++){
		a[i]=n;
	}
	bool f=1;
	for(int i=1;;i++){
		int x=i;
		while(x){
			int y=x%10;
			a[y]--;
			if(a[y]==-1){
				f=0;
				break;
			}
			x/=10;
		}
		if(!f){
			cout<<i-1<<endl;
			break;
		}
	}

	return 0;
}



