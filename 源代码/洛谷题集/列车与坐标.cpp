#include<iostream>
using namespace std;
bool pd(int x){
	if(x<2)return 0;
	else if(x==2)return 1;
	else
		for(int i=2;i<=x/2;i++) 
			if(x%i==0)return 0;
			
		return  1;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		int k;
		cin>>k;
		if(pd(k))cout<<"YES"<<endl;
		else cout<<"NO"<<endl; 
		
	}
	
	return 0;
} 
