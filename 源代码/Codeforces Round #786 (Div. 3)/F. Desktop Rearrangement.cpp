#include<bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff
#define ll long long
#define endl "\n"
using namespace std;
const double eps = 1e-6;
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
int n, m, q;
char s[N][N];
int tr[N * N];
int get(int x,int y){//将二维数组转换一维 
	return (y-1)*n+x;
}
void add(int x,int k) {
	for(;x<=n*m;x+=x&-x)tr[x]+=k;
}
int ask(int x){
	int ans=0;
	for(;x;x-=x&-x)ans+=tr[x];
	return ans;
}
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n >> m >> q;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> s[i][j];
			if (s[i][j] == '*') {
				cnt++;//记录‘* ’的数量 
				add(get(i,j), 1);
			}
		}
	}
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		if(s[x][y]=='*'){
			s[x][y]='.';
			cnt--;
			add(get(x,y),-1);
		}else{
			s[x][y]='*';
			cnt++;
			add(get(x,y),1);
		}
//		cout<<cnt<<" "<<ask(cnt)<<endl;
		cout<<cnt-ask(cnt)<<endl;
	}
	return 0;
}
