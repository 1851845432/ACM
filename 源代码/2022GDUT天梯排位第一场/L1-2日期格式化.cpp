#include<stdio.h>

char s[100];
char a[100];
int main() {
	scanf("%s",s);
	a[0]=s[6];
	a[1]=s[7];
	a[2]=s[8];
	a[3]=s[9];
	a[4]='-';
	a[5]=s[0];
	a[6]=s[1];
	a[7]='-';
	a[8]=s[3];
	a[9]=s[4];
	a[10]=0;
	printf("%s",a);
	

	return 0;
}



