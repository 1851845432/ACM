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
#define forr(n) for(int i=1;i<=n;i++)
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 5e1 + 10;
const int mod = 1e9 + 7;
int a[N];
int main() {
//  freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int t[55]={0};
		bool f=1;
		forr(n) {
			int x;
			cin >> x;
			while(x>n || t[x])x/=2;
			if(x==0)f=0;//如果这个数所以除以二的数都已经被其他数使用过，则这个数必定是重复的 
			else t[x]=1;
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
