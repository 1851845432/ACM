#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int f[110];//���ڵ�
int v[110];//��¼����ô���Ե��˵ı��
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
		if (!k) {//���һ�����Զ����ᣬ ����Ҫѧһ�����Բ�����ͨ
			f[i] = 0;//����丸�ڵ�Ϊ0����ʾ�䲻������
			ans++;
		}
		while (k--) {
			int a;
			cin >> a;//���Եı�ʶ
			if (v[a]) {
				teget(v[a], i); //�����ô�����������˻ᣬ�Ͱ����Ǻϲ���
				continue;
			}
			v[a] = i; //û�˻�ͼ�¼��i���˻��ˡ�
		}
	}
	if (ans == n) { //�������ȫ���������Ծ�ÿ������ѧһ�ֲ��ܽ���
		cout << n << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] == i)ans++;//�����ж��л����Ե���û��ͨ���˵�������������Ҫѧ��һ������ͨ�����Բ��ܽ���
	}
	cout << ans - 1 << endl;//-1�Ǽ�ȥ�������ж�
	return 0;
}
