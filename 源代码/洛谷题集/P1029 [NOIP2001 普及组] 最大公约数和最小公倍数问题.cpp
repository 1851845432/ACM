#include<iostream>
#include<math.h>
using namespace std;
int  gcd(int x,int y){
	if(!y)return x;
	gcd(y,x%y);
}
int lcm(int x,int y){
	return x/gcd(x,y)*y;
}
int main(){
	int x,y;
	cin>>x>>y;
	int ans=0;
	if(x==y)ans--;
	for(int i=1;i<=sqrt(x*y);i++)
		if(x*y%i==0 && gcd(i,x*y/i)==x)	ans+=2;	
		
	cout<<ans<<endl;
	
	return 0;
} 
/*两个数的最大公约数与最小公倍数的乘积等于这两个数的乘积
   两个数的积的最大的因子为对其取根号
   	如果积的两个因子的最大公因数等于原本两个数的最大公约数
	   ，这两个数的最小公倍数也相同 （因为积相同，且最大公因数相同，则最小公倍数一定相同） 
 
