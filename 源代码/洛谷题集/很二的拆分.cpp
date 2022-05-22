#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n&1){
        cout<<-1<<endl;
        return 0;
    }
    else{
        for(int i=31;i>0;i--){
            if((n>>i)&1)cout<<pow(2,i)<<' ';
            }
        
    }
    
    return 0;
}
