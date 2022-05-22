#include<iostream>
using namespace std;
int gcd(int x,int y)
{
	if(!y)return x;
	gcd(y,x%y);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int  n;
		cin>>n;
			
		if(n&1)
		{
	     	n-=1;
			for(int i=2; i<=n; i++)
			{
				if(gcd(i,n-i)==1)
				{
					cout<<i<<' '<<n-i<<' '<<1<<endl;
					break;
				}
			}
		}
		else
		{
			cout<<n/2-1<<' '<<n/2<<' '<<1<<endl;
		}
	}

	return 0;
}
