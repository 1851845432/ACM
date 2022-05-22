#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int ol(int x){//ŷ������ 
	int res=x;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			res=res/i*(i-1);
			while(x%i==0)x/=i;
		}
	}
	if(x>1)res=res/x*(x-1);
	return res;
}
inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
//��1~n����n���ʵ�������Ϊnum, ��ô[n + 1, 2n]����n���ʵ����ĸ���Ҳһ��Ϊnum.
//˼·���ݣ� 
int main()
{
	int n, k;
	while (~scanf("%d%d", &n, &k))
	{
		int num=ol(n);
		if(k%num==0){//�����num�������� 
			printf("%d\n",(k/num)*n-(n!=1)) ;//���n==1,���κ������ʣ����Ϊk������һ��Ϊ���������һ����������Ϊ�Ҷ˵�-1��ֵ 
			continue; 
		} 
		else{
			int cnt=k/num;//�ж��ڵڼ���������
			k%=num;//�༸�ͱ�ʾΪ�������ڵĵڼ���
			cnt=cnt*n;//������Ŀ�ͷ
			while(k){
				cnt++;
				if(gcd(cnt,n)==1)k--;//���cnt��n���ʣ���Ϊ�����ڵ�һ������������k--�� 
			}
			 printf("%d\n",cnt); 
		}
	}

	return 0;
}
