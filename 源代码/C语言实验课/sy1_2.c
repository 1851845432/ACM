#include<stdio.h> 
int main()
{
	int x;
	printf("«Î ‰»Î∑÷ ˝£∫"); 
	scanf("%d",&x);
	switch (x/10)
	{
	case 0:
	{
		printf("Range:0 - 2\n");
		printf("Level:Guess\n");
		break;
	}
	case 1:
	{
		printf("Range:3-16\n");
		printf("Level:Elementary\n");
		break;
	}
	case 2:
	{
		printf("Range:3-16\n");
		printf("Level:Elementary\n");
		break;
	}
	case 3:
	{
		printf("Range:16-25\n");
		printf("Level:Good\n");
		break;
	}
	case 4:
	{
		printf("Range:26-30\n");
		printf("Level:Excellent\n");
		break;
	}
	}



	return 0;
}
