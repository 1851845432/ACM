#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#include<set>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps=1e-6;
const int N=1e6+10;
const int mod=1e9+7;
struct edge{
	char name[10];
	int num;
	int flag;
}s[110];
int main() {
	int n;
	cin>>n;
	set<int> q;
	for(int i=1;i<=n;i++){
		int k; 
		cin>>s[i].name;
		cin>>k;
		q.clear();
		int x,ans=0;
		while(k--){
			cin>>x;
			q.insert(x);
			ans++;
		}
		cout<<q.size()<<endl;
		s[i].num=q.size();
		s[i].flag=ans;
	}
	sort(s+1,s+n+1,[](edge &a,edge &b){
		if(a.num==b.num){
			return a.flag<b.flag;
		}
		return a.num>b.num;
	});
	for(int i=1;i<3;i++){
		if(s[i].num){
			cout<<s[i].name<<' ';
		}
		else{
			cout<<"- ";
		}
	}
	if(s[3].num){
		cout<<s[3].name;
	}
	else{
		cout<<"-";
	}
	
	return 0;
}


