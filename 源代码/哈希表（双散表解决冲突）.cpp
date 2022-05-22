#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int H = 1e6;
const int L = 15;
char s[H][L];
int getChar(char ch) { //���ַ�ת��Ϊ��ֵ
	if (ch == 'A')return 1;
	else if (ch == 'C')return 2;
	else if (ch == 'G')return 3;
	else if (ch == 'T')return 4;
	else return 0;
}

long long getKey(char* x) { //���ַ���ת��Ϊ��ֵ ������key
	long long sum = 0, p = 1, i = 0;
	for (i = 0; i < strlen(x); i++) {
		sum += p * getChar(x[i]);
		p *= 5;
	}
	return sum;
}
int h1(int key) {
	return key % H;   //��ϣ����1
}
int h2(int key) {
	return 1 + (key % (H - 1));   //��ϣ����2
}
int insert(char* str) { //�����ַ������±��ɹ�ϣֵ����
	long long key, i, h;
	key = getKey(str);
	for (i = 0;; i++) {
		h = (h1(key) + i * h2(key)) % H; //˫ɢ�б�Ĺ�ϣֵ��iΪ��ͻ����
		if (strcmp(s[h], str) == 0)return 1;
		else if (strlen(s[h]) == 0) {
			strcpy(s[h], str);
			return 0;
		}
	}
	return 0;
}
int findd(char* str) {
	long long key, i, h;
	key = getKey(str);
	for (i = 0;; i++) {
		h = (h1(key) + i * h2(key)) % H; //˫ɢ�б�Ĺ�ϣֵ��iΪ��ͻ����
		if (strcmp(s[h], str) == 0)return 1;
		else if (strlen(s[h]) == 0) return 0;
	}
	return 0;

}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char com[L], str[L];
		scanf("%s %s", com, str);
		if (com[0] == 'i') {
			insert(str);
		} else if (com[0] == 'f') {
			if (findd(str)) {
				cout << "yes" << endl;
			} else {
				cout << "no" << endl;
			}
		}

	}




	return 0;
}
