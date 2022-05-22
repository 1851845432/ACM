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
inline int read() { int x = 0, f = 1;char ch = getchar();while (ch < '0' || ch > '9') {if (ch == '-')f = -1;ch = getchar();}while (ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();	}return x * f;}
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e4+7;
int ksm(int a,int n){
	int ans=1;
	while(n){
		if(n&1)ans=(ans*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return ans%mod;
}
/*

ȡ���̵ĺ�ΪK
k==0ʱ ��n����λ��ÿ����λ��ѡ����������ɫ2^n��
��Ϊ���̶���ż������ k��ȡֵ[2��4��6����n]
��C(n,2)+C(n,4)+C(n,6)+����+C(n,n) �ɶ���ʽ���� ��2^(n-1)-1����ȥk==0������� 
��k���У�Ϊ����䣨ʣ�µľ����̵ģ���C(a,k) a��ȡֵΪ[0,2,4,����,k]
�ɶ���ʽ����ɵú�Ϊ2^(k-1)
������ģ�n-k����λ���У�Ҳ������������ɫ��ѡ ����2^(n-k)��
�ϲ��ֵ� 2^(n-1) ��
����ɼӷ�����ͳ˷��������� ���Ϊ��
2^n+2^(n-1)*(2^(n-1)-1) 

*/
int main() {
	int t;
    cin>>t;
	while(t--){
		int n;cin>>n;
		cout<<(ksm(2,n)+(ksm(2,n-1)%mod*(ksm(2,n-1)+mod-1)%mod)%mod)%mod<<endl;
	}
	return 0;
}



