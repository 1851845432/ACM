#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct point
{
	int x; //������
	int y; //������
};

int main()
{
	vector<point> p;//������е�
	for (int i = 0; i <= 19; ++i)
		for (int j = 0; j <= 20; ++j)
			p.push_back({i, j});

	int len = p.size();
	set<pair<double, double> > lines; //���бֱ��y=kx+b
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			if (p[i].x != p[j].x && p[i].y != p[j].y) // ͳ������бֱ�ߵ����
			{
				double k = (p[j].y - p[i].y) * 1.0 / (p[j].x - p[i].x);
				double b = (p[j].y * (p[j].x - p[i].x) - (p[j].y - p[i].y) * p[j].x) * 1.0 / (p[j].x - p[i].x);
				//double b = p[j].y - k * p[j].x; �������ַ���������k��ɾ��ȱ�ը
				lines.insert(pair<double, double>(k, b));
			}

		}
	}
	cout << lines.size() + 20 + 21 << endl; // �ܵ�ֱ��=бֱ��+��ֱ��+��ֱ��
	return 0;
}
