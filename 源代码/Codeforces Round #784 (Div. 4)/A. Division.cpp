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
#define INF 0x3f3f3f3f
#define ll long long
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define forr(x) for(int i=1;i<=x;i++)
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;

int main() {
//  freopen("in.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--){
		int r;
		cin>>r;
		int x;
		if(r>=1900)x=1;
		else if(r>=1600 && r<=1899)x=2;
		else if(r>=1400 && r<=1599)x=3;
		else x=4;
		printf("Division %d\n",x);
	}

	return 0;
}



