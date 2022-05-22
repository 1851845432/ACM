#include<bits/stdc++.h>
using namespace std;
#define fx first;
#define sc second;
using ll = long long;
const ll N = 1e5+500,mod = 1e9+7;



int main()
{
    //freopen("input.txt","r",stdin);
//    freopen("easy.in","r",stdin);
//    freopen("easy.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='-')
        {
            if(s[i+2]>='0' and s[i+2]<='9')
            {
                s.insert(s.begin()+i+2,1,'+');
            }
        }
    }
    cout<<s;
}
