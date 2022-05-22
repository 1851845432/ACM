#include<iostream>
using namespace std;
int s[20][20];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<=n;i++){
		s[i][0]=1;//当队列没有数的时候，只能出栈 
	}
	for(int j=1;j<=n;j++){//队列剩下的数 
		for(int i=0;i<=n;i++){//栈内的数 
			if(i==0){//如果栈内没有数，只能入栈 
				s[i][j]=s[i+1][j-1];
			}
			else{
				s[i][j]=s[i-1][j]+s[i+1][j-1];
			}
		} 
	} 
	//想求的是，队列中有n个数，栈内没有数的初始情况的可能 
	cout<<s[0][n]<<endl;
	return 0;
} 
