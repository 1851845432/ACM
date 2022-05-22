#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
//字典树
//trie
int tr[N][30];//构造树的结构
int v[N];//记录结束标志，此题用来记录到此处结束的子串出现的次数
int idx, cnt, len;
int id(char c) {
	if (c >= 'a' && c <= 'z')return c - 'a';
	else return c - 'A';
}
void insert(char *s, int len) {
	int u = 0;
	for (int i = len-1; i >= 0; i--) {
		int t = id(s[i]); //转换字符的位置
		if (!tr[u][t]) tr[u][t] = ++idx; //u为上一个字符的结点，t为当前字符的结点，idx记录结点出现的个数
		u = tr[u][t]; //更新至下一个结点
		v[u]++; //记录到该结点为止，出现的次数
	}
}
void dfs(int u, int l) {
	if(l>len && v[u]>=3){
		len=l;
		cnt=v[u];
	}
	else if(l==len && v[u]>=3){
		cnt=max(cnt,v[u]);
	}
	for(int i=0;i<=26;i++){
		if(tr[u][i]){
			dfs(tr[u][i],l+1);
		}
	}
}
int main() {
	int t, cont = 0;
	cin >> t;
	while (t--) {
		memset(tr, 0, sizeof(tr));
		memset(v, 0, sizeof(v));
		idx = 0;//记录树结点数 
		cnt = 0;//记录相同后缀出现的个数 
		len = 0;//记录最长的后缀 
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++) {
			char s[110];
			cin >> s;
			insert(s, strlen(s));//插入字典树 
		}
		dfs(0, 0);
		printf("Case %d:\n", ++cont);
		cout << len << ' ' << cnt << endl;
	}
}
//int main() {
//	int t;
//	cin >> t;
//	int cont = 0;
//	while (t--) {
//		int k;
//		vector<string> s;
//		cin >> k;
//		for (int i = 1; i <= k; i++) {
//			string s1;
//			cin >> s1;
//			transform(s1.begin(),s1.end(),s1.begin(),::tolower);
//			reverse(s1.begin(), s1.end());
//			s.push_back(s1);
//		}
//		sort(s.begin(), s.end());
//		map<string, int> mp;
//		int len=0;
//		for(int i=0;i<s.size();i++)len=max(len,(int)s[i].size());
//		int maxx = 0, ans = 0;
//		for (int i = len; i >=1; i--) {
//			for (int j = 0; j < s.size(); j++) {
//				if (i <= s[j].size()) {
//					mp[s[j].substr(0, i)]++;
//					ans = max(ans, mp[s[j].substr(0, i)]);
//				}
//			}
//			if (ans >= 3) {
//				maxx = i;
//				break;
//			}
//		}
//		printf("Case %d:\n", ++cont);
//		cout << maxx << ' ' << ans << endl;
//	}
//	return 0;
//}


