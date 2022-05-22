#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int mod=1e9+7;
#define ll long long 

int main(){
//	freopen("in.txt","r",stdin);
	int n,m,q;
	cin>>n>>m>>q;
	map<int,int> a,b;
	while(q--){
		int t,c;
		cin>>t>>c;
		if(t){//lie
			a[c]++;
		}else{
			b[c]++;
		}
	} 
	int la=a.size();
	int lb=b.size();
	cout<<n*m-la*n-lb*m+la*lb<<endl;

	return 0;
}
