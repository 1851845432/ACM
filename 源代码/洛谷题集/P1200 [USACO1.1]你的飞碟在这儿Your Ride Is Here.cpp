#include<iostream>
#include<algorithm>
using namespace std;
int main(){
		string s1,s2;
		cin>>s1>>s2;
		long long ans1=1,ans2=1;
		for(int i=0;i<s1.length();i++){
			ans1*=(s1[i]-'A'+1);
		}
		for(int i=0;i<s2.length();i++){
			ans2*=(s2[i]-'A'+1);
		}
		if(ans1%47==ans2%47)cout<<"GO"<<endl;
		else cout<<"STAY"<<endl;
	
	return 0;
} 
