#include<iostream>
using namespace std;
int a[1000];

int main() {
	int n;
	int ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				ans++;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(i)cout<<' ';
		cout<<a[i];
	}
	cout<<endl;
	cout<<ans<<endl;

}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i < n; i++) {
//		int v = a[i]; //δ����Ĳ��ֵ���Ԫ��
//		int j = i - 1; //�����򲿷ֵ�ĩԪ��
//		while (j >= 0 && a[j] > v) { //���δԽ�磬����δ��ǰѡ�е�Ԫ�ش���v
//			a[j + 1] = a[j]; //����v��Ԫ������ƶ�
//			j--;//ָ�����
//		}
//		a[j + 1] = v; //����
//		for (int k = 0; k < n; k++) {
//			cout << a[k] << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}
