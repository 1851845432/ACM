#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k;
	cin>>n>>k;
		if(n&1 || k>=n){
			cout<<"YES"<<endl;
			return 0;
		}
		else{
			if(k==1){
				cout<<"NO"<<endl;
			}
		 else	if(k>=2){
				cout<<"YES"<<endl;
			}
		}
	
	
	return 0;
}
