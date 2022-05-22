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
	printf("请输入需要添加的学生信息数 >> ");
	scanf("%d", &n);
	int i,  flag;
	double maxn = 0;
	for (i = 0; i < n; i++) {
		int j;
		printf("请输入学生的学号 >> ");
		scanf("%d", &stu[i].ID);
		printf("请输入学生姓名 >> ");
		scanf("%s", stu[i].name);
		getchar();
		printf("请分别输入学生的四门成绩(以空格隔开) >> ");
		for (j = 0; j < 4; j++) {
			scanf("%lf", &stu[i].cj[j]);
			stu[i].aver += stu[i].cj[j] / 4;
		}
		if (stu[i].aver > maxn) {
			maxn = stu[i].aver;
			flag = i;
		}
		printf("第一位学生的信息录入完毕！请录入下一位学生的信息 \n");
	}
	struct student p;
	p = stu[0];
	stu[0] = stu[flag];
	stu[flag] = p;
	printf("\n学生的学号      学生的姓名         学生四门课的成绩\n");
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
