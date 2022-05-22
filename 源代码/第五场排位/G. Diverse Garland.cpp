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
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;
char x[3]={'R','G','B'};
int main() {
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=0;
	for(int i=1;i<n;i++){
		if(s[i-1]==s[i] && s[i]==s[i+1]){
			for(int j=0;j<3;j++){
				if(s[i-1]==x[j]){
					s[i]=x[!j];
					ans++;
					break;
				}
			}
	
		}else if (s[i-1]==s[i]){
			for(int j=0;j<3;j++){
				if(x[j]!=s[i-1] && x[j]!=s[i+1]){
					s[i]=x[j];
					ans++;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	cout<<s<<endl;

	return 0;
}



