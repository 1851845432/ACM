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
const int N=5e3+10;
const int mod=1e9+7;
int sum[N];
int main() {
	string  a,b;
	cin>>a>>b; 
	int len=max(a.size(),b.size());	
	//转置方便判断高精进位 
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	//两个数字相加存与sum数组 
	for(int i=1;i<=len;i++){
		if(i>a.size())sum[i]=b[i-1]-'0';
		else if(i>b.size())sum[i]=a[i-1]-'0';
		else sum[i]=a[i-1]-'0'+b[i-1]-'0';
	}
	//判断进位 
	for(int i=1;i<=len;i++){
		if(sum[i]>9){
			sum[i]-=10;
			sum[i+1]++;
		}
	}
	//特判最高位是否有进位 
	if(sum[len+1]>0)len++;
	//逆序输出 
	for(int i=len;i>=1;i--){
		cout<<sum[i];
	}
	return 0;
}



