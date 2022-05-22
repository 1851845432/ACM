#include<cstdio>
using namespace std;
int main(){
	int x=98765;
	for(int i=0;i<2;i++){
		for(int j=1;j<=4;j++){
			printf("%d\n",x);
			if(i==0) x/=10;
			else if(i==1){
				int y=x%10-1;
				x*=10;
				x+=y;
			}
			}
		}
		printf("%d\n",x);
	return 0;
}
