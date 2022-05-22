#include<iostream>
using namespace std;
int s[1010][1010],a[1010][1010];
int main()//未构建差分数组，而是直接对数据进行处理 
{
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)//输入矩阵 
	{
		for(int j=1;j<=m;j++)
		{
			cin>>s[i][j];
		}
	}
	
	while(q--)//对需要修改的部分进行进行处理 
	{
		int x1,y1,x2,y2,c;
		cin>>x1>>y1>>x2>>y2>>c;
		a[x1][y1]+=c;
		a[x1][y2+1]-=c;
		a[x2+1][y1]-=c;
		a[x2+1][y2+1]+=c;
	}
	//进行前缀和运算
	 for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1]; //处理完并进行前缀和后，得到的是原数组每个位置应该变化的值 
		}
	}
		 for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
		cout<<s[i][j]+a[i][j]<<' ';
		}
		cout<<endl;
	}
	
	
	return 0;
 } 
