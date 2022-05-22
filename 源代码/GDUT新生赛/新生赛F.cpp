#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long  n,a,b;
		long  sum=0;
		cin>>n>>a>>b;
		if(a*3>b*2){//买三个的单价便宜 
			if(n%3==2){//剩下两个 ，最多买三个a的，或一个a一个b，或者两个b 
			sum+=(n/3)*b;
			sum+=min(a,b);	
			}
			else if(n%3==1){//剩一个 
				sum+=((n/3)-1)*b;
				sum+=min(2*a,a+b); 
			}
			else
			sum+=(n/3)*b;
		}
		else if(a*3<b*2){//买两个的单价便宜 
			if(n%2){
				sum+=((n/2)-1)*a;
				sum+=min(b,2*a);
			}
			else
				sum+=(n/2)*a;
		}
		else{//单价相同 
			sum+=n*a/2;
		}
		cout<<sum<<endl;
		
	}
	
	return 0;
}
