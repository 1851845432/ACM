#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int s[110][110], ss[110][110];
void XZ1(int n)
{
	//旋转90°》》顺时针旋转
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ss[j][n - i + 1] = s[i][j];
		}
	}
}
void XZ2(int n)
{
	//旋转180°》》垂直旋转
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ss[n - i + 1][n + 1 - j] = s[i][j];
		}
	}
}
void XZ3(int n)
{
	//旋转270°》》逆时针旋转	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ss[n + 1 - j][i] = s[i][j];
		}
	}
}
void XZ4(int n)
{

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ss[i][j] = s[i][j];
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> s[i][j];
			}
		}
		switch (d / 90%4)
		{
		case 1:
			{
				XZ1(n);
				break;
			}
		case 2:
			{
				XZ2(n);
				break;
			}
		case 3:
			{
				XZ3(n);
				break;
			}
		case 0:
			XZ4(n);
			break;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (j == n)
					cout << ss[i][j];
				else
					cout << ss[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}

