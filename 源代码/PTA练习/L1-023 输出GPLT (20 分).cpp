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
int s[5];
string x="GPLT";
int main() {
//  freopen("in.txt", "r", stdin);
//GPLT
	string a;
	cin >> a;
	int ans=0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= 'a' && a[i] <= 'z')a[i] -= 32;
		if(a[i]=='G')s[0]++,ans++;
		else if(a[i]=='P')s[1]++,ans++;
		else if(a[i]=='L')s[2]++,ans++;
		else if(a[i]=='T')s[3]++,ans++;
	}
	for(int i=0;ans;i++){
		if(s[i%4]){
			cout<<x[i%4];
			s[i%4]--;
			ans--;
		}
	}
}
