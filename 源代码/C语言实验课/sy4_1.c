#include<stdio.h>
	int cj[30];//��¼�ɼ� 
	int T[110];//Ͱ 
	int dj[9];//��¼�����εĵȼ� 
	char name[30][30];//��¼���� 
	int unname[30];//��¼�������ѧ���ı�� 
int main(){
	int i=0,j=0,num=0;
	int un=0; 
	while(1){
	printf("������ɼ����������Կո����(���븺����ֹͣ����)��");
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
	printf("�����������Ϊ��%d\n",un); 
	printf("�������ѧ��������");
	for(i=0;i<un;i++){
		printf("%s\t",name+unname[i]); 
	}
	printf("\n");
	for(i=100;i>=0;i--){//���ճɼ��ߵ����������ɼ� 
		while(T[i]){
			if(i<60)dj[0]++;
			else if(i>=60 && i<70)dj[1]++;
			else if(i>=70 && i<80)dj[2]++;
			else if(i>=80 && i<90)dj[3]++;
			else if(i>=90 && i<100)dj[4]++;
			else dj[5]++; 
			for(j=0;j<=30;j++){
				if(cj[j]==i){
				printf("%s��%d\n",name+j,cj[j]);
				break;	
				}
			}
			T[i]--;
		}
	}
	printf("60������ռ��Ϊ��%.2lf\n",1.0*dj[0]/num);
	printf("60~69��ռ��Ϊ��%.2lf\n",1.0*dj[1]/num);
	printf("70~79ռ��Ϊ��%.2lf\n",1.0*dj[2]/num);
	printf("80~89ռ��Ϊ��%.2lf\n",1.0*dj[3]/num);
	printf("90~99ռ��Ϊ��%.2lf\n",1.0*dj[4]/num);
	printf("100ռ��Ϊ��%.2lf\n",1.0*dj[5]/num);
	return 0;
}
