#include"all.h"

//�׽��� 
void head_menu()
{
	int select;//ѡ����� 
	while(1)
	{
		system("cls");//���� 
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("| ��ӭʹ�ù����г˵�����Ʊ���� |\n");
		printf("|                              |\n");
		printf("|        ��1.������� ��       |\n");
		printf("|                              |\n");
		printf("|        ��2.�û����� ��       |\n");
		printf("|                              |\n");
		printf("|          ��0.�˳� ��         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ�� 
		printf("��ѡ�� >> ");
		scanf("%d",&select);//����ѡ����� 
			switch (select) 
			{
				case 1:
					manager_menu();
					break;
				case 2:
					user_menu();
					break;
				case 0:
					printf("��л����ʹ�ã�\n");
					Sleep(1000);
					return;
				default:
					printf("������һ����Ч����\n");
					system("pause");
					break;
			}
	}
}

//�������
void manager_menu()
{
	system("cls");//���� 
	char t[5]; 
	int select;
	printf("���������Ա���� >> ");
	scanf("%s",t);
	getchar();
	if(!strcmp(t,"admin"))
	{
		printf("������ȷ\n");
	}
	else
	{
		printf("�������\n");
		system("pause");
		return;
	}
	while(1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         �������� ��        |\n");
		printf("|                              |\n");
		printf("|        ��1.���빦�� ��       |\n");
		printf("|                              |\n");
		printf("|        ��2.��ѯ���� ��       |\n");
		printf("|                              |\n");
		printf("|        ��3.�޸Ĺ��� ��       |\n");
		printf("|                              |\n");
		printf("|       ��0.������һ�� ��      |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ�� 
		printf("��ѡ�� >> ");
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
				printf("������һ����Ч����\n");
				system("pause");
				break;
		}
	}
}

//�����������
void manager_input_menu()
{
	int select;
	while(1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ��������� ��        |\n");
		printf("|                              |\n");
		printf("|        ��1.��·���� ��       |\n");
		printf("|                              |\n");
		printf("|        ��2.վ������ ��       |\n");
		printf("|                              |\n");
		printf("|       ��0.������һ�� ��      |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ�� 
		printf("��ѡ�� >> ");
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
				printf("������һ����Ч����\n");
				system("pause");
				break;
		}
	}
} 

//�û�����
void user_menu()
{
	int select; 
	while(1)
		{
			system("cls");//���� 
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|         ���û����� ��        |\n");
			printf("|                              |\n");
			printf("|          ��1.��½ ��         |\n");
			printf("|                              |\n");
			printf("|          ��2.ע�� ��         |\n");
			printf("|                              |\n");
			printf("|       ��0.������һ�� ��      |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();//�������ʱ�� 
			printf("��ѡ�� >> ");
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
					printf("������һ����Ч����\n");
					system("pause");
					break;
			}
		}
} 

//��½�����
void after_login_menu(users t)
{
	int select;
	double m=t.money;
	while(1)
		{
			system("cls");//���� 
			printf("------------------------------------------\n");
			printf("|                                        |\n");
			printf("|\t\t%s����ӭ��\t\t|\n",t.name);
			printf("|                                        |\n");
			printf("|             ��1.����Ʊ ��            |\n");
			printf("|                                        |\n");
			printf("|             ��2.�޸����� ��            |\n");
			printf("|                                        |\n");
			printf("|             ��3.��ֵ��� ��            |\n");
			printf("|                                        |\n");
			printf("|             ��4.��ѯ��� ��            |\n");
			printf("|                                        |\n");
			printf("|             ��0.�˳���¼ ��            |\n");
			printf("|                                        |\n");
			printf("------------------------------------------\n");
			times();//�������ʱ�� 
			printf("��ѡ�� >> ");
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
					printf("������һ����Ч����\n");
					system("pause");
					break;
			}
	}
	return; 
}

//����ѯ����
void inquire_money_menu(double m)
{
	system("cls");//���� 
	printf("-----------------------------------------\n");
	printf("|                                       |\n");
	printf("|\t�������Ϊ����%.2lf\t\t|\n",m);
	printf("|                                       |\n");
	printf("-----------------------------------------\n");
	times();//�������ʱ�� 
	system("pause");
	return; 
}
