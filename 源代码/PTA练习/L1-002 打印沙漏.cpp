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
int main() {
//  freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	char ch;
	cin >> ch;
	if(n==0){
		cout<<0<<endl;
		return 0;
	}
	int x = (int)sqrt((n + 1) / 2);
	int num = n - 2 * x * x + 1;
	for(int i=0;i<x;i++){
		for(int j=0;j<i;j++){
			printf(" ");
		}
		for(int j=0;j<2*(x-i)-1;j++){
			printf("%c",ch);
		}
		cout<<endl;
	}
	for(int i=2;i<=x;i++){
		for(int j=0;j<x-i;j++)printf(" ");
		for(int j=0;j<2*i-1;j++)printf("%c",ch);
		cout<<endl;
	}
	cout << num << endl;
	return 0;
}
