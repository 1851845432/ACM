#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int a=n;;a++){
		for(int b=a+1;;b++){
			for(int c=b+1;;c++){
				if(2*a*b*c==n*b*c+n*a*c+n*a*b)
				{
					cout<<a<<' '<<b<<' '<<c<<endl;
					goto end;
				}

			}
		}
	}
end:	
	return 0;
}
