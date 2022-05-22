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
int mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main() {
//  freopen("in.txt", "r", stdin);
	for(int i=1;i<=12;i++){
		for(int j=1;j<=mon[i];j++){
			set<int> s;
			int x=i*100+j;
			while(x){
				s.insert(x%10);
				x/=10;
			}
			
		}
	}

	return 0;
}



