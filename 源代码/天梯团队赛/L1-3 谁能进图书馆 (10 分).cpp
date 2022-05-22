#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int mod=1e9+7;


int main(){
//	freopen("in.txt","r",stdin);
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	int la=0,lb=0;
	la=a>=n?1:0;
	lb=b>=n?1:0;
	if(la &&lb){
		printf("%d-Y %d-Y\n",a,b);
		puts("huan ying ru guan");
	}
	else if(!la && !lb){
		printf("%d-N %d-N\n",a,b);
		puts("zhang da zai lai ba");
	}else if((la && !lb) || (!la && lb)){
		if(a>=m || b>=m){
			printf("%d-Y %d-Y\n",a,b);
			printf("qing %d zhao gu hao %d\n",la?1:2,la?2:1);
		}
		else {
			if(la)printf("%d-Y %d-N\n",a,b);
			else printf("%d-N %d-Y\n",a,b);
			printf("%d: huan ying ru guan\n",la?1:2);
		}
	}

	return 0;
}
