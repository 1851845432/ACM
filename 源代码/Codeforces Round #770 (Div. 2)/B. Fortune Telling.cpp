#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);


using namespace std;
inline int read() { int x = 0, f = 1;char ch = getchar();while (ch < '0' || ch > '9') {if (ch == '-')f = -1;ch = getchar();}while (ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();	}return x * f;}
const double eps=1e-6;
const int N=1e5+10;
const int mod=1e9+7;

int main() {
	int t;
	cin>>t;
	while(t--){
		ll n,x,y;
		cin>>n>>x>>y;
		for(int i=1;i<=n;i++){
			int a;cin>>a;
			x+=(a&1);
		}
		/*����ÿ�����ֵĴ�������x�Ǽ��ϻ�λ���һ������
		�����������ı�����ż�ԣ�ż���򲻻�
		���x�ڶ������ȫ�����Ĵ����£������յ���ż����y��ͬ�������ΪAlice
		��ΪBobΪx+3��ż��һ����x�෴�� 
		*/
		if((x&1)==(y&1))cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;
	}
	
	
	
	return 0;
}


