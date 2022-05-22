#include<iostream>
using namespace std;

void floyd(){
	for(int j=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]>a[i][k]+a[k][j]){//已k为跳板遍历全部可能，判断是否可以缩短路径 
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
	}
} 
int main() {

	return 0;
}
