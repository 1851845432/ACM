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
//		int v = a[i]; //未排序的部分的首元素
//		int j = i - 1; //已排序部分的末元素
//		while (j >= 0 && a[j] > v) { //如果未越界，并且未当前选中的元素大于v
//			a[j + 1] = a[j]; //大于v的元素向后移动
//			j--;//指针后移
//		}
//		a[j + 1] = v; //交换
//		for (int k = 0; k < n; k++) {
//			cout << a[k] << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}
