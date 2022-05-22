#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string s,a;
bool v[256];
void dfs(int x) {
	int len=s.length();
	if (x == len) {
		cout << a << endl;
	}
	for(int i=0;i<len;i++){
		if(!v[(int)s[i]]){
			a[x]=s[i];
			v[(int)s[i]]=1;
			dfs(x+1);
			v[(int)s[i]]=0;
		}
	}

}
int main() {

	cin >> s;
	sort(s.begin(), s.end());
	dfs(0);
}

//int main(){
//	string s;
//	cin>>s;
//	do{
//		cout<<s<<endl;
//	}
//	while(next_permutation(s.begin(),s.end()));
//
//	return 0;
//}
