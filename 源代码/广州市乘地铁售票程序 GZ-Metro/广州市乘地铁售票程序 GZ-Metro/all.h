#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define MAXN 100000
typedef struct The_users   
{
	char phone[20];
    char id[20];
    char name[16];
    char password[16]; 
 	double money;
}users;
typedef struct line
{
	char line_number[20];
	char line_name[50];
	char line_EnglishName[50];
	char firststation_number[20];
	char laststation_number[20];
	char startdate[20];	
}Line;
typedef struct station
{
	char belongLine_number[20];
	char station_number[20];
	char station_name[20];
	char station_Englishname[20];
	char station_information[20];
}Station;
void head_menu();
void manager_menu();
void user_menu();
void times();
void Create_File();
void registers();
void login();
void after_login_menu(users t);
void changepassport(users t);
double Recharge(users t);
void inquire_money_menu(double m);
void Creat_linestxt();
void linesInput(); 
void Creat_stationstxt();
void stationsInput();
void manager_input_menu();
