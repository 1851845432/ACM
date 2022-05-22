#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
const int N = 2010;
int n, m;
struct zb
{
	int x, y;
};
int tx[] = {-1, 1, 0, 0};
int ty[] = {0, 0, -1, 1};
char s[N][N];
queue<zb> q;
int fd(int x, int y)  //查找四周.的个数
{
	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		int dx = x + tx[i], dy = y + ty[i];
		if (dx >= 0 && dx < n && dy >= 0 && dy < m && s[dx][dy] == '.')
		{
			ans++;
		}
	}
	return ans;
}
void  fd2(int x, int y)  //重新搜索并记录当前为.且四周只有一个.的点
{
	for (int i = 0; i < 4; i++)
	{
		int dx = x + tx[i], dy = y + ty[i];
		if (dx >= 0 && dx < n && dy >= 0 && dy < m && s[dx][dy] == '.')
		{
			if (fd(dx, dy) == 1)
			{
				zb node;
				node.x = dx;
				node.y = dy;
				q.push(node);
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	getchar();
	for (int i = 0; i < n; i++)scanf("%s", s[i]);
	for (int i = 0.; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '.' && fd(i, j) == 1)   //找到四周只有一个.的坐标并插入队列
			{
				zb node;
				node.x = i;
				node.y = j;
				q.push(node);
			}
		}
	}
	while (q.size())
	{
		zb node = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = node.x + tx[i], y = node.y + ty[i];
			if (x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.')
			{
				if (i == 0)
				{
					s[x][y] = '^';
					s[node.x][node.y] = 'v';
				}
				else if (i == 1)
				{
					s[x][y] = 'v';
					s[node.x][node.y] = '^';
				}
				else if (i == 2)
				{
					s[x][y] = '<';
					s[node.x][node.y] = '>';
				}
				else if (i == 3)
				{
					s[x][y] = '>';
					s[node.x][node.y] = '<';
				//更新已经用砖填满的的位置后继续搜索可能存在的值。
				fd2(x, y);
				fd2(node.x, node.y);
				break;
			}
		}
	}
	bool flag = 1;
	for (int i = 0; i < n; i++)  //判断地板是否被填满
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '.')flag = 0;
		}
	}
	if (flag)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%s\n", s[i]);
		}
	}
	else     //未填满
	{
		printf("Not unique\n");
	}

	return 0;
}
