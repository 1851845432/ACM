#include<stdio.h>

int main() {
	int n,ans=0,flag=0;
	while(~scanf("%d",&n)){
		ans++;
		if(n==250 && !flag){
			flag=ans;
		}
	}
	printf("%d\n",flag);
	
	return 0;
}



