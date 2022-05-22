# ACM模板

## 基础算法

### ST表

```c
int Log[N], f[N][21];//第二维由数据大小决定
//输入
	for (int i = 1; i <= n; i++) {
		scanf("%d", &f[i][0]);
	}
//处理
	for (int j = 1; j <= 21; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {//注意边界处理，第二维不能大于n
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
// 查询
	for (int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		int s = Log[r - l + 1];
		printf("%d\n", max(f[l][s], f[r - (1 << s) + 1][s]));
	}


```

### 二维前缀和

```c
s[i][j]=s[i-1][j]+s[i][j-1]+a[i][j]-s[i-1][j-1];//预处理
s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];//查询
```

### 二维差分

```c++
b[i][j]=a[i][j]−a[i−1][j]−a[i][j−1]+a[i−1][j−1]//构造
// 处理
b[x1][y1]+=c;
b[x2+1][y1]-=c;
b[x1][y2+1]-=c;
b[x2+1][y2+1]+=c;
```

### 快速幂

```c
ll ksm(int a, int n) {
	ll ans = 1;
	while (n) {
		if (n & 1)ans = ans * a % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return ans;
} 
```

### 矩阵快速幂

```c
struct matrix
{
    ll x[105][105];
    matrix(){memset(x,0,sizeof(x));}
};
matrix multiply(matrix &a,matrix &b)
{
    matrix c;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                c.x[i][j]+=a.x[i][k]*b.x[k][j];
    return c;
}
matrix mpow(matrix &a,ll m)//矩阵a的m次方
{
    matrix res;
    for(int i=1;i<=n;i++) res.x[i][i]=1;//单位矩阵
    while(m>0)
    {
        if(m&1) res=multiply(res,a);
        a=multiply(a,a);
        m>>=1;
    }
    return res;
}
//重载运算符写法
struct egde{
	int m[N][N];
	egde() {//将结构体初始化的矩阵全部赋值为0
		memset(m, 0, sizeof(m));
	}
	inline void build() {//构建单位矩阵 相当于快速幂初始化时的sum=1;
		for (int i = 1; i <= n; i++) {
			m[i][i] = 1;
		}
	}
} e;
egde operator*(const egde &a, const egde &b) {//重载结构体的乘法为矩阵乘法
	egde x;
	for (inti = 1; i <= n; i++) {
		for (intj = 1; j <= n; j++) {
			for (intk = 1; k <= n; k++) {
				x.m[i][j] = (x.m[i][j] + a.m[i][k] * b.m[k][j] % mod) % mod;
			}
		}
	}
	return x;
}
egde ksm() {
	egde ans;
	ans.build();//构建单位矩阵，相当于ans=1;
	while (k) {
		if (k & 1)ans = ans * e;
		e = e * e;
		k >>= 1;
	}
	return ans;
}
```

### 二分查找

```c
//往左
while (l < r)
{
    int mid = l + r >> 1;	//(l+r)/2
    if (check(mid))  r = mid;    // check()判断mid是否满足性质
    else l = mid + 1;
}
//往右
while (l < r)
{
    int mid = l + r + 1 >> 1;	//(l+r+1)/2
    if (check(mid))  l = mid;
    else r = mid - 1;
}

```

### 二分答案（最大值最小化）最小值最大化）

