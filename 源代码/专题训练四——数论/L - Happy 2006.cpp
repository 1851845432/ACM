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
int ol(int x){//欧拉函数 
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
//设1~n中与n互质的数个数为num, 那么[n + 1, 2n]中与n互质的数的个数也一定为num.
//思路依据： 
int main()
{
	int n, k;
	while (~scanf("%d%d", &n, &k))
	{
		int num=ol(n);
		if(k%num==0){//如果是num的整数倍 
			printf("%d\n",(k/num)*n-(n!=1)) ;//如果n==1,与任何数互质，结果为k，否则一定为区间内最后一个质数，即为右端点-1的值 
			continue; 
		} 
		else{
			int cnt=k/num;//判断在第几个区间内
			k%=num;//余几就表示为在区间内的第几个
			cnt=cnt*n;//新区间的开头
			while(k){
				cnt++;
				if(gcd(cnt,n)==1)k--;//如果cnt与n互质，则为区间内第一个质数，所以k--； 
			}
			 printf("%d\n",cnt); 
		}
	}

	return 0;
}
