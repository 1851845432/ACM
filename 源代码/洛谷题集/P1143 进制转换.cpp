#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
char v[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
char x[1000000];//string���ڴ����ƣ����ݹ�����ܴ治�� 
int main(){
	int n,m;
	string s;
	cin>>n>>s>>m;
	long long  ans=0;
	for(int i=0;i<s.length();i++){//����ʮ���Ƶ�ת�� 
		for(int j=0;j<=15;j++){
			if(s[i]==v[j]){
				ans+=j*pow(n,s.length()-i-1);//�ַ�����ȡ�ĵ�һ���ַ���Ȩ�ز���0����������Ȩ�� 
			}
		}
	}

	int num=0;
	while(ans){//��m���ƽ���ת�� 
		x[num++]=v[ans%m];
		ans/=m;
	}
	for(int i=num-1;i>=0;i--){//��ת���Ľ���������������� 
		cout<<x[i];
	}
	return 0;
}
