#include<iostream>
#include<cstring>
#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;
const int N = 2e3+10;
int dp[N],v[N],w[N],s[N];
int main(){
    int n,V;
    cin>>n>>V;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i]>>s[i];
    for(int i=1;i<=n;i++){
        int sum=min(s[i],V/v[i]);
        for(int k=1;sum>0;k<<=1){
            if(k>sum)k=sum;
            sum-=k;
            for(int j=V;j>=v[i]*k;j--){
                dp[j]=max(dp[j],dp[j-k*v[i]]+k*w[i]);
            }
        }
    }
    cout<<dp[V]<<endl;
    
    return 0;
}
