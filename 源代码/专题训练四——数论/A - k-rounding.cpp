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
using namespace std;
inline int read() { int x = 0, f = 1;char ch = getchar();while (ch < '0' || ch > '9') {if (ch == '-')f = -1;ch = getchar();}while (ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();	}return x * f;}
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;
ll gcd(int a,int b){
	if(b==0)return a;
	gcd(b,a%b);
}
//10^k与n的最小公倍数 
int main() {
		ll n,k;
		cin>>n>>k;
		ll z=pow(10,k);
		cout<<n*z/gcd(n,z)<<endl;
	return 0;
}



