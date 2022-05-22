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
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int main() {
//  freopen("in.txt", "r", stdin);
	int cnt = 0;
	int month=0;
	for(int i=2000;i<2020;i++){
		if(i%4==0 && i%100!=0 || i%400==0){
			cnt+=366; 
		}
		else cnt+=365;
		month+=12;
	}
	cout<<cnt+31+29+31+30+31+30+31+31+31+10+month+1085-36<<endl;
	return 0;
}
