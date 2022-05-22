#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/*
输出字符串s的最小排列
并且使t不是最小排列的子序列
*/
int main()
{
	int x;
	cin>>x;
	while(x--)
	{
		string s,t;
		cin>>s>>t;
		int num[3]= {0,0,0};
		sort(s.begin(),s.end());
		for(int i=0; i<s.length(); i++)
		{
			if(s[i]<='c')
			{
				num[s[i]-'a']++;
			}
		}
		int a=s.find('a');
		int b=s.find('b');
		int c=s.find('c');
		if(a<0 ||b<0 ||c<0 || t[0]>t[2] || t[0]>t[1] ||t[1]>t[2])
		{
			cout<<s<<endl;
		}
		else
		{
			for(int i=b; i<b+num[2]; i++)
			{
				s[i]=t[2];
			}
			for(int i=b+num[2]; i<b+num[2]+num[1]; i++)
			{
				s[i]=t[1];
			}
			cout<<s<<endl;
		}
	}
	return 0;
}
