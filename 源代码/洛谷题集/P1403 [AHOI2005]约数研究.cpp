#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=n/i;
	}
	printf("%d",ans);
	
	return 0;
}

/*
** f(i)=n/i **
���ڹ�ʽ����ô�Ƴ����ģ����ҽ��ͣ�

1-n�����Ӹ��������Կ��ɹ�����2���ӵ����ĸ���+����3���ӵ����ĸ�������+����n���ӵ����ĸ���

����1~n�к��С�2��������ӵ�����n/2����3��n/3�����Դ����ƣ���ʽ�ͳ�����


*/
