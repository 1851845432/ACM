#include<iostream>
using namespace std;
int s[20][20];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<=n;i++){
		s[i][0]=1;//������û������ʱ��ֻ�ܳ�ջ 
	}
	for(int j=1;j<=n;j++){//����ʣ�µ��� 
		for(int i=0;i<=n;i++){//ջ�ڵ��� 
			if(i==0){//���ջ��û������ֻ����ջ 
				s[i][j]=s[i+1][j-1];
			}
			else{
				s[i][j]=s[i-1][j]+s[i+1][j-1];
			}
		} 
	} 
	//������ǣ���������n������ջ��û�����ĳ�ʼ����Ŀ��� 
	cout<<s[0][n]<<endl;
	return 0;
} 
