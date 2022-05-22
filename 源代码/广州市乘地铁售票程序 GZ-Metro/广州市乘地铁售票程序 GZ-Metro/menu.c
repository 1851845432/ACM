#include"all.h"

//首界面 
void head_menu()
{
	int select;//选择变量 
	while(1)
	{
		system("cls");//清屏 
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("| 欢迎使用广州市乘地铁售票程序 |\n");
		printf("|                              |\n");
		printf("|        ◎1.管理界面 ◎       |\n");
		printf("|                              |\n");
		printf("|        ◎2.用户界面 ◎       |\n");
		printf("|                              |\n");
		printf("|          ◎0.退出 ◎         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间 
		printf("请选择 >> ");
		scanf("%d",&select);//输入选择变量 
			switch (select) 
			{
				case 1:
					manager_menu();
					break;
				case 2:
					user_menu();
					break;
				case 0:
					printf("感谢您的使用！\n");
					Sleep(1000);
					return;
				default:
					printf("请输入一个有效数字\n");
					system("pause");
					break;
			}
	}
}

//管理界面
void manager_menu()
{
	system("cls");//清屏 
	char t[5]; 
	int select;
	printf("请输入管理员密码 >> ");
	scanf("%s",t);
	getchar();
	if(!strcmp(t,"admin"))
	{
		printf("密码正确\n");
	}
	else
	{
		printf("密码错误\n");
		system("pause");
		return;
	}
	while(1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ◎管理界面 ◎        |\n");
		printf("|                              |\n");
		printf("|        ◎1.输入功能 ◎       |\n");
		printf("|                              |\n");
		printf("|        ◎2.查询功能 ◎       |\n");
		printf("|                              |\n");
		printf("|        ◎3.修改功能 ◎       |\n");
		printf("|                              |\n");
		printf("|       ◎0.返回上一级 ◎      |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间 
		printf("请选择 >> ");
		scanf("%d",&select);
		switch (select) 
		{
			case 1:
				manager_input_menu(); 
				break;
			case 2:
				break;
			case 3:
				break;
			case 0:
				system("pause");
				return;
			default:
				printf("请输入一个有效数字\n");
				system("pause");
				break;
		}
	}
}

//管理输入界面
void manager_input_menu()
{
	int select;
	while(1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ◎输入界面 ◎        |\n");
		printf("|                              |\n");
		printf("|        ◎1.线路输入 ◎       |\n");
		printf("|                              |\n");
		printf("|        ◎2.站点输入 ◎       |\n");
		printf("|                              |\n");
		printf("|       ◎0.返回上一级 ◎      |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间 
		printf("请选择 >> ");
		scanf("%d",&select);
		switch (select) 
		{
			case 1:
				linesInput(); 
				break;
			case 2:
				stationsInput();
				break;
			case 0:
				system("pause");
				return;
			default:
				printf("请输入一个有效数字\n");
				system("pause");
				break;
		}
	}
} 

//用户界面
void user_menu()
{
	int select; 
	while(1)
		{
			system("cls");//清屏 
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|         ◎用户界面 ◎        |\n");
			printf("|                              |\n");
			printf("|          ◎1.登陆 ◎         |\n");
			printf("|                              |\n");
			printf("|          ◎2.注册 ◎         |\n");
			printf("|                              |\n");
			printf("|       ◎0.返回上一级 ◎      |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();//输出现在时间 
			printf("请选择 >> ");
			scanf("%d",&select);
			switch (select) 
			{
				case 1:
					login();
					break;
				case 2:
					registers();
					break;
				case 0:
					system("pause");
					return;
				default:
					printf("请输入一个有效数字\n");
					system("pause");
					break;
			}
		}
} 

//登陆后界面
void after_login_menu(users t)
{
	int select;
	double m=t.money;
	while(1)
		{
			system("cls");//清屏 
			printf("------------------------------------------\n");
			printf("|                                        |\n");
			printf("|\t\t%s，欢迎您\t\t|\n",t.name);
			printf("|                                        |\n");
			printf("|             ◎1.购买车票 ◎            |\n");
			printf("|                                        |\n");
			printf("|             ◎2.修改密码 ◎            |\n");
			printf("|                                        |\n");
			printf("|             ◎3.充值余额 ◎            |\n");
			printf("|                                        |\n");
			printf("|             ◎4.查询余额 ◎            |\n");
			printf("|                                        |\n");
			printf("|             ◎0.退出登录 ◎            |\n");
			printf("|                                        |\n");
			printf("------------------------------------------\n");
			times();//输出现在时间 
			printf("请选择 >> ");
			scanf("%d",&select);
			switch (select) 
			{
				case 1:
					break;
				case 2:
					changepassport(t); 
					return; 
				case 3:
					m=Recharge(t);
					break;
				case 4:
					inquire_money_menu(m);
					break;
				case 0:
					system("pause");
					return;
				default:
					printf("请输入一个有效数字\n");
					system("pause");
					break;
			}
	}
	return; 
}

//余额查询界面
void inquire_money_menu(double m)
{
	system("cls");//清屏 
	printf("-----------------------------------------\n");
	printf("|                                       |\n");
	printf("|\t您的余额为：￥%.2lf\t\t|\n",m);
	printf("|                                       |\n");
	printf("-----------------------------------------\n");
	times();//输出现在时间 
	system("pause");
	return; 
}
