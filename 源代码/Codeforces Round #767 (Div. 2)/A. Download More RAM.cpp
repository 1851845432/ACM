#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e3 + 10;
struct RAM{
	int a,b;
}r[N];
bool cmp(struct RAM x,struct RAM y){
	if(x.a==y.a){
		return x.b>y.b;
	}
	return x.a<y.a;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)cin >> r[i].a;
		for (int i = 1; i <= n; i++)cin >> r[i].b;
		sort(r+1,r+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(k>=r[i].a){
				k+=r[i].b;
			}
		}
		cout<<k<<endl;	
	}



	return 0;
}
