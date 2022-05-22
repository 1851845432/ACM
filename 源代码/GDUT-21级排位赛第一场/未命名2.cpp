#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
#define endl "\n"
#define  IOS std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
const double eps = 1e-6;
const int N = 1e4 + 10;
const int mod = 1e9 + 7;
int main() {
	int n;
	while (cin >> n && n) {
		map<string, int> mp;
		set<string,less<string> > st;
		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			mp[s]++;
			st.insert(s);
		}
		for(auto & x : st){
			cout<<x<<endl;
		}
		stack<int> q;
		while (1) {
			bool flag = 1;
			int num = 0;
			for (auto & is : mp) {
				if (is.second) {
					is.second--;
					num++;
					flag = 0;
				}
			}
			if (flag)break;
			q.push(num);
		}
		while (q.size()) {
			cout << q.top();
			q.pop();
		}
		cout << endl;
	}
}
//int main() {
//	int n, ans = 0;
//	while (cin >> n && n) {
//		ans++;
//		string s;
//		vector<string> a;
//		for (int i = 1; i <= n; i++) {
//			cin >> s;
//			if (!mp[s]) {
//				a.push_back(s);
//			}
//			mp[s]++;
//		}
//		stack<int> w;
//		while (1) {
//
//			bool flag=1;int num = 0;
//			for (int i = 0; i < a.size(); i++) {
//				if (mp[a[i]]) {
//					mp[a[i]]--;
//					num++;
//					flag=0;
//				}
//			}
//			if(flag)break;
//			w.push(num);
//		}
//		printf("Case %d: ",ans);
//		while(w.size()){
//			cout<<w.top();
//			w.pop();
//		}
//		cout<<endl;
//	}
//	return 0;
//}
