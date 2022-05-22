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
	//�ַ����±��һ��ʼ
	cin >> a + 1;
	cin >> b + 1;
	int la = strlen(a + 1);
	int lb = strlen(b + 1);
	int j = 0;
	for (int i = 2; i <= lb; i++) {
		while (j && b[i] != b[j + 1]) j = kmp[j]; //�����ƥ�����������ǰλ����ƥ������ͬǰ��׺�ĳ��ȵ��±�Ϊλ��
		if (b[i] == b[j + 1])j++; //���ƥ��ɹ��������������ƥ��
		kmp[i] = j; //��¼�µ�ǰλ�õ����ͬǰ��׺�ĳ���
	}
	j = 0;
	for (int i = 1; i <= la; i++) {
		while (j && a[i] != b[j + 1]) j = kmp[j]; //��ģʽ������������ƥ�䣬�粻ƥ�������
		if (a[i] == b[j + 1])j++; //��ƥ�����һ
		if (j == lb) { //��������ģʽ����������������Ӧ������λ��
			cout <<"wow" << endl;
			j=0;
			break;//������������
		}
	}
	if(j)cout<<"TAT"<<endl;
	
	return 0;
}
