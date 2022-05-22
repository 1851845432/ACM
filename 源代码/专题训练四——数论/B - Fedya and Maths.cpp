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
int ksm(int a,int n){
	int sum=1;
	while(n){
		if(n&1)sum=sum*a%5;
		a=a*a%5;
		n>>=1;
	}
	return sum;
}

int main() {
	ll n;
	n=read();
	if(n%4){
		cout<<0<<endl;
	}
	else cout<<4<<endl;
	
	/*数据过大，考虑找规律，打表找规律*/
//	for(int i=1;i<=20;i++){
//		cout<<"n="<<i<<' '<<"mod="<<(ksm(1,i)%5+ksm(2,i)%5+ksm(3,i)%5+ksm(4,i)%5)%5<<endl;
//	}

	return 0;
}