[P2678 [NOIP2015 提高组] 跳石头](https://www.luogu.com.cn/problem/P2678)

```c++
int a[N];
int d, n, m;
bool C(int x) {
	int cnt = 0;
	int last = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (a[i] - a[last] < x) {
			cnt++;
		} else {
			last = i;
		}
		if (cnt > m) {
			return 0;
		}
	}
	return 1;
}
int main() {
//  freopen("in.txt", "r", stdin);
	cin >> d >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[n + 1] = d;
	int l = 0, r = d;
	int ans = 0;
	while (l <= r) {
       	//二分可能出现的答案
		int mid = l + r >> 1;
		if (C(mid)) {
            //因为是最小距离的最大化，所以向右二分
			ans = mid;//记录答案
			l = mid + 1;//继续寻找
		} else {
			r = mid - 1;//缩小范围
		}
	}
	cout << ans << endl;
	return 0;
}
```



### 三分答案

```c
		while (r - l >= esp) {
			double mar = (r - l) / 3.0;
			double ml, mr ;
			ml = l + mar;
			mr = r - mar;
			if (f(ml) > f(mr))l = ml;
			else r = mr;
		}
```

## 数据结构

### 离散化

```c
sort(C, C + n); // 排序
int l = unique(C, C + n) - C; // 去重
for (int i = 0; i < n; ++i)L[i] = lower_bound(C, C + l, A[i]) - C + 1; // 查找
```

### 树状数组

```c++
//区间修改与区间查询
ll a[N],t1[N],t2[N];
 int n,m;
void add1(int x,int k){
	for(;x<=n;x+=x&-x)t1[x]+=k;
}
void add2(int x,int k){
	for(;x<=n;x+=x&-x)t2[x]+=k;
}
ll ask1(int x){
	ll ans=0;
	for(;x;x-=x&-x)ans+=t1[x];
	return ans;
}
ll ask2(int x){
	ll ans=0;
	for(;x;x-=x&-x)ans+=t2[x];
	return ans;
}
ll ask(int x){
	return ask1(x+1)*(x+1)-ask2(x+1);
}
int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=a[i]-a[i-1];
		add1(i,x);//维护差分数组 
		add2(i,i*x); 
	}
	while(m--){
		int q,x,y,k;
		scanf("%d",&q);
		if(q==1){
			scanf("%d%d%d",&x,&y,&k);
			add1(x,k);add1(y+1,-k);
			add2(x,x*k);add2(y+1,-(y+1)*k); 
		}
		else{
			scanf("%d%d",&x,&y);
			cout<<ask(y)-ask(x-1)<<endl;
		}
	}
	return 0;
}
```

### 线段树

```c++
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#define INF 0x3f3f3f
#define ll long long
#define fre() freopen(".in", "r", stdin);freopen(".out", "w", stdout);
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
const double eps = 1e-6;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
struct tree {
	int l, r;
	ll sum, lazy;
	//sum维护的值，l，r维护区间，lazy懒惰标记
} t[5 * N];
int a[N];
int n, m;
inline void update(int node) {
	t[node].sum = t[node << 1].sum + t[node << 1 | 1].sum;
}
void build(int node, int l, int r) { //建树
	t[node].l = l, t[node].r = r;
	if (t[node].l == t[node].r) {
		t[node].sum = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(node << 1, l, mid);
	build(node << 1 | 1, mid + 1, r);
	update(node);//这里是因为递归后从底部开始维护，回溯时在维护父节点
}
void lazy(int node) { //下传懒惰标记
	if (t[node].lazy) { //如果lazy标记存在，则更新左右子节点
		ll lazy = t[node].lazy;
		int l = node << 1, r = node << 1 | 1;
		t[l].sum += lazy * (t[l].r - t[l].l + 1);
		t[r].sum += lazy * (t[r].r - t[r].l + 1);
		t[l].lazy += lazy;
		t[r].lazy += lazy;
		t[node].lazy = 0;
	}
}
void change(int node, int x, int y, int k) { //区间修改
	if (t[node].l >= x && t[node].r <= y) { //如果需要修改的区间覆盖当前结点的区间
		t[node].sum += (ll)k * (t[node].r - t[node].l + 1); //更新当前结点维护的值
		t[node].lazy += k; //打上懒惰标记
		return ;
	}
	lazy(node);//判断当前结点是否存在懒惰标记，若存在则将标记下移
	int mid = t[node].l + t[node].r >> 1;
	if (x <= mid)change(node << 1, x, y, k);
	if (y > mid)change(node << 1 | 1, x, y, k);
	update(node);//回溯并维护当前结点的区间值
}
ll ask(int node, int x, int y) { //区间查询
	if (x <= t[node].l && y >= t[node].r)return t[node].sum; //如果当前区间被查询区间覆盖则返回当前区间值
	lazy(node);//下传懒惰标记
	int mid = t[node].l + t[node].r >> 1;
	ll ans = 0;
	if (x <= mid)ans += ask(node << 1, x, y);
	if (y > mid)ans += ask(node << 1 | 1, x, y);
	return ans;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	build(1, 1, n);
	int t, x, y, k;
	while (m--) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d%d", &x, &y, &k);
			change(1, x, y, k);
		} else {
			scanf("%d%d", &x, &y);
			printf("%lld\n", ask(1, x, y));
		}
	}
	return 0;
}
```

### 单调栈/单调队列

```c
	int head = 0, tail = -1;
	for (int i = 0; i < n; i++) {
		while (head <= tail && i - k >= q[head])head++;//窗口移动
		while (head <= tail && s[q[tail]] > s[i]) tail--;//维护队列递增，求最小值（若不递增则出队）
		q[++tail] = i;
		if (i >= k - 1)cout << s[q[head]] << ' ';
	}
	cout << endl;
```

### 字典树

```c
int trie[N][26] = {0};
int color[N] = {0};
int k = 1;

void insert(char *w){
    int len = strlen(w);
    int p = 0;
    for(int i=0; i<len; i++){
        int c = w[i] - 'a';
        if(!trie[p][c]){
            trie[p][c] = k;
            k++;
        }
        p = trie[p][c];
    }
    color[p] = 1;
}
int search(char *s){
    int len = strlen(s);
    int p = 0;
    for(int i=0; i<len; i++){
        int c = s[i] - 'a';
        if(!trie[p][c]) return 0;
        p = trie[p][c];
    }
    return color[p] == 1;
}
```

### KMP

```c
const int N = 1e6 + 10;
char a[N], b[N];
int kmp[N];
/*
ABABABC
ABA
*/
int main() {
	//字符串下标从一开始
	cin >> a + 1;
	cin >> b + 1;
	int la = strlen(a + 1);
	int lb = strlen(b + 1);
	int j = 0;
	for (int i = 2; i <= lb; i++) {
		while (j && b[i] != b[j + 1]) j = kmp[j]; //如果不匹配则回溯至当前位置所匹配的最长相同前后缀的长度的下表为位置
		if (b[i] == b[j + 1])j++; //如果匹配成功则继续继续向下匹配
		kmp[i] = j; //记录下当前位置的最长相同前后缀的长度
	}
	j = 0;
	for (int i = 1; i <= la; i++) {
		while (j && a[i] != b[j + 1]) j = kmp[j]; //将模式串与主串进行匹配，如不匹配则回溯
		if (a[i] == b[j + 1])j++; //若匹配则加一
		if (j == lb) { //若长度与模式串长度相等则输出相应的坐标位置
			cout << i - lb + 1 << endl;
			j = kmp[j]; //继续回溯搜索
		}
	}
	for (int i = 1; i <= lb; i++)cout << kmp[i] << " ";
	return 0;
}
```

## 数论

### 欧拉函数

```c++
int euler_phi(int n) {
	int ans = n;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			ans = ans / i * (i - 1);
			while (n % i == 0) n /= i;
		}
	if (n > 1) ans = ans / n * (n - 1);
	return ans;
}
```

### 筛法求欧拉函数

```c++
void pre() {
	memset(is_prime, 1, sizeof(is_prime));
	int cnt = 0;
	is_prime[1] = 0;
	phi[1] = 1;
	for (int i = 2; i <= 5000000; i++) {
		if (is_prime[i]) {
			prime[++cnt] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= cnt && i * prime[j] <= 5000000; j++) {
			is_prime[i * prime[j]] = 0;
			if (i % prime[j])
				phi[i * prime[j]] = phi[i] * phi[prime[j]];
			else {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
		}
	}
}
```

### 组合数

```c++
ll C(int a, int b) {
	ll res = 1;
	for (int i = a, j = 1; j <= b; i--, j++) {
		res = res * i / j;
		if (res > n)return res;
	}
	return res;
}
```

### 质因数分解

```c++
vector<int> ans;
for (int i = 2; i * i <= N; i++) {
	if (N % i == 0) {  // 如果 i 能够整除 N，说明 i 为 N 的一个质因子。
		while (N % i == 0) N /= i;
		ans.push_back(i);
	}
}
if (N != 1) {  // 说明再经过操作之后 N 留下了一个素数
	ans.push_back(N);
}
```

### 扩展欧几里得

```c++
int exgcd(int a, int b, int &x, int &y) { //扩展欧几里得算法
	if (b == 0) {
		x = 1;
		y = 0;
		return a;  //到达递归边界开始向上一层返回
	}
	int gcd = exgcd(b, a % b, y, x);
	y-=(a/b)*x;
	return gcd;     //得到a b的最大公因数
}
```

### 线性同余方程

```c++
int exgcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int gcd = exgcd(b, a % b, y, x);
	y -= (a / b) * x;
	return gcd;
}
int main() {
	int t;
	t = 1;
//	cin>>t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int x = 1, y = 0;
		int gcd = exgcd(a, b, x, y);
		int t = b / gcd;
		cout << (x % t + t) % t;
	}
	return 0;
}
```

### 费马小定理求逆元

```c++
ll ksm(int a, int n) {
	ll ans = 1;
	while (n) {
		if (n & 1)ans = ans * a % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return ans;
}
int get_inv(int x, int  mod) {
	return ksm(x, mod - 2);
}
```

### 扩欧求逆元

```c++
void exgcd(int a, int b, int &x, int &y) { //扩展欧几里得算法
	if (b == 0) {
		x = 1;
		y = 0;
		return a;  //到达递归边界开始向上一层返回
	}
	int gcd = exgcd(b, a % b, y, x);
	y-=(a/b)*x;
}
int get_inv(int a,int p){
	int x=1,y=0;
	exgcd(a,p,x,y);
	return (x%p+p)%p;
}
```

### 线性求逆元

```c++
ll n, M, inv[3001000];
int main() {
	ll i, j;
	cin >> n >> M;
	inv[1] = 1;
	puts("1");
	for (i = 2; i <= n; i++) {
		inv[i] = M - M / i * inv[M % i] % M; //重要结论
		printf("%lld\n", inv[i]);
	}
}
```

### 埃筛

```c++
bool isprime[N];
int prime[N];
int top;
int judge(int n) {
	memset(isprime, true, sizeof(isprime));
	isprime[1] = isprime[0] = false;
	top = 0;
	for (int i = 2; i <= n; i++) {
		if (isprime[i]) {
			prime[++top] = i;
			for (int j = 2 * i; j <= n; j += i) {
				isprime[j] = false;
			}
		}
	}
	return top;
}
```

### 欧拉筛

```c++
int prime[maxn];//用来存储素数
int visit[maxn];//用来标记合数
int cnt;
void Prime(){
    for (int i = 2;i <= maxn; i++) {
        if (!visit[i]) {
            prime[++cnt] = i;
        }
        for (int j = 1; j <=cnt && i*prime[j] <= maxn; j++) {
            visit[i*prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}

```

### 区间筛

```c++
ll prime[N];
ll top;
bool is_primesmall[N];
bool is_prime[N];
ll judge(ll a, ll b) { //sqrt函数参数和返回值都为double型，精度不确定，尽量少用
	memset(is_primesmall, true, sizeof(is_primesmall));
	memset(is_prime, true, sizeof(is_prime));
	for (ll i = 2; i * i < b; i++) {
		if (is_primesmall[i]) { //用小区间 [ 2,sqrt(b) )去打表
			for (ll j = 2 * i; j * j < b; j += i)  is_primesmall[j] = false; //筛选[2,sqrt(b));
			for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i)  is_prime[j - a] = false; //大数a,b下标偏移。(a+i-1)/i表示>=a的最小的数。j至少得是2*i, 因为i是素数，如果j=1*i，is_prime[i]标记成i不是素数
		}
	}
	for (ll i = (a == 1); i < b - a; i++) { //区间坐标统一向左偏移了a。1不是素数，但是is_prime[0]=true，所以如果a=1,要排除这种情况
		if (is_prime[i])  prime[++top] = i + a;
	}
	return top;
}
```

## 图论

### 链式前向星存图

```c++
struct Edge{
    int to,w,next;
}e[maxn];
int cnt;
void add(int u,int v,int w){//添加一条边u--v 
    e[++cnt].to=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
} 
```

### 并查集

```c++
int f[N];
for(int i=1;i<+n;i++)f[i]=i;
int find(int x) {//利用路径压缩优化，将所有的子节点直接连接至根节点
	if (x != f[x]) f[x] = find(f[x]);
	return f[x];
}
void toget(int x, int y) {//合并两个集合，即将一个树的根节点插入另一棵树的根节点中
	x = find(x);
	y = find(y);
	f[x] = y;
}
```

### 最小生成树

#### prim算法

```c++
void prim() {
	//对标记重新初始化 
	memset(v, 0, sizeof(v));
	//初始化最小树的权值 
	for (int i = 1; i <= n; i++) d[i] = INF;
	d[1] = 0; //以1为根起点
	while (1) {
		int u = -1;
		int minn = INF;
		//遍历已选集合的所有出度中最小的边 
		for (int i = 1; i <= n; i++) {
			if (!v[i] && d[i] < minn) {
				minn = d[i];
				u = i;
			}
		}
		if (u == -1)break; //已找到所有结点
		v[u] = 1; //标记树的新节点
		//遍历更新新集合中相应权值的大小 
		for (int i = 1; i <= n; i++) {
			if (!v[i] && d[i] > s[u][i]) {
				d[i] = s[u][i];
			}
		}
	}
}
```

#### Kruskal算法（克鲁斯卡算法）

```c++
struct edge {
	int x, y;
	long long val;
} t[N];
bool cmp(const edge &x, const edge &y) {
	return x.val < y.val;
}
int find(int x ){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
void kruskal() {
	for (int i = 1; i <= m; i++) {
		int x=find(t[i].x);
		int y=find(t[i].y);
		if(x==y) continue;//判断如果是同一个根则已在树上，如果合并则会成环，故舍弃。
		sum+=t[i].val;
		fa[x]=y;
		ans++;
		if(ans==n-1)break;
	}
	cout<<sum<<endl;
}
```

### 最短路

#### floyd

```c++
void floyd() {
	for (int j = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] > a[i][k] + a[k][j]) { //已k为跳板遍历全部可能，判断是否可以缩短路径
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}
}
```

#### Dijkstra

```c++
int n,m,s,t;
int p[N][N],d[N],v[N],f[N];
int djtsl(){
	memset(v,0,sizeof(v));
	memset(d,INF,sizeof(d));
	d[s]=0;
	while(1){
		int u=-1,minn=INF;
		for(int i=1;i<=n;i++){
			if(!v[i] && d[i]<minn){
				minn=d[i];
				u=i;
			}
		}
		if(u==-1)break;
		v[u]=1;
		for(int i=1;i<=n;i++){
			if(!v[i] && d[i]>d[u]+p[u][i]){
				d[i]=d[u]+p[u][i];
				f[i]=u;//路径还原标记前驱 
			}
		}
	}
	return d[t];
}
```

#### Dijkstra+堆优化

```c++
void djstl() {
	for (int i = 1; i <= n; i++)d[i] = INF;
	d[s] = 0;
	priority_queue<PII, vector<PII>, greater<PII> > q; //将原来找最小边的操作，利用优先队列直接top
	q.push({0, s});//距离，结点
	while (q.size()) {
		PII p = q.top();
		q.pop();
		int u = p.Y;
		if (vis[u])continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			if (d[v] > d[u] + e[i].w) {
				d[v] = d[u] + e[i].w;
				q.push({d[v], v});
			}
		}
	}
}
```

##### 路径还原

```c++
// 初始化pre[i] = i;
void Print(int s, int v) { //s为起点，v为当前结点（从终点递归）
// 递归边界
	if (s == v) { //如果已经到达起点s，就输出起点并返回
		printf("%d ", s);
		return;
	}
// 递归边界
	Print(s, pre[v]); //递归访问v的前驱
	printf("%d ", v); //从最深处return回来后，输出每一层的顶点号
}
```

#### SPFA

```c++
#define INF 0x3f3f3f3f
int dis[MAX];//dis[i]表示起点到i的最短距离
bool vis[MAX];//是否访问过点i
int e[MAX][MAX];//矩阵
int n, m; //点和边的数量
int s;//源点
void SPFA() {
	for (int i = 1; i <= n; i++) { //初始化
		dis[i] = INF;
		vis[i] = false;
	}
	queue<int> q;
	q.push(s);
	dis[s] = 0;
	vis[s] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		vis[cur] = false;
		for (int i = 1; i <= n; i++) {
			if (e[cur][i] != INF && dis[i] >= dis[cur] + e[cur][i]) {
				dis[i] = dis[cur] + e[cur][i];
				if (!vis[i]) {
					vis[i] = true;
					q.push(i);
				}
			}
		}
	}
}
```

#### 拓扑排序

```c++
vector<int> p[N];
queue<int> q;
int in[N], out[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		while (cin >> x && x) {
			p[i].push_back(x);
			in[x]++;
			out[i]++;
		}
	}
	for (int i = 1; i <= n; i++)if (in[i] == 0)q.push(i);
	while (q.size()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < p[x].size(); i++) {
			in[p[x][i]]--;
			if (!in[p[x][i]]) {
				q.push(p[x][i]);
			}
		}
	}
	return 0;
}
```

