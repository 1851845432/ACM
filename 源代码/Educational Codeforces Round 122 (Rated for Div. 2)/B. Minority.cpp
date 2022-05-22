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
const int N=2e5+10;
const int mod=1e9+7;
char s[N];
int main() {
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		int num0=0,num1=0;
		for(int i=0;s[i];i++){
			if(s[i]=='0')num0++;
			else num1++;
		}
		if(num1==num0){
			cout<<num0-1<<endl;
		}
		else cout<<min(num0,num1)<<endl;
	}

	return 0;
}



