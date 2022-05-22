#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
using namespace std;
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;

int main() {
  freopen("in.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		if(y%x==0)
		cout<<1<<" "<<y/x<<endl;
		else{
		cout<<0<<" "<<0<<endl;
		}
	} 

	return 0;
}



