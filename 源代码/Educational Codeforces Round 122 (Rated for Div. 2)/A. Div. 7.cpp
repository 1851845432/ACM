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
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%7==0){
			cout<<n<<endl;
			continue;
		}
		for(int i=0;i<10;i++){
			if((n-n%10+i)%7==0){
				cout<<n-n%10+i<<endl;
				break;
			}
		}
	}
	return 0;
}



