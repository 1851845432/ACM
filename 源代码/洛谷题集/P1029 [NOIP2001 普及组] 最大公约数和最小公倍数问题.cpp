#include<iostream>
#include<math.h>
using namespace std;
int  gcd(int x,int y){
	if(!y)return x;
	gcd(y,x%y);
}
int lcm(int x,int y){
	return x/gcd(x,y)*y;
}
int main(){
	int x,y;
	cin>>x>>y;
	int ans=0;
	if(x==y)ans--;
	for(int i=1;i<=sqrt(x*y);i++)
		if(x*y%i==0 && gcd(i,x*y/i)==x)	ans+=2;	
		
	cout<<ans<<endl;
	
	return 0;
} 
/*�����������Լ������С�������ĳ˻��������������ĳ˻�
   �������Ļ�����������Ϊ����ȡ����
   	��������������ӵ������������ԭ�������������Լ��
	   ��������������С������Ҳ��ͬ ����Ϊ����ͬ�������������ͬ������С������һ����ͬ�� 
 
