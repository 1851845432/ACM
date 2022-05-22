#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a;
	int sum=0;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		sum+=a;
		maxn=max(a,maxn);
	}
		if(sum%2){
			cout<<"NO"<<endl;
		}
		else
		{
			if(maxn>sum/2)cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
	
	
	return 0;
}
