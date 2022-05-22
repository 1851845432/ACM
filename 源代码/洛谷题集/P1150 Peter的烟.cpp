#include<iostream>
using namespace std;
int main(){
	int n,k;
	int num=0;
	cin>>n>>k;
		int sum=n;
	while(n/k>0){
		sum+=n/k;
		num+=n%k;
		n/=k;
		if(num>=k){
			sum++;
			num-=k;
		}
	}
	cout<<sum<<endl;
	
	return 0;
}

/*
 #include <bits/stdc++.h>
     using namespace std;
     int main(){
         int n,k;
         cin>>n>>k;
         cout<<n+(n-1)/(k-1);
         return 0;
     } 
感觉智商受到侮辱 
*/
