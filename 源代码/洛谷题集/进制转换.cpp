#include<iostream>
#include<math.h>
using namespace std;
char a[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
string s;
int main(){
	int n,r;
	cin>>n>>r;
	cout<<n<<'=';
	while(n){
		int j=n%r;
		n/=r;
		if(j<0){
			s+=a[j-r];
			n++;
		}
		else 
		s+=a[j];
	}
	for(int i=s.length()-1;i>=0;i--){
		cout<<s[i];
	}
	cout<<"(base"<<r<<')'<<endl; 
	return 0;
}
