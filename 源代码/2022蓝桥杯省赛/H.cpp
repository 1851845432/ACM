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
const double eps = 1e-6;
const int N = 5e4 + 10;
const int mod = 1e9 + 7;
struct egde {
	int x, y, r;
};
int main() {
//  freopen("in.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	vector<egde> a, b;
	for (int i = 1; i <= n; i++) {
		int x, y, r;
		scanf("%d%d%d", &x, &y, &r);
		a.push_back({x, y, r});
	}
	sort(a.begin(),a.end(),[](egde & x,egde & y){
		return x.x<y.x;
	});
	for (int i = 1; i <= m; i++) {
		int x, y, r;
		scanf("%d%d%d", &x, &y, &r);
		queue<egde> que;
		que.push({x,y,r});
		int ans=0;
		while(que.size()){
			egde temp =que.front();que.pop();
			int xx=temp.x;
			int yy=temp.y;
			for(auto & aa : a){
				if(aa.x==INF)continue;
				if(abs(aa.x-xx)<=temp.r && abs(aa.y-yy)<=temp.r){
					que.push(aa);
					ans++;
					aa.x=INF;aa.y=INF;
				}else{
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	
	
	return 0;
}
