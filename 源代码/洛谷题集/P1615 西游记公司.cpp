#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	long long  time1=0,time2=0;
	 string s1,s2;
	 cin>>s1>>s2;
	 int x;
	 cin>>x;
	 for(int i=0,h=3600;i<s1.length();i++){
	 	if(s1[i]==':'){
	 		h/=60;
	 		continue;
		 }
		 if(s1[i]!=':' && s1[i+1]!=':' && i+1<s1.length())time1+=(s1[i]-'0')*h*10;
		 else time1+=(s1[i]-'0')*h;		

	 }
//	 cout<<time1<<endl;
	 for(int i=0,h=3600;i<s2.length();i++){
	 	if(s2[i]==':'){
	 		h/=60;
	 		continue;
		 }
		 if(s2[i]!=':' && s2[i+1]!=':' &&i+1<s2.length())time2+=(s2[i]-'0')*h*10;
		 else time2+=(s2[i]-'0')*h;	
	 }
//	 cout<<time2<<endl;
	cout<<(time2-time1)*x<<endl;
	return 0;
}
