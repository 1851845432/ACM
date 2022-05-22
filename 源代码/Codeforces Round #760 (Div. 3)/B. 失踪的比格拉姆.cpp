#include<iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		string a,s,b;
		int n;
		cin>>n;
		for(int i=1; i<=n-2; i++) {
			cin>>a;
			if(i==1){
				s+=a;
				b=a;
				continue;
			}
			if(a[0]==b[1])s+=a[1];
			else s+=a;
			b=a;
		}
		if(s.size()!=n)s+=b[1];
		cout<<s<<endl;

	}


	return 0;
}
