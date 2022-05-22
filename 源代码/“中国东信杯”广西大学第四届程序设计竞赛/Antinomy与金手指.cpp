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
const int N=2e5+10;
const int mod=1e9+7;
string a,b;
int kmp[N];
int main() {
	int n;
	cin>>n;
	cin>>a>>b;
	a+=a;
	int j=0;
	for(int i=2;i<b.size();i++){
		while(j && b[i]!=b[j+1]) j=kmp[j];
		if(b[i]==b[j+1]) j++;
		kmp[i]=j;
	}
	j=0;
	bool f=1;
	for(int i=1;i<a.size();i++){
		while(j && b[j+1]!=a[i])j=kmp[j];
		if(b[j+1]==a[i]) j++;
		if(j==b.size()){
			cout<<"wow"<<endl;
			f=0;
			break;
		}
	}
	if(f)cout<<"TAT"<<endl;
//	cout<<a<<endl<<b<<endl;
//	for(int i=0;i<b.size();i++)cout<<kmp[i]<<' ';
	

	return 0;
}


