#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int main() {
//	freopen("in.txt","r",stdin);
	string a, b;
	cin >> a >> b;
	string c, d;
	for (int i = 1; i < a.size(); i++) {
		int x = a[i] - '0';
		int y = a[i - 1] - '0';
		if ((x & 1) == (y & 1)) {
			c += x > y ? a[i] : a[i - 1];
		}
	}
	for (int i = 1; i < b.size(); i++) {
		int x = b[i] - '0';
		int y = b[i - 1] - '0';
		if ((x & 1) == (y & 1)) {
			d += x > y ? b[i] : b[i - 1];
		}
	}
	if(c==d)cout<<c<<endl;
	else{
	cout<<c<<endl;
	cout<<d<<endl;
		
	}
	return 0;
}
