#include<iostream>
using namespace std;
const int N=30;
int a,n,m,x;
int a1[N],b[N];//a和a的系数 
int main(){
	cin>>a>>n>>m>>x;
	a1[2]=1;a1[3]=2;
	for(int i=4;i<=n;i++){
		a1[i]=a1[i-1]+a1[i-2]-1;
		b[i]=b[i-1]+b[i-2]+1;	
	}
	int r=(m-a*a1[n-1])/b[n-1];
	cout<<a*a1[x]+r*b[x]<<endl;
	return 0;
}
