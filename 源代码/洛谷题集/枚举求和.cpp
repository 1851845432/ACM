#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
bool pd[N][N];
int gcd(int x,int y){
    int z=x%y;
    while(z){
        x=y;
        y=z;
        z=x%y;
    }
    return y;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,k;
        int ans=0;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(pd[i][j])continue;
               if(gcd(i,j)%k==0){
                   pd[i][j]=1;
                   pd[j][i]=1;
                   if(i==j)ans++;
                   else ans+=2;
               }
            }
        }
        cout<<ans<<endl;
        
    }
    
    
    return 0;
}
