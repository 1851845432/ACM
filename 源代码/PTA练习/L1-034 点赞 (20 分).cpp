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
	int a[1100]={0};
	int mx=0,num=0;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			a[x]++;
		}
	}
	for(int i=1000;i>=1;i--){
		if(a[i]>mx){
			mx=a[i];
			num=i;
		}
	}
	cout<<num<<" "<<mx<<endl;

	return 0;
}



