#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define ll long long
#define fre() freopen("in.txt", "r", stdin);
#define endl "\n"
#define forr(x) for(int i=1;i<=x;i++)
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
string a="10X98765432";
int main() {
//  freopen("in.txt", "r", stdin);
		int n;
		cin >> n;
		bool f=0;
		int x[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
		for (int i = 1; i <= n; i++) {
			string s;cin>>s;
			int sum=0;
			for(int i=0;i<s.size()-1;i++){
				sum+=(s[i]-'0')*x[i];
			}
			sum%=11;
//			cout<<s[17]<<" "<<a[sum]<<endl;
			if(s[17]!=a[sum]){
				f=1;
				cout<<s<<endl;
			}
		}
		if(!f){
			puts("All passed");
		}
	
	return 0;
}
