#include<iostream>
using namespace std;
bool pd(int n){
	if(n%7==0)return 1;
		while(n){
			if(n%10==7)return 1;
			n/=10;
		}
		return 0;
		
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(pd(n))cout<<"pa"<<endl;
		else cout<<n<<endl;
		
	} 
	return 0;
} 
