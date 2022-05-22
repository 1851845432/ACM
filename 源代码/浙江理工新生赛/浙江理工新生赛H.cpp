#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		int a=i;
		while(a){
			if(a%10==k){
			ans++;	
			break; 
			}
			a/=10;
		}
	} 
	cout<<ans<<endl;
	
	return 0;
}
