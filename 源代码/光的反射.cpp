#include <cstdio>
#include <windows.h>
 #define endx 188
 #define endy 88
void setCursorPosition(int x, int y);
int main(){
	int x,y;
	printf("请输入起始坐标："); 
	scanf("%d%d",&x,&y);
	int v_x=1,v_y=1; 
	while(1){
	//	if(getchar()=='\n'){
			x+=v_x;y+=v_y;
			setCursorPosition(x,y);
			printf("*");
			if(x<=1 || x>=endx)v_x=-v_x;
			if(y<=1 || y>=endy)v_y=-v_y;
     		Sleep(10);
	//	}
		}
return 0;
} 
//自定义的光标定位函数
void setCursorPosition(int x, int y){
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
