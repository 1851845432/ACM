#include<stdio.h>
int main()
{
	int n = 4;
	int a, b;
	char c;
	while (n--) {
		printf("请输入表达式（如5/2）：");
		scanf("%d%c%d", &a, &c, &b);
		switch (c) 
		{
		case '+': {
			printf("%d+%d=%d\n", a, b, a + b);
			break;
		}
		case '*': {
			printf("%d*%d=%d\n", a, b, a * b);
			break;
		}
		case '/': {
			if (b == 0) {
				printf("The divisor can not be zero.\n");
				break;
			}
			printf("%d/%d=%d\n", a, b, a / b);
			break;
		}
		case '%': {
			if (b == 0) {
				printf("The divisor can not be zero.\n");
				break;
			}
			printf("%d%%%d=%d\n", a, b, a % b);
			break;
		}
		}
	}
	return 0;
}
