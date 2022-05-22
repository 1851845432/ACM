#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main(){
    int  n,m;
    long long  ans=0,ai=0;//怒气值，以有人坐座位号
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    sort(a+1,a+m+1);
    for(int i=1;i<=m;i++){
        if(ai>n){
            cout<<-1<<endl;
            return 0;
        }
        else if(a[i]>ai){//如果想坐的位置比比已有人坐的位置大
            ai=a[i];//记录已有人坐的位置
            continue;
        }
        else{
            ans+=ai+1-a[i];//想要的位置被坐了，就往前面没人的地方（ai+1）坐
            ai++;
        }
            
    }
    cout<<ans<<endl;
    
    return 0;
}
