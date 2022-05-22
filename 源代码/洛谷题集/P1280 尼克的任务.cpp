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
const int N = 1e4 + 10;
const int mod = 1e9 + 7;
int n, k;
vector<int> q[N];
int dp[N];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int p, t;
		cin >> p >> t;
		q[p].push_back(t);//��¼pʱ�俪ʼʱ������ʱ�� 
	}
	//�����޺�Ч�ԣ������� 
	for (int i = n; i > 0; i--) {//dp[i]��ʾi����ʱ���ܻ�õ�������ʱ�� 
		if(q[i].size()){//���i����ʱ������ 
			for(int j=0;j<q[i].size();j++){//״̬ת��ÿ�����������Ͼʱ�� 
				dp[i]=max(dp[i],dp[i+q[i][j]]);
			}
		}
		else{//���i����ʱû�����������ʱ���һ 
			dp[i]=dp[i+1]+1;
		} 
	}
	cout<<dp[1]<<endl;
	return 0;
}
