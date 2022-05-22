#include<iostream>
#include<cstdio>
using namespace std;


int main() {
	int a[8],b[4],t;
	cin>>t;
	while(t--) {
		for(int i=1; i<=7; i++) {
			cin>>a[i];
			if(i<=3) {
				b[i]=a[i];
			}
		}
		if(b[1]+b[2]+b[3]>=a[7]) {
			printf("%d %d %d\n",b[1],b[2],b[3]);
		} else {
			b[3]=a[4];
			printf("%d %d %d\n",b[1],b[2],b[3]);
		}
	}



	return 0;
}
