#include<stdio.h>
int main(){
	char a[100];
	char b[100];
	int numa=0,numb=0;
	printf("������ԭ�ַ�����");
	scanf("%s",a);
	printf("�������������ַ�����") ;
	scanf("%s",b);
	int i=0;
	int max=0;
	for(i=1;a[i];i++){
		max=a[i]>a[max]?i:max;//��¼����ַ����±� 
	}
	for(i=0;b[i];i++)numb++; //b���鳤�� 
	for(i=0;a[i];i++)numa++; //a���鳤�� 
	for(i=numa;i>max;i--){//�����ƶ�b���鳤�ȵ�λ�� 
		a[i+numb]=a[i];	
	}
	for(i=0;i<numb;i++){
		a[max+i+1]=b[i];
	}
	a[numa+numb+1]='\0';
	printf("�ַ��������Ľ��Ϊ��"); 
	printf("%s",a);
	
	return 0;
}
