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
const double eps = 1e-6;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
ll h[N], w[N];
ll s[N];
int q[N]; 
int l[N],r[N];
/*
利用单调栈维护出当前结点左边第一个低于他的矩阵
和右边第一个低于他的矩形 
*/
int main() {
	int n;
	cin >> n;
	int top = 0;
	for (int i = 1; i <= n; i++) {
		cin >> h[i] >> w[i];
		s[i]=s[i-1]+w[i];//前缀和处理	
	}
	h[0]=h[n+1]=0;//边界 
	for(int i=1;i<=n+1;i++){//注意要到n+1，因为设置边界第n个的右结点应该是n+1 
		//如果当前结点小于栈顶元素则，该点为栈顶元素的右节点 
		while(h[q[top]]>h[i]){
			r[q[top]]=i;
			top--;
		}
		//如果当前元素大于栈顶元素，则该点的左结点为栈顶元素 
		l[i]=q[top];
		q[++top]=i;//维护单调栈递增 
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
//		cout<<l[i]<<" "<<r[i]<<endl;
		ans=max(ans,h[i]*(s[r[i]-1]-s[l[i]]));
	} 
	cout << ans << endl;
	return 0;
}
