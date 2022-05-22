#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>


using namespace std;


int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		string s;
		cin>>n>>s;
		if(n<=1){cout<<"YES"<<endl;continue;}
		if(n==2){
			if(s[0]==s[1]){cout<<"NO"<<endl;continue;}
			else{cout<<"YES"<<endl;continue;}
		}
		cout<<"NO"<<endl;
	}

	return 0;
}


