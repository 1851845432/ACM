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
#define INF 0x3f3f3f3f3f
#define ll long long
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=2e5+10;
const int mod=1e9+7;
int main() {
//	fre();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int  a[n+1],b[n+1];
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		int la=INF,ra=INF,lb=INF,rb=INF;
		for(int i=1;i<=n;i++){
			la=min(la,abs(a[1]-b[i]));
			ra=min(ra,abs(a[n]-b[i]));
			lb=min(lb,abs(a[i]-b[1]));
			rb=min(rb,abs(a[i]-b[n]));
		}
//		cout<<INF<<endl; 
		//只要四个角都有连接，则网络有容错 
		cout<<min(
		min(la+lb,abs(a[1]-b[1]))+min(ra+rb,abs(a[n]-b[n])),
		min(la+rb,abs(a[1]-b[n]))+min(ra+lb,abs(a[n]-b[1])))<<endl;
	}

	return 0;
}



