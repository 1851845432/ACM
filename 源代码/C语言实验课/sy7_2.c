#include<stdio.h>
void sCopy(char *a,char*b,int x){
	int i;
	for(i=0;i<=x;i++){
		b[i]=a[i];
	}
	b[i]='\0';
}
int main(){
	int n;
	scanf("%d",&n);
	char s1[100],s2[100];
	scanf("%s",s1);
	sCopy(s1,s2,n);
	printf("%s",s2);
	return 0;
} 
