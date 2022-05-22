#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int s[N];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		sort(s,s+n);
		for(int i=1;i<=n/2;i++){
			cout<<s[i]<<' '<<s[0]<<endl; 
		}
	}
	
	
	return 0;
}
