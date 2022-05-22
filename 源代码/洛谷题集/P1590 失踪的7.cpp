#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long  n;
		cin>>n;
		int a=0,b=0;
		long long  ans=0;
		while(n){
			a=n%10;
			b++;

			ans+=a*pow(9,b-1)-(a>=7?pow(9,b-1):0);
			n/=10;
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
