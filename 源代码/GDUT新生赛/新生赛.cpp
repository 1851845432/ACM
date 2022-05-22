#include<iostream>
using namespace std;
int main(){
	int a;
	cin>>a;
		for(int j=0;j<100;j++){//ÄêÁä 
		if((a-j)%100==0)
			cout<<j<<' '<<(a-j)/100<<endl;	
}
	return 0;
}
