#include<iostream>
using namespace std;

struct PK {
	char value;
	int num;
};

void Bubble(struct PK c1[], int n) { //√∞≈›≈≈–Ú
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (c1[j].num > c1[j + 1].num) {
				struct PK t = c1[j];
				c1[j] = c1[j + 1];
				c1[j + 1] = t;
			}
		}
	}
}
void selection(struct PK c2[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (c2[i].num > c2[j].num) {
				struct PK t = c2[i];
				c2[i] = c2[j];
				c2[j] = t;
			}
		}
	}
}

bool isStable(struct PK c1[],struct PK c2[],int n){
	for(int i=0;i<n;i++){
		if(c1[i].value!=c2[i].value){
			return false;
		}
	}
	return true;
}
void print(struct PK a[],int n){
	for(int i=0;i<n;i++){
		if(i)cout<<' ';
		cout<<a[i].value<<a[i].num; 
	} 
	cout<<endl;
}

int main() {
	int n;
	cin >> n;
	PK c1[100],c2[100];
	for (int i = 0; i < n; i++) {
		cin >> c1[i].value >> c1[i].num;
		c2[i]=c1[i];
	}
	Bubble(c1, n);
	selection(c2, n);
	print(c1,n);
	cout<<"Stable"<<endl;
	print(c2,n);
	if(isStable(c1,c2,n)){
		cout<<"Stable"<<endl;
	}
	else{
		cout<<"Not Stable"<<endl;
	}

	return 0;
}
