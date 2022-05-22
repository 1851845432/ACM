#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e4 + 10;
int a[N], b[N];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ma=0,mb=0;
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++){
			cin >> b[i];
			if(a[i]<=b[i]){
				swap(a[i],b[i]);
			}
			ma=max(ma,a[i]);
			mb=max(mb,b[i]);
		}

		cout <<ma*mb<< endl;
	}
	return 0;
}
