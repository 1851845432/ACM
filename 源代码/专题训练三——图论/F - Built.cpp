#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#define IL inline
typedef long long ll;
using namespace std;
//kruskal�㷨 
const int N = 1e5 + 10;
ll n,ans,sum;
struct edge {//��¼�ߵĽṹ�壬p1��p2�ֱ��¼ת���ɽ���ͼ��d��ʾΪ�ߵ�Ȩֵ 
	ll p1, p2, d;
} p[2*N];
struct dian {//��¼��Ľṹ�� �����±�id��ʾΪͼ�Ľ�� 
	ll x, y, id;
} a[N];
bool cmpx(dian a, dian b) {//��x�������� 
	return a.x < b.x;
}
bool cmpy(dian a, dian b) {//��y�������� 
	return a.y < b.y;
}
bool cmp(edge a, edge b) {//�Ա߳��������� 
	return a.d < b.d;
}
int f[N];//��¼���ڵ� 
int fd(ll x) {//���Ҹ��ڵ� 
	if (x == f[x])return x;
	return f[x] = fd(f[x]);
}
void tg(int x, int y) {//�ϲ���� 
	x = fd(x);
	y = fd(y);
	if (x != y)f[y] = x;
}
int kruskal() {//�㷨ʵ�� 
	int num=0;
	for (int i = 1; i <= ans; i++) {
		int x=fd(p[i].p1),y=fd(p[i].p2);
		if(x==y)continue;
		f[x]=y;
		sum+=p[i].d;
		num++;
		if(num==n-1)break;
	}
	return sum;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &a[i].x, &a[i].y);//���������� 
		a[i].id = i;//��¼��Ϊͼ�Ľ�� 
		f[i] = i;//��ʼ�����ڵ� 
	}
	sort(a + 1, a + n + 1, cmpx);//��x���� 
	for (int i = 1; i < n; i++) {//�ֱ��¼��������x������ʾ�ߵ�Ȩֵ 
		p[++ans].p1 = a[i].id;
		p[ans].p2 = a[i + 1].id;
		p[ans].d = abs(a[i].x - a[i + 1].x);
	}
	sort(a + 1, a + n + 1, cmpy);
	for (int i = 1; i < n; i++) {//�ֱ��¼��������y������ʾ�ߵ�Ȩֵ 
		p[++ans].p1 = a[i].id;
		p[ans].p2 = a[i + 1].id;
		p[ans].d = abs(a[i].y - a[i + 1].y);
	}
	sort(p+1,p+ans+1,cmp);//����ߵ�ȫ��Ȩֵ�������� ��ת��Ϊ��kruskal����С���������� 
	cout<<kruskal()<<endl;
	
	return 0;
}


