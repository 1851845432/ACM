#include<iostream>
using namespace std;
const int N=1e6+10;
int s[N],a[N];//s²¿³¤£¬aÓã 
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		a[s[i]]=i; 		
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
