#include"all.h"

//��ȡϵͳʱ�� 
void times()
{
	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo=localtime(&rawtime);
	printf("���ڵ�ʱ����: %s",asctime(timeinfo));
}

//�˺��ļ����� 
void Create_File() 
{
    FILE *fp;
    if ((fp = fopen("users.txt","rb+"))==NULL)//����ļ�������                
    {
        if ((fp = fopen("users.txt","wb+"))==NULL)
        {
            printf("�޷������ļ���\n");
            exit(0);          
        }
    }
}

//��·�ļ����� 
void Creat_linestxt()
{
 	FILE *fp;
 	if ((fp = fopen("lines.txt","rb+"))==NULL)//����ļ�������                
 	{
 	    if ((fp = fopen("lines.txt","wb+"))==NULL)
 	    {
 	        printf("�޷������ļ���\n");
 	        exit(0);          
 	    }
 	}
}

//վ���ļ�����
void Creat_stationstxt()
{
	FILE *fp;
	if ((fp = fopen("stations.txt","rb+"))==NULL)//����ļ�������                
	{
	    if ((fp = fopen("stations.txt","wb+"))==NULL)
	    {
	        printf("�޷������ļ���\n");
	        exit(0);          
	    }
	}
}

//ע���˺�(���޸� ����)
void registers()
{    
    users a,b,c;//aΪ��ǰ����������û����ϣ�bΪ�Ѵ����ĵ����û����ϣ�cΪ�ݴ�
    FILE *fp;
    char temp[20];
    system("cls");//���� 
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|       ���û�ע����� ��      |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//�������ʱ��
    fp = fopen("users.txt","r");//ָ���û������ļ���ָ�� 
    fread(&b, sizeof(struct The_users), 1, fp);//����һ���ṹ���ַ��� ��b
    while(1)//�ж��ֻ����Ƿ�Ϊ11λ 
    {
    	printf("�������ֻ��� >> ");
		scanf("%s",c.phone); 
		getchar();
		if(strlen(c.phone)==11)
		{
			strcpy(a.phone,c.phone);
			break;
		}
		else
		{
			printf("��ȷ����������ֻ���λ���Ƿ�Ϊ 11 λ\n");
		}
	}
    while (1)
    {    
        if (strcmp(a.phone, b.phone)) //������������
        {
            if (!feof(fp))//���δ���ļ�β
            {
                fread(&b, sizeof(struct The_users), 1, fp);//��ȡ��һ�У������жϡ� 
            }
            else
            {
				break;
			}
        }
        else
        {   
            system("cls");//���� 
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|          ���û��Ѵ���        |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();//�������ʱ��
			system("pause");
            fclose(fp);
            return;      
        }
    }
    printf("���������� >> ");
    scanf("%s",a.name);
    getchar();
    while(1)//�ж����֤���Ƿ�Ϊ18λ 
	{
	    printf("���������֤�� >> ");
		scanf("%s",c.id); 
		getchar();
		if(strlen(c.id)==18)
		{
			strcpy(a.id,c.id);
			break;
		}
		else
		{
			printf("��ȷ����������ֻ���λ���Ƿ�Ϊ 18 λ\n");
		}
	}
    printf("����������(16λ����) >> ");
    scanf("%s",a.password);
    getchar();
    printf("��ȷ������ >> ");
    scanf("%s",temp);
    getchar();
    do
	{
    	if(!strcmp(a.password,temp))
		{
          	fp = fopen("users.txt","a");
           	fwrite(&a, sizeof(users), 1, fp);
           	system("cls");//���� 
		   	printf("--------------------------------\n");
		   	printf("|                              |\n");
		   	printf("|            ע��ɹ�          |\n");
		   	printf("|                              |\n");
		   	printf("|           �뷵�ص�¼         |\n");
			printf("|                              |\n");
		   	printf("--------------------------------\n");
		   	times();//�������ʱ��
           	system("pause");
           	fclose(fp);
		  	return;
    	}
		else
		{
			printf("�������벻ƥ�䣡���������룡\n");
			scanf("%s",a.password);
			printf("��ȷ������\n");
			scanf("%s",temp);
		}
   }while(1);
}

