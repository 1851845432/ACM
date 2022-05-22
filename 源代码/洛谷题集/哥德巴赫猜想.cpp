#include<iostream>
using namespace std;
bool pd(int x){
	if(x==2)return 1;
	for(int i=2;i<=x/2;i++){
		if(x%i==0) return 0;
	}
	return 1;
	
}
int main(){
	int n;
	cin>>n;
	for(int j=4;j<=n;j+=2){
		for(int i=2;i<=n;i++){
			if(pd(i) && pd(j-i)){
			cout<<j<<'='<<i<<'+'<<j-i<<endl;
			break;
			}
		}
	} 

	
	
	
	return 0;
}
