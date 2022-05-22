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
const int mod= 80112002;
int in[N],out[N];
vector<int> q[N];
int ans[N];
int main() {
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		q[x].push_back(y);
		in[y]++,out[x]++;
	} 
	queue<int> qu;
	for(int i=1;i<=n;i++){
		if(in[i]==0){//���Ϊ0 �������� 
			qu.push(i);
			ans[i]=1;
		}
	}
	//�������� 
	while(qu.size()) {
		int x=qu.front();qu.pop();
		for(int i=0;i<q[x].size();i++){//������һӪ���� 
			int y=q[x][i];
			in[y]--;//��Ϊx�Ѿ��߹���������ȼ�һ 
			ans[y]=(ans[x]+ans[y])%mod;//���µ��ý���·���� 
			if(!in[y])qu.push(y);//���Ϊ0������ѹ����� 
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(!out[i]){//����Ϊ0 Ϊ���Ӫ��������¼������ʳ�������� 
			sum=(sum+ans[i])%mod;
		}
	} 
	cout<<sum<<endl;
	
	

	return 0;
}



