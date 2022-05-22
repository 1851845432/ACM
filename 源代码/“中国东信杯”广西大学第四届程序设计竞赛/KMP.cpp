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
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
char a[N], b[N];
int kmp[N];
/*
ABABABC
ABA
*/
int main() {
	//字符串下标从一开始
	cin >> a + 1;
	cin >> b + 1;
	int la = strlen(a + 1);
	int lb = strlen(b + 1);
	int j = 0;
	for (int i = 2; i <= lb; i++) {
		while (j && b[i] != b[j + 1]) j = kmp[j]; //如果不匹配则回溯至当前位置所匹配的最长相同前后缀的长度的下表为位置
		if (b[i] == b[j + 1])j++; //如果匹配成功则继续继续向下匹配
		kmp[i] = j; //记录下当前位置的最长相同前后缀的长度
	}
	j = 0;
	for (int i = 1; i <= la; i++) {
		while (j && a[i] != b[j + 1]) j = kmp[j]; //将模式串与主串进行匹配，如不匹配则回溯
		if (a[i] == b[j + 1])j++; //若匹配则加一
		if (j == lb) { //若长度与模式串长度相等则输出相应的坐标位置
			cout <<"wow" << endl;
			j=0;
			break;//继续回溯搜索
		}
	}
	if(j)cout<<"TAT"<<endl;
	
	return 0;
}
