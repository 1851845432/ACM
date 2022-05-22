#include<iostream>
using namespace std;
char s[60][60];
int n, m, r, c;
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> r >> c;
		int ans = -1;
		if (r > n || c > m) {
			cout << -1 << endl;
			continue;
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
					cin >> s[i][j];
					if(s[i][j]=='B'){
						ans=0;
					}
			}
		}
		if(ans){
			cout<<ans<<endl;
			continue; 
		}	
		if (s[r][c] == 'B') {
			cout << 0 << endl;
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (s[i][c] == 'B') {
				ans = 1;
				break;
			}
		}
		for (int i = 1; i <= m; i++) {
			if (s[r][i] == 'B') {
				ans = 1;
				break;
			}
		}
		if(ans==1){
			cout<<ans<<endl;
			continue; 
		}
		else{
			cout<<2<<endl;
			continue;
		}
	}
	return 0;
}
