#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
struct student {
	char name[MAX];
	int ID;
	double cj[9];
	double aver;
}stu[MAX];
int main() {
	int n;
	memset(stu, 0, sizeof(struct student) * MAX);
	printf("��������Ҫ��ӵ�ѧ����Ϣ�� >> ");
	scanf("%d", &n);
	int i,  flag;
	double maxn = 0;
	for (i = 0; i < n; i++) {
		int j;
		printf("������ѧ����ѧ�� >> ");
		scanf("%d", &stu[i].ID);
		printf("������ѧ������ >> ");
		scanf("%s", stu[i].name);
		getchar();
		printf("��ֱ�����ѧ�������ųɼ�(�Կո����) >> ");
		for (j = 0; j < 4; j++) {
			scanf("%lf", &stu[i].cj[j]);
			stu[i].aver += stu[i].cj[j] / 4;
		}
		if (stu[i].aver > maxn) {
			maxn = stu[i].aver;
			flag = i;
		}
		printf("��һλѧ������Ϣ¼����ϣ���¼����һλѧ������Ϣ \n");
	}
	struct student p;
	p = stu[0];
	stu[0] = stu[flag];
	stu[flag] = p;
	printf("\nѧ����ѧ��      ѧ��������         ѧ�����ſεĳɼ�\n");
	for (i = 0; i < n; i++) {
		int j;
		printf("%5d%15s", stu[i].ID, stu[i].name);
		printf("\t\t"); 
		for (j = 0; j < 4; j++) {
			printf("%5.1lf", stu[i].cj[j]);
		}
		printf("\n");
	}

	return 0;
}
