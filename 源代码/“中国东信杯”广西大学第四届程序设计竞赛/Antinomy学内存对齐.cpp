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
#include<string>
#define X first
#define Y second
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=1e5+10;
const int mod=1e9+7;
struct egde{
	string s;
	int x;
}ed[N];

int main() {
	int cnt=0;
	while(getline(cin,ed[++cnt].s)){
		if(ed[cnt].s[0]=='c' || ed[cnt].s[0]=='b')ed[cnt].x=1;
		else if(ed[cnt].s[0]=='s')ed[cnt].x=2;
		else ed[cnt].x=4;
		
		if(ed[cnt].s=="};"){
			break;
		}
	}
	sort(ed+2,ed+cnt,[](egde &a,egde &b){
		return a.x<b.x;	
	});
	for(int i=1;i<=cnt;i++){
		cout<<ed[i].s<<endl;
	}
	

	return 0;
}



