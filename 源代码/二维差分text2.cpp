#include<iostream>
using namespace std;
int s[1010][1010],a[1010][1010];
int main()//δ����������飬����ֱ�Ӷ����ݽ��д��� 
{
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)//������� 
	{
		for(int j=1;j<=m;j++)
		{
			cin>>s[i][j];
		}
	}
	
	while(q--)//����Ҫ�޸ĵĲ��ֽ��н��д��� 
	{
		int x1,y1,x2,y2,c;
		cin>>x1>>y1>>x2>>y2>>c;
		a[x1][y1]+=c;
		a[x1][y2+1]-=c;
		a[x2+1][y1]-=c;
		a[x2+1][y2+1]+=c;
	}
	//����ǰ׺������
	 for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1]; //�����겢����ǰ׺�ͺ󣬵õ�����ԭ����ÿ��λ��Ӧ�ñ仯��ֵ 
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
