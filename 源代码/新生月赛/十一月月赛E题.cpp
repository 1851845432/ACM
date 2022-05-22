#include<iostream>
using namespace std;
int main(){
	int n;
	int a;

	cin>>n;
	while(n--){
		cin>>a;
		int sum=a/2;
		int ans=a/3; 
		int cont=a/6;
		

		cout<<a-sum-ans+cont<<endl;
	}
	
	return 0;
}
