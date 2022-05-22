#include"all.h"

//获取系统时间 
void times()
{
	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo=localtime(&rawtime);
	printf("现在的时间是: %s",asctime(timeinfo));
}

//账号文件创建 
void Create_File() 
{
    FILE *fp;
    if ((fp = fopen("users.txt","rb+"))==NULL)//如果文件不存在                
    {
        if ((fp = fopen("users.txt","wb+"))==NULL)
        {
            printf("无法建立文件！\n");
            exit(0);          
        }
    }
}

//线路文件创建 
void Creat_linestxt()
{
 	FILE *fp;
 	if ((fp = fopen("lines.txt","rb+"))==NULL)//如果文件不存在                
 	{
 	    if ((fp = fopen("lines.txt","wb+"))==NULL)
 	    {
 	        printf("无法建立文件！\n");
 	        exit(0);          
 	    }
 	}
}

//站点文件创建
void Creat_stationstxt()
{
	FILE *fp;
	if ((fp = fopen("stations.txt","rb+"))==NULL)//如果文件不存在                
	{
	    if ((fp = fopen("stations.txt","wb+"))==NULL)
	    {
	        printf("无法建立文件！\n");
	        exit(0);          
	    }
	}
}

//注册账号(待修改 限制)
void registers()
{    
    users a,b,c;//a为当前即将输入的用户资料，b为已存入文档的用户资料，c为暂存
    FILE *fp;
    char temp[20];
    system("cls");//清屏 
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|       ◎用户注册界面 ◎      |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//输出现在时间
    fp = fopen("users.txt","r");//指向用户资料文件的指针 
    fread(&b, sizeof(struct The_users), 1, fp);//读入一个结构体字符块 到b
    while(1)//判断手机号是否为11位 
    {
    	printf("请输入手机号 >> ");
		scanf("%s",c.phone); 
		getchar();
		if(strlen(c.phone)==11)
		{
			strcpy(a.phone,c.phone);
			break;
		}
		else
		{
			printf("请确认您输入的手机号位数是否为 11 位\n");
		}
	}
    while (1)
    {    
        if (strcmp(a.phone, b.phone)) //如果两串不相等
        {
            if (!feof(fp))//如果未到文件尾
            {
                fread(&b, sizeof(struct The_users), 1, fp);//读取下一行，依次判断。 
            }
            else
            {
				break;
			}
        }
        else
        {   
            system("cls");//清屏 
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|          此用户已存在        |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();//输出现在时间
			system("pause");
            fclose(fp);
            return;      
        }
    }
    printf("请输入姓名 >> ");
    scanf("%s",a.name);
    getchar();
    while(1)//判断身份证号是否为18位 
	{
	    printf("请输入身份证号 >> ");
		scanf("%s",c.id); 
		getchar();
		if(strlen(c.id)==18)
		{
			strcpy(a.id,c.id);
			break;
		}
		else
		{
			printf("请确认您输入的手机号位数是否为 18 位\n");
		}
	}
    printf("请输入密码(16位以下) >> ");
    scanf("%s",a.password);
    getchar();
    printf("请确认密码 >> ");
    scanf("%s",temp);
    getchar();
    do
	{
    	if(!strcmp(a.password,temp))
		{
          	fp = fopen("users.txt","a");
           	fwrite(&a, sizeof(users), 1, fp);
           	system("cls");//清屏 
		   	printf("--------------------------------\n");
		   	printf("|                              |\n");
		   	printf("|            注册成功          |\n");
		   	printf("|                              |\n");
		   	printf("|           请返回登录         |\n");
			printf("|                              |\n");
		   	printf("--------------------------------\n");
		   	times();//输出现在时间
           	system("pause");
           	fclose(fp);
		  	return;
    	}
		else
		{
			printf("两次密码不匹配！请重新输入！\n");
			scanf("%s",a.password);
			printf("请确认密码\n");
			scanf("%s",temp);
		}
   }while(1);
}

