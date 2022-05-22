#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int s[N];
int main(){
	int n;
	int ans=0;
	cin>>n; 
	for(int i=1;i<=sqrt(n);i++){
		s[i*i]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sqrt(i);j++){
			if(j==sqrt(i) && s[j]){
				ans++;
				break;
			}
			if(i%j==0){
				if(s[j])ans++;
				if(s[i/j])ans++;
			}		
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
