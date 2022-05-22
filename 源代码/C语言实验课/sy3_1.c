#include<stdio.h>
int main(){
	int x=98765;
	int i,j;
	for(i=0;i<2;i++){
		for(j=1;j<=4;j++){
			if(i==0){
			printf("%d\n",x);
			x/=10;				
			} 
			else if(i==1){
				printf("%d\n",x);
				x=x*10+x%10-1;
			}
			}
		}
		printf("%d\n",x);
	return 0;
}
