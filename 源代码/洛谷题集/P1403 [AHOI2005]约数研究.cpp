#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=n/i;
	}
	printf("%d",ans);
	
	return 0;
}

/*
** f(i)=n/i **
至于公式是怎么推出来的，看我解释：

1-n的因子个数，可以看成共含有2因子的数的个数+含有3因子的数的个数……+含有n因子的数的个数

但在1~n中含有“2”这个因子的数有n/2个，3有n/3个，以此类推，公式就出来了


*/
