#include<iostream>
using namespace std;

void floyd(){
	for(int j=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]>a[i][k]+a[k][j]){//��kΪ�������ȫ�����ܣ��ж��Ƿ��������·�� 
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
	}
} 
int main() {

	return 0;
}
