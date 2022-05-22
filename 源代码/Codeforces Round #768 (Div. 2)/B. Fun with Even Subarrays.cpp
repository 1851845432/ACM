#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int x=a[n];int ans=0;	int d=1;
		for(int i=n-1;i>=1;i--){
			if(a[i]!=x){
				i-=n-i-1;
				ans++;	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
