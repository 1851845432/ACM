#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int f[110];//父节点
int v[110];//记录会这么语言的人的编号
int _find(int x) {
	if (x != f[x]) f[x] = _find(f[x]);
	return f[x];
}
void teget(int x, int y) {
	int fx = _find(x);
	int fy = _find(y);
	if (fx != fy)f[fx] = fy;
}

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		if (!k) {//如果一门语言都不会， 起码要学一门语言才能连通
			f[i] = 0;//标记其父节点为0，表示其不会语言
			ans++;
		}
		while (k--) {
			int a;
			cin >> a;//语言的标识
			if (v[a]) {
				teget(v[a], i); //如果这么语言有其他人会，就把他们合并。
				continue;
			}
			v[a] = i; //没人会就记录第i个人会了。
		}
	}
	if (ans == n) { //特判如果全部不会语言就每人起码学一种才能交流
		cout << n << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] == i)ans++;//这是判断有会语言但是没连通的人的数量，他们需要学会一种已连通的语言才能交流
	}
	cout << ans - 1 << endl;//-1是减去根结点的判定
	return 0;
}
