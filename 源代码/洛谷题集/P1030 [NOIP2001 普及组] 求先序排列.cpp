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
const int N=1e6+10;
const int mod=1e9+7;
void dfs(string a,string b){
	if( !a.size() || !b.size())return ;
	cout<<b[b.size()-1];//����Ϊ����� 
	int x=a.find(b[b.size()-1]);
	//����Ϊ����� ������Ϊ���Ҹ�
	//�����и������ߵ�ȫΪ�������Ľ�㣬�䳤�ȵ�ͬ�ں������������Ľ��
	//���Կ���ֱ�ӽ�ȡ 
	dfs(a.substr(0,x),b.substr(0,x));//�ָ����򣬷ֱ�������������� 
	dfs(a.substr(x+1),b.substr(x,b.size()-x-1)); 
} 
int main() {
	string a,b;
	cin>>a>>b;
	dfs(a,b);
	cout<<endl; 

	return 0;
}



