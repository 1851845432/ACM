#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
char v[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
char x[1000000];//string有内存限制，数据过大可能存不下 
int main(){
	int n,m;
	string s;
	cin>>n>>s>>m;
	long long  ans=0;
	for(int i=0;i<s.length();i++){//进行十进制的转换 
		for(int j=0;j<=15;j++){
			if(s[i]==v[j]){
				ans+=j*pow(n,s.length()-i-1);//字符串读取的第一个字符的权重不是0，而是最大的权重 
			}
		}
	}

	int num=0;
	while(ans){//对m进制进行转换 
		x[num++]=v[ans%m];
		ans/=m;
	}
	for(int i=num-1;i>=0;i--){//对转换的进制数进行逆序输出 
		cout<<x[i];
	}
	return 0;
}
