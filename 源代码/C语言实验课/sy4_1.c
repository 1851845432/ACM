#include<stdio.h>
	int cj[30];//记录成绩 
	int T[110];//桶 
	int dj[9];//记录分数段的等级 
	char name[30][30];//记录姓名 
	int unname[30];//记录不及格的学生的编号 
int main(){
	int i=0,j=0,num=0;
	int un=0; 
	while(1){
	printf("请输入成绩和姓名，以空格隔开(输入负数则停止输入)：");
	scanf("%d",&cj[i]);
	T[cj[i]]++; 
	if(cj[i]<0)break;
	getchar();
	scanf("%s",name+i);
	i++;
	}
	num=i;
	for(j=0;j<i;j++){
		if(cj[j]<60)
		{
		unname[un]=j;
		un++;	
		}	
	}
	printf("不及格的人数为：%d\n",un); 
	printf("不及格的学生名单：");
	for(i=0;i<un;i++){
		printf("%s\t",name+unname[i]); 
	}
	printf("\n");
	for(i=100;i>=0;i--){//按照成绩高低输出姓名与成绩 
		while(T[i]){
			if(i<60)dj[0]++;
			else if(i>=60 && i<70)dj[1]++;
			else if(i>=70 && i<80)dj[2]++;
			else if(i>=80 && i<90)dj[3]++;
			else if(i>=90 && i<100)dj[4]++;
			else dj[5]++; 
			for(j=0;j<=30;j++){
				if(cj[j]==i){
				printf("%s：%d\n",name+j,cj[j]);
				break;	
				}
			}
			T[i]--;
		}
	}
	printf("60分以下占比为：%.2lf\n",1.0*dj[0]/num);
	printf("60~69分占比为：%.2lf\n",1.0*dj[1]/num);
	printf("70~79占比为：%.2lf\n",1.0*dj[2]/num);
	printf("80~89占比为：%.2lf\n",1.0*dj[3]/num);
	printf("90~99占比为：%.2lf\n",1.0*dj[4]/num);
	printf("100占比为：%.2lf\n",1.0*dj[5]/num);
	return 0;
}
