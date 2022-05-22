#include<stdio.h>
int s[100];
char v[6]={'A','B','C','D','E'};
int main(){
	char ch;
	
	for(int i=0;i<100;i++){
		printf("请输入打分（输入0时结束）："); 
		scanf("%c",&ch);
		getchar();
		if(ch=='0')break; 
		s[ch-'A']++;
	}
	printf("Grade     ");
	printf("Count     ");
	printf("Histogram \n");
	for(int i=0;i<5;i++){
		printf("%c          ",v[i]);
		for(int j=0;j<s[i];j++){
			printf("*");
		}
		printf("%10d\n",s[i]);
		
	}
	
	return 0;
}
