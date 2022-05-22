#include<bits/stdc++.h>
using namespace std;
char s[110][110];
int main(){
	int r,c,k;
	cin>>r>>c>>k;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>s[i][j];
		}
	}
	bool flag;
	int ans=0;
	for(int i=0;i<r;i++){//ºáÏòËÑË÷ 
		for(int j=0;j<c;j++){
			flag=1;
			for(int l=0;l<k;l++){
				if(s[i+l][j]!='.'){
					flag=0;
				}
			}
			if(flag)ans++; 
		}
	}
	for(int i=0;i<r;i++){//ÊúÏòÀú±é 
		for(int j=0;j<c;j++){
			flag=1;
			for(int l=0;l<k;l++){
				if(s[i][j+l]!='.'){
					flag=0;
				}
			}
			if(flag)ans++; 
		}
	}
	if(k==1)cout<<ans*2<<endl;
	else cout<<ans<<endl; 
	
	return 0; 
} 
