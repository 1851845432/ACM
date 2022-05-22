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
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
bool low_v[N],v[N];
vector<int> prime;
void qjs(ll a,ll b){
	for(ll i=0;i*i<b;i++)low_v[i]=1; 
	for(int i=0;i<=b-a;i++)v[i]=1;
	low_v[1]=0;
	if(a==1)v[0]=0;
	for(ll i=2;i*i<b;i++){
		if(low_v[i]){
			for(ll j=2*i;j*j<=b;j+=i)low_v[j]=0;//É¸[2£¬sqrtb)£» 
			for(ll j=max(2LL,(a+i-1)/i)*i;j<=b;j+=i)v[j-a]=0;//É¸[a,b) 
		}
	}
}

int main()
{
	ll L, U;
	while (~scanf("%lld%lld", &L, &U))
	{
		qjs(L,U);
		prime.clear();
		for(ll i=L;i<=U;i++){
			if(v[i-L]){
				prime.push_back(i);
			}
		}
//		for(int i=0;i<prime.size();i++)cout<<prime[i]<<' ';
		if (prime.size() < 2)
		{
			cout << "There are no adjacent primes." << endl;
		}
		else
		{
			ll a=prime[0], b=prime[1], x=prime[0], y=prime[1];
			ll maxx =b-a, minn = y-x;
			
			for (int i = 2; i < prime.size(); i++)
			{
				if (prime[i] - prime[i-1] > maxx)
				{
					maxx = prime[i] - prime[i-1];
					a = prime[i-1];
					b = prime[i];
				}
				if (prime[i] - prime[i-1] < minn)
				{
					minn = prime[i] - prime[i-1];
					x = prime[i-1];
					y = prime[i];
				}
			}
	printf("%lld,%lld are closest, %lld,%lld are most distant.\n",x,y,a,b);
		}
	}

	return 0;
}