//登录系统 
void login()
{
    users a,b;//用b来依次记录文件中的每一个用户资料，并与当前输入的用户资料a作比对 
              //检查用户是否注册 
    FILE *fp;
    system("cls");//清屏 
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|       ◎用户登陆界面 ◎      |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//输出现在时间 
    fp=fopen("users.txt","r");
    fread(&b, sizeof(struct The_users), 1, fp); //读入一个结构体 写入b
    printf("请输入您的手机号 >> ");
    scanf("%s",a.phone);   
    while (1)
    {   
    	if(strcmp(a.phone, b.phone)==0)         //如果有此用户名
        {
            break;       
        }
        else 
        {
            if (!feof(fp))  //如果文件没有读完                            
            {
                fread(&b, sizeof(struct The_users), 1, fp);
            }
            else
            {
                system("cls");//清屏 
				printf("--------------------------------\n");
				printf("|                              |\n");
				printf("|        此用户名不存在        |\n");
				printf("|                              |\n");
				printf("|          请重新登陆          |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();//输出现在时间 
				system("pause");
                fclose(fp);  
        		return;              
            }
        }
    }
    printf("请输入密码 >> ");
    scanf("%s",a.password); 
    do
	{  
		if (strcmp(a.password, b.password)==0)//如果密码匹配
        { 
           	fclose(fp);
           	system("cls");//清屏 
			printf("--------------------------------\n");
		   	printf("|                              |\n");
		   	printf("|           登陆成功           |\n");
		   	printf("|                              |\n");
		   	printf("--------------------------------\n");
		   	times();//输出现在时间 
		   	system("pause"); 
          	after_login_menu(b);
			return; 
        }
        else
        {    
			system("cls");//清屏 
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|           密码错误           |\n");
			printf("|                              |\n");
			printf("|          请重新登陆          |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();//输出现在时间 
			system("pause");       
        }
	}while(strcmp(a.password, b.password)==0);      
}

//修改密码系统
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
		printf("|          ◎修改密码 ◎       |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
	 	printf("请输入新密码 >> "); 
	 	scanf("%s",newpassword1); 
	 	getchar();
	 	printf("请确认您的新密码 >> ");
	 	scanf("%s",newpassword2); 
	 	getchar();
	 	if(!strcmp(newpassword1,newpassword2))
	 	{
	 		break;
	 	}
	 	else
	 	{
	 		printf("两次密码不匹配！请重新输入！\n");
	 		system("pause"); 
	 	}
	} 
 	fp=fopen("users.txt","r+");
 	while(fread(&temp,sizeof(users),1,fp))
	{
 		if(!strcmp(temp.phone,t.phone))
		{
 			strcpy(temp.password,newpassword1);
 			fseek(fp,-sizeof(users),SEEK_CUR);//指针移至修改目标前
 			fwrite(&temp,sizeof(users),1,fp);
 			fclose(fp);	
 			system("cls");
 			printf("--------------------------------\n");
 			printf("|                              |\n");
 			printf("|         修改密码成功！       |\n");
 			printf("|                              |\n");
 			printf("|          请重新登陆          |\n");
 			printf("|                              |\n");
 			printf("--------------------------------\n");
 			times();//输出现在时间 
 			system("pause"); 
 			return;
 		}
	}		
}

//充值系统
double Recharge(users t)
{
	FILE *fp;
	double moneyadd;//充值金额
	users temp;
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|           充值余额           |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//输出现在时间 
	printf("请输入您需要充值的金额 >> "); 
	scanf("%lf",&moneyadd);
	fp=fopen("users.txt","r+") ;
	while(fread(&temp,sizeof(users),1,fp))
	{
		if(!strcmp(temp.phone,t.phone))
		{
			temp.money+=moneyadd;
			fseek(fp,-sizeof(users),SEEK_CUR);//指针移至修改目标前 
			fwrite(&temp,sizeof(users),1,fp);
			system("cls");	
			printf("-----------------------------------------\n");
			printf("|\t\t\t\t\t|\n");
			printf("|\t\t充值成功！\t\t|\n");
			printf("|\t\t\t\t\t|\n");
			printf("\t您当前的余额为：￥%.2lf\t\t\n",temp.money);
			printf("|\t\t\t\t\t|\n");
			printf("-----------------------------------------\n");
			times();//输出现在时间 
			fclose(fp);	
			system("pause"); 
			return temp.money;
		}
	}
	return t.money;
}
 
//线路输入系统
void linesInput()
{
	FILE *fp;
	Line a,b;
 	if((fp=fopen("lines.txt","r+"))==NULL)
	{
 		printf("打开文件失败！\n"); 
 		return; 
 	}
 	else
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ◎线路输入 ◎        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		printf("请输入要输入的线路编号 >> "); 
		scanf("%s",a.line_number);
		getchar();
		fread(&b, sizeof(Line), 1, fp);
 		while(1)
		{
 			if(strcmp(a.line_number, b.line_number))//如果两串不相等
 			{
 			    if(!feof(fp))//如果未到文件尾                                                                     
 			    {
 			        fread(&b, sizeof(Line), 1, fp);//读取下一行，依次判断。 
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
				printf("|          该线路已存在        |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();//输出现在时间 		                 
 				fclose(fp); 
 				system("pause"); 
 				return;
 			}
 		}
 		printf("请输入路线中文名 >> ");
 		scanf("%s",a.line_name);
 		getchar();
 		printf("请输入路线英文名 >> ");
 		scanf("%s",a.line_EnglishName);
 		getchar();
 		printf("请输入该路线的第一个站点编号 >> ");
 		scanf("%s",a.firststation_number);
 		getchar();
 		printf("请输入该路线的最后一个站点编号 >> ");
 		scanf("%s",a.laststation_number);
 		getchar();
 		printf("请输入该路线的初建日期 >> ");
 		scanf(" %s",a.startdate);
 		fwrite(&a, sizeof(Line), 1, fp);
 		system("cls");
 		printf("--------------------------------\n");
 		printf("|                              |\n");
 		printf("|         线路加入成功         |\n");
 		printf("|                              |\n");
 		printf("--------------------------------\n");
 		times();//输出现在时间
 		system("pause");
 		fclose(fp);
 		return;
 	}			
 } 
 
//站点输入系统（若站点不存在） 
void stationsInput()
{
 	FILE *fp;
 	Station a,b;
 	if((fp=fopen("stations.txt","r+"))==NULL)
	{
 		printf("打开文件失败！\n"); 
 		return; 
 	}
 	else
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ◎线路输入 ◎        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
 		printf("请输入要输入的站点编号 >> "); 
 		scanf("%s",a.station_number);
 		getchar();
 		fread(&b, sizeof(Station), 1, fp);
 		while(1)
		{
 			if(strcmp(a.station_number, b.station_number)) //如果两串不相等
 			{
 			    if(!feof(fp))//如果未到文件尾
 			    {
 			        fread(&b, sizeof(Station), 1, fp);//读取下一行，依次判断
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
				printf("|          该线路已存在        |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();//输出现在时间		                 
				fclose(fp); 
				system("pause"); 
 				return;      
 			}
 		}
 		printf("请输入该站点所属线路编号 >> ");
 		scanf("%s",a.belongLine_number);
 		getchar();
 		printf("请输入该站点的中文名 >> ");
 		scanf("%s",a.station_name);
 		getchar();
 		printf("请输入该站点英文名 >> ");
 		scanf("%s",a.station_Englishname);
 		getchar();
 		printf("请输入该站点的信息 >> ");
 		scanf("%s",a.station_information);
 		getchar();
 		fwrite(&a, sizeof(Station), 1, fp);
 		system("cls");
 		printf("--------------------------------\n");
 		printf("|                              |\n");
 		printf("|         站点加入成功         |\n");
 		printf("|                              |\n");
 		printf("--------------------------------\n");
 		times();//输出现在时间
 		system("pause");
 		fclose(fp);
 		return;
 	}			
 }
 
