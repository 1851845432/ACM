#include<iostream>
using namespace std;
int pd(int a,int b){
	if(a==b)return 2;
	if(a==0 && (b==2 || b==3))return 1;
	else if(a==1 && (b==0 || b==3))return 1;
	else if(a==2 && (b==1 || b==4))return 1;
	else if(a==3 && (b==2 || b==4))return 1;
	else if(a==4 && (b==0 || b==1))return 1;
	else return 0; 
}
int main(){
	int N,Na,Nb;
	cin>>N>>Na>>Nb;
	int a[400],b[400];
	for(int i=0;i<Na;i++)cin>>a[i];
	for(int i=0;i<Nb;i++)cin>>b[i];
	int ansa=0,ansb=0;
	for(int i=0;i<N;i++){
	//	cout<<"²ÂÈ­½á¹û£º"<<pd(a[i%Na],b[i%Nb])<<endl;
		if(pd(a[i%Na],b[i%Nb])==2)continue;
		else if(pd(a[i%Na],b[i%Nb])==1)ansa++;
		else ansb++;
	}
	cout<<ansa<<' '<<ansb<<endl;
	
	return 0;
} 
