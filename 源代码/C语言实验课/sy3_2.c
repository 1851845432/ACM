#include<stdio.h>
int s[100];
char v[6]={'A','B','C','D','E'};
int main(){
	char ch;
	int i=0,j=0;
	for(i=0;i<100;i++){
		printf("请输入打分(ABCDE)（输入0时结束）："); 
		scanf("%c",&ch);
		getchar();
		if(ch=='0')break; 
		s[ch-'A']++;
	}
	printf("Grade\t\t");
	printf("Count\t\t");
	printf("Histogram \n");
	for( i=0;i<5;i++){
		printf("%c\t\t",v[i]);
		for(j=0;j<s[i];j++){
			printf("*");
		}
		printf("\t\t%d\t\n",s[i]);
		
	}
	
	return 0;
}

