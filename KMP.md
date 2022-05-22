# KMP

[[P3375 【模板】KMP字符串匹配 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/solution/P3375)](https://www.luogu.com.cn/problem/solution/P3375)

## 简单理解：

> KMP的精髓在于每次匹配失败后，由一个相同的真前缀直接转移至一个相同的真后缀的位置上，从而省略了大量的无用比对，节约时间。
>
> 根据其最长的相同真前后缀的数量关系可以知道，当字符串位于第 **j** 位时，其最长的相同真前后缀存于 next[ j ]中，，若要继续向下比对，则直接判断其第 i 位于第 j+1 位的关系是否相同，若相同则令 j++ 表示其最长真前后缀加一，并存于next[ i ]中，若不匹配则不断回溯  j 的位置令其等于 next[ j ] ，回溯至上一次匹配判断的位置。
>
> 当模式串与自身匹配时，则可以求出该模式串中所有子串的最长的真前后缀的长度。
>
> 借此再继续对主串进行比较时，只需重复与自身匹配时的过程，并判断其长度是否等于模式串本身时，即可得到判断。



```c++
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
			cout << i - lb + 1 << endl;
			j = kmp[j]; //继续回溯搜索
		}
	}
	for (int i = 1; i <= lb; i++)cout << kmp[i] << " ";
	return 0;
}
```

