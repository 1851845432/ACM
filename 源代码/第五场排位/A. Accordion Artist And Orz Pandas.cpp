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
���õ���ջά������ǰ�����ߵ�һ���������ľ���
���ұߵ�һ���������ľ��� 
*/
int main() {
	int n;
	cin >> n;
	int top = 0;
	for (int i = 1; i <= n; i++) {
		cin >> h[i] >> w[i];
		s[i]=s[i-1]+w[i];//ǰ׺�ʹ���	
	}
	h[0]=h[n+1]=0;//�߽� 
	for(int i=1;i<=n+1;i++){//ע��Ҫ��n+1����Ϊ���ñ߽��n�����ҽ��Ӧ����n+1 
		//�����ǰ���С��ջ��Ԫ���򣬸õ�Ϊջ��Ԫ�ص��ҽڵ� 
		while(h[q[top]]>h[i]){
			r[q[top]]=i;
			top--;
		}
		//�����ǰԪ�ش���ջ��Ԫ�أ���õ������Ϊջ��Ԫ�� 
		l[i]=q[top];
		q[++top]=i;//ά������ջ���� 
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
//		cout<<l[i]<<" "<<r[i]<<endl;
		ans=max(ans,h[i]*(s[r[i]-1]-s[l[i]]));
	} 
	cout << ans << endl;
	return 0;
}
