#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main(){
    int  n,m;
    long long  ans=0,ai=0;//ŭ��ֵ������������λ��
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
        else if(a[i]>ai){//���������λ�ñȱ�����������λ�ô�
            ai=a[i];//��¼����������λ��
            continue;
        }
        else{
            ans+=ai+1-a[i];//��Ҫ��λ�ñ����ˣ�����ǰ��û�˵ĵط���ai+1����
            ai++;
        }
            
    }
    cout<<ans<<endl;
    
    return 0;
}