//��¼ϵͳ 
void login()
{
    users a,b;//��b�����μ�¼�ļ��е�ÿһ���û����ϣ����뵱ǰ������û�����a���ȶ� 
              //����û��Ƿ�ע�� 
    FILE *fp;
    system("cls");//���� 
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|       ���û���½���� ��      |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//�������ʱ�� 
    fp=fopen("users.txt","r");
    fread(&b, sizeof(struct The_users), 1, fp); //����һ���ṹ�� д��b
    printf("�����������ֻ��� >> ");
    scanf("%s",a.phone);   
    while (1)
    {   
    	if(strcmp(a.phone, b.phone)==0)         //����д��û���
        {
            break;       
        }
        else 
        {
            if (!feof(fp))  //����ļ�û�ж���                            
            {
                fread(&b, sizeof(struct The_users), 1, fp);
            }
            else
            {
                system("cls");//���� 
				printf("--------------------------------\n");
				printf("|                              |\n");
				printf("|        ���û���������        |\n");
				printf("|                              |\n");
				printf("|          �����µ�½          |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();//�������ʱ�� 
				system("pause");
                fclose(fp);  
        		return;              
            }
        }
    }
    printf("���������� >> ");
    scanf("%s",a.password); 
    do
	{  
		if (strcmp(a.password, b.password)==0)//�������ƥ��
        { 
           	fclose(fp);
           	system("cls");//���� 
			printf("--------------------------------\n");
		   	printf("|                              |\n");
		   	printf("|           ��½�ɹ�           |\n");
		   	printf("|                              |\n");
		   	printf("--------------------------------\n");
		   	times();//�������ʱ�� 
		   	system("pause"); 
          	after_login_menu(b);
			return; 
        }
        else
        {    
			system("cls");//���� 
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|           �������           |\n");
			printf("|                              |\n");
			printf("|          �����µ�½          |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();//�������ʱ�� 
			system("pause");       
        }
	}while(strcmp(a.password, b.password)==0);      
}

//�޸�����ϵͳ
void changepassport(users t)
{
 	FILE *fp;
 	users temp;
 	char newpassword1[16],newpassword2[16];
 	while(1)
	{
	 	system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|          ���޸����� ��       |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
	 	printf("������������ >> "); 
	 	scanf("%s",newpassword1); 
	 	getchar();
	 	printf("��ȷ������������ >> ");
	 	scanf("%s",newpassword2); 
	 	getchar();
	 	if(!strcmp(newpassword1,newpassword2))
	 	{
	 		break;
	 	}
	 	else
	 	{
	 		printf("�������벻ƥ�䣡���������룡\n");
	 		system("pause"); 
	 	}
	} 
 	fp=fopen("users.txt","r+");
 	while(fread(&temp,sizeof(users),1,fp))
	{
 		if(!strcmp(temp.phone,t.phone))
		{
 			strcpy(temp.password,newpassword1);
 			fseek(fp,-sizeof(users),SEEK_CUR);//ָ�������޸�Ŀ��ǰ
 			fwrite(&temp,sizeof(users),1,fp);
 			fclose(fp);	
 			system("cls");
 			printf("--------------------------------\n");
 			printf("|                              |\n");
 			printf("|         �޸�����ɹ���       |\n");
 			printf("|                              |\n");
 			printf("|          �����µ�½          |\n");
 			printf("|                              |\n");
 			printf("--------------------------------\n");
 			times();//�������ʱ�� 
 			system("pause"); 
 			return;
 		}
	}		
}

//��ֵϵͳ
double Recharge(users t)
{
	FILE *fp;
	double moneyadd;//��ֵ���
	users temp;
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|           ��ֵ���           |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//�������ʱ�� 
	printf("����������Ҫ��ֵ�Ľ�� >> "); 
	scanf("%lf",&moneyadd);
	fp=fopen("users.txt","r+") ;
	while(fread(&temp,sizeof(users),1,fp))
	{
		if(!strcmp(temp.phone,t.phone))
		{
			temp.money+=moneyadd;
			fseek(fp,-sizeof(users),SEEK_CUR);//ָ�������޸�Ŀ��ǰ 
			fwrite(&temp,sizeof(users),1,fp);
			system("cls");	
			printf("-----------------------------------------\n");
			printf("|\t\t\t\t\t|\n");
			printf("|\t\t��ֵ�ɹ���\t\t|\n");
			printf("|\t\t\t\t\t|\n");
			printf("\t����ǰ�����Ϊ����%.2lf\t\t\n",temp.money);
			printf("|\t\t\t\t\t|\n");
			printf("-----------------------------------------\n");
			times();//�������ʱ�� 
			fclose(fp);	
			system("pause"); 
			return temp.money;
		}
	}
	return t.money;
}
 
//��·����ϵͳ
void linesInput()
{
	FILE *fp;
	Line a,b;
 	if((fp=fopen("lines.txt","r+"))==NULL)
	{
 		printf("���ļ�ʧ�ܣ�\n"); 
 		return; 
 	}
 	else
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ����·���� ��        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		printf("������Ҫ�������·��� >> "); 
		scanf("%s",a.line_number);
		getchar();
		fread(&b, sizeof(Line), 1, fp);
 		while(1)
		{
 			if(strcmp(a.line_number, b.line_number))//������������
 			{
 			    if(!feof(fp))//���δ���ļ�β                                                                     
 			    {
 			        fread(&b, sizeof(Line), 1, fp);//��ȡ��һ�У������жϡ� 
 			    }
 			    else
 			    {
				 	break;
				}
 			}
 		    else
 			{
 				system("cls");
				printf("--------------------------------\n");
				printf("|                              |\n");
				printf("|          ����·�Ѵ���        |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();//�������ʱ�� 		                 
 				fclose(fp); 
 				system("pause"); 
 				return;
 			}
 		}
 		printf("������·�������� >> ");
 		scanf("%s",a.line_name);
 		getchar();
 		printf("������·��Ӣ���� >> ");
 		scanf("%s",a.line_EnglishName);
 		getchar();
 		printf("�������·�ߵĵ�һ��վ���� >> ");
 		scanf("%s",a.firststation_number);
 		getchar();
 		printf("�������·�ߵ����һ��վ���� >> ");
 		scanf("%s",a.laststation_number);
 		getchar();
 		printf("�������·�ߵĳ������� >> ");
 		scanf(" %s",a.startdate);
 		fwrite(&a, sizeof(Line), 1, fp);
 		system("cls");
 		printf("--------------------------------\n");
 		printf("|                              |\n");
 		printf("|         ��·����ɹ�         |\n");
 		printf("|                              |\n");
 		printf("--------------------------------\n");
 		times();//�������ʱ��
 		system("pause");
 		fclose(fp);
 		return;
 	}			
 } 
 
//վ������ϵͳ����վ�㲻���ڣ� 
void stationsInput()
{
 	FILE *fp;
 	Station a,b;
 	if((fp=fopen("stations.txt","r+"))==NULL)
	{
 		printf("���ļ�ʧ�ܣ�\n"); 
 		return; 
 	}
 	else
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ����·���� ��        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
 		printf("������Ҫ�����վ���� >> "); 
 		scanf("%s",a.station_number);
 		getchar();
 		fread(&b, sizeof(Station), 1, fp);
 		while(1)
		{
 			if(strcmp(a.station_number, b.station_number)) //������������
 			{
 			    if(!feof(fp))//���δ���ļ�β
 			    {
 			        fread(&b, sizeof(Station), 1, fp);//��ȡ��һ�У������ж�
 			    }
 			    else
 			    {
 			        break;
 			    }
 		    }
 		    else
 			{
 				system("cls");
				printf("--------------------------------\n");
				printf("|                              |\n");
				printf("|          ����·�Ѵ���        |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();//�������ʱ��		                 
				fclose(fp); 
				system("pause"); 
 				return;      
 			}
 		}
 		printf("�������վ��������·��� >> ");
 		scanf("%s",a.belongLine_number);
 		getchar();
 		printf("�������վ��������� >> ");
 		scanf("%s",a.station_name);
 		getchar();
 		printf("�������վ��Ӣ���� >> ");
 		scanf("%s",a.station_Englishname);
 		getchar();
 		printf("�������վ�����Ϣ >> ");
 		scanf("%s",a.station_information);
 		getchar();
 		fwrite(&a, sizeof(Station), 1, fp);
 		system("cls");
 		printf("--------------------------------\n");
 		printf("|                              |\n");
 		printf("|         վ�����ɹ�         |\n");
 		printf("|                              |\n");
 		printf("--------------------------------\n");
 		times();//�������ʱ��
 		system("pause");
 		fclose(fp);
 		return;
 	}			
 }
 
