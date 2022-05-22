#include<stdio.h>
#include<string.h>
#include<math.h>
/*
100bc89202*1
q2t0
*/
extract(char*a,int d[])
{
	int i,j,num=0,ans=0,t=0;
	for(i=0,j=0; i<=strlen(a); i++)
	{
		if(a[i]=='0' && !num)
		{
			d[ans++]=0;
			continue;
		}
		if(a[i]>='0' && a[i]<='7')
		{
			num=num*10+(a[i]-'0');
		}
		else
		{
			while(num)
			{
				int x=num%10;
				t+=x*pow(8,j);
				j++;
				num/=10;
			}
			j=0;
			if(t){
				d[ans++]=t;
				t=0;
			}
		}
	}
	for(i=0; i<ans; i++)
	{
		printf("%d ",d[i]);
	}
}
int main()
{
	int i;
	char s[100];
	int ss[100]= {0};
	scanf("%s",s);
	extract(s,ss);

	return 0;
}
