#include<stdio.h>
int main(){
	char a[100];
	char b[100];
	int numa=0,numb=0;
	printf("请输入原字符串：");
	scanf("%s",a);
	printf("请输入想插入的字符串：") ;
	scanf("%s",b);
	int i=0;
	int max=0;
	for(i=1;a[i];i++){
		max=a[i]>a[max]?i:max;//记录最大字符的下标 
	}
	for(i=0;b[i];i++)numb++; //b数组长度 
	for(i=0;a[i];i++)numa++; //a数组长度 
	for(i=numa;i>max;i--){//往后移动b数组长度的位数 
		a[i+numb]=a[i];	
	}
	for(i=0;i<numb;i++){
		a[max+i+1]=b[i];
	}
	a[numa+numb+1]='\0';
	printf("字符串插入后的结果为："); 
	printf("%s",a);
	
	return 0;
}
