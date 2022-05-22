#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int inf = 1e8;
const int N = 5e3 + 10;
int s[N][N];//�ڽӾ���洢ͼ 
int v[N], d[N];//vΪ����Ƿ�����µļ����У�d��ʾΪ��С��������Ȩֵ 
int n, m;
void prim() {
	//�Ա�����³�ʼ�� 
	memset(v, 0, sizeof(v));
	//��ʼ����С����Ȩֵ 
	for (int i = 1; i <= n; i++) d[i] = inf;
	d[1] = 0; //��1Ϊ�����
	while (1) {
		int u = -1;
		int minn = inf;
		//������ѡ���ϵ����г�������С�ı� 
		for (int i = 1; i <= n; i++) {
			if (!v[i] && d[i] < minn) {
				minn = d[i];
				u = i;
			}
		}
		if (u == -1)break; //���ҵ����н��
		v[u] = 1; //��������½ڵ�
		//���������¼�������ӦȨֵ�Ĵ�С 
		for (int i = 1; i <= n; i++) {
			if (!v[i] && d[i] > s[u][i]) {
				d[i] = s[u][i];
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	//���ڽӾ����ʼ��
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			s[i][j] = inf;
		}
	}
	//��ֹ�رߵĳ��֣�������Сֵ������¼�Ƿ���ͨ 
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		s[x][y] = min(s[x][y], z);
		s[y][x] = min(s[y][x], z);
		v[x] = v[y] = 1;
	}
	//���δ����������Ϊ��ͨ���orz 
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			cout << "orz" << endl;
			return 0;
		}
	}
	//prim�㷨����С������ 
	prim();
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] == inf) {//��������޷���ͨ�����������Ϊinf 
			cout << "orz" << endl;
			return 0;
		}
		sum += d[i];
	}
	cout << sum << endl;

	return 0;
}
