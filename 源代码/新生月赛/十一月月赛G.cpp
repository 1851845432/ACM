#include<iostream>
using namespace std;
int main(){
	double n;
   	cin>>n;
   	double x=1.0;
	for(int i=1;;i++){
		x=x*((365-i+1)/365.0);
		if(1-x>n){
			//cout<<1-x<<endl;
			cout<<i<<endl;
			break;
		}
		
	}
	
	return 0;
}
