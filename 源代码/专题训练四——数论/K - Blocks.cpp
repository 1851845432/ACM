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

取红绿的和为K
k==0时 有n个空位，每个空位可选另外两种颜色2^n种
因为红绿都是偶数所以 k的取值[2，4，6……n]
又C(n,2)+C(n,4)+C(n,6)+……+C(n,n) 由二项式定理 得2^(n-1)-1（减去k==0的情况） 
从k个中，为红分配（剩下的就是绿的）有C(a,k) a的取值为[0,2,4,……,k]
由二项式定理可得和为2^(k-1)
而其余的（n-k）个位置中，也有其他两种颜色可选 又有2^(n-k)种
合并又得 2^(n-1) 种
最后由加法定理和乘法定理可求得 结果为：
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



