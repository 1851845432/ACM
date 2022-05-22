#include<iostream>
using namespace std;
//°£É¸   ËØÊıÉ¸·¨ 
const int N=1e6;
int str[N];
int n;
void prime(){
	str[0]=1;
	str[1]=1;
	for(int i=2;i*i<=n;i++){
		if(!str[i]){
			for(int j=i*i;j<=n;j+=i){
				str[j]=1;
			}
		}
		
	}
	
}
int main(){
	cin>>n;
	prime();
	for(int i=0;i<=n;i++){
		if(!str[i])cout<<i<<endl;
	}

	
	
	return 0;
} 
