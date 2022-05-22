#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	cout<<n<<endl;
	int s[110]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				if(s[j])s[j]=0;
				else s[j]=1;
			}
			cout<<s[j];
		}
		cout<<endl;
	}
	
	
	return 0;
}
 
