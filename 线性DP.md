# 线性DP

> **线性[动态规划](https://so.csdn.net/so/search?q=动态规划&spm=1001.2101.3001.7020)，是较常见的一类动态规划问题，其是在线性结构上进行状态转移，这类问题不像背包问题、区间DP等有固定的模板。**
>
> **线性动态规划的目标函数为特定变量的线性函数，[约束](https://so.csdn.net/so/search?q=约束&spm=1001.2101.3001.7020)是这些变量的线性不等式或等式，目的是求目标函数的最大值或最小值。**
>
> **因此，除了少量问题（如：LIS、LCS、LCIS等）有固定的模板外，大部分都要根据实际问题来推导得出答案。**

## 序列问题：

#### 基本概念

- 子序列： 一个序列 A＝a1,a2,……an 中任意删除若干项，剩余的序列叫做 A 的一个子序列。也可以认为是从序列 A 按原顺序保留任意若干项得到的序列。（例如：对序列｛1,3,5,4,2,6,8,7｝来说，序列｛3,4,8,7｝是它的一个子序列。）
- 公共子序列 ：如果序列 C 既是序列 A 的子序列，也是序列 B 的子序列，则称它为序列 A 和序列 B 的公共子序列。（例如：对序列｛1,3,5,4,2,6,8,7｝和序列｛1,4,8,6,7,5｝来说，序列｛1,8,7｝是它们的一个公共子序列）
- 最长公共子序列：A 和 B 的公共子序列中长度最长的（包含元素最多的）序列叫做 A 和 B 的公共子序列。（ 最长公共子序列不唯一）
- 对于一个长度为 n 的序列，它一共有 2^n 个子序列，有 (2^n – 1) 个非空子序列。
- 子序列不是子集，它和原始序列的元素顺序是相关的。
- 空序列是任何两个序列的公共子序列。
- 角标为 0 时，认为子序列是空序列。

#### 【LIS问题】

LIS 问题（Longest Increasing Subsequence），最长上升子序列，其一般为求最长下降子序列或是最长上升子序列。
用 DP[i] 表示 A[i] 为结尾的最长上升子序列的长度，则有状态转移方程：

#### 模板：

```c++
for(int i=2;i<=n+1;i++)
{
    int num=0;
    for(int j=i-1;j>=1;j--)
        if(a[i]>a[j])
            num=max(num,dp[j]);
    dp[i]=num+1;
}

```

#### 【LCS 问题】

LCS 问题（Longest Common Subsequence），求序列的最长公共子序列。

F[i][j] 表示前缀子串 A[1~i] 与 B[1~j] 的最长公共子序列的长度，则有状态转移方程： 

![F[i][j]=max(F[i-1][j],F[i][j-1],F[i-1][j-1]+1(if\:A[i]=B[j]))](https://private.codecogs.com/gif.latex?F%5Bi%5D%5Bj%5D%3Dmax%28F%5Bi-1%5D%5Bj%5D%2CF%5Bi%5D%5Bj-1%5D%2CF%5Bi-1%5D%5Bj-1%5D&plus;1%28if%5C%3AA%5Bi%5D%3DB%5Bj%5D%29%29)

即：

![C[i,j]=\left\{\begin{matrix}0, &i=0|j=0 \\ C[i-1,j-1]+1,&i,j>0,x_i=y_j \\ max\{C[i,j-1],C[i-1,j]\},&i,j>0,x_i \neq y_j \end{matrix}\right.](https://private.codecogs.com/gif.latex?C%5Bi%2Cj%5D%3D%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D0%2C%20%26i%3D0%7Cj%3D0%20%5C%5C%20C%5Bi-1%2Cj-1%5D&plus;1%2C%26i%2Cj%3E0%2Cx_i%3Dy_j%20%5C%5C%20max%5C%7BC%5Bi%2Cj-1%5D%2CC%5Bi-1%2Cj%5D%5C%7D%2C%26i%2Cj%3E0%2Cx_i%20%5Cneq%20y_j%20%5Cend%7Bmatrix%7D%5Cright.)

#### 模板：

```c++
char s[MAX],t[MAX];  
scanf("%s%s",s,t);  
int x=strlen(s),y=strlen(t);  
for(i=0;i<x;i++)  
{  
    for(j=0;j<y;j++)  
    {
        if(s[i]==t[j])  
            dp[i][j]=dp[i-1][j-1]+1;  
        else  
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);  
    }  
    printf("%d\n",dp[i][j]);              
}
```

#### 【LCIS 问题】

LCIS 问题（Longest Common Increasing Subsequence），求序列的最长公共上升子序列。

用 F[i][j] 表示 A[1~j] 与 B[1~j] 可以构成的以 B[j] 为结尾的 LCIS 的长度，易得状态转移方程：

![\left\{\begin{matrix} dp[i][j] = dp[i-1][j],&a[i] \neq b[j] \\ dp[i][j] = max(dp[i-1][k]+1) ,&1 \leq k \leq j-1,a[i] =b[j], b[j] > b[k] \end{matrix}\right.](https://private.codecogs.com/gif.latex?%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D%20dp%5Bi%5D%5Bj%5D%20%3D%20dp%5Bi-1%5D%5Bj%5D%2C%26a%5Bi%5D%20%5Cneq%20b%5Bj%5D%20%5C%5C%20dp%5Bi%5D%5Bj%5D%20%3D%20max%28dp%5Bi-1%5D%5Bk%5D&plus;1%29%20%2C%261%20%5Cleq%20k%20%5Cleq%20j-1%2Ca%5Bi%5D%20%3Db%5Bj%5D%2C%20b%5Bj%5D%20%3E%20b%5Bk%5D%20%5Cend%7Bmatrix%7D%5Cright.)

因此对于决策集合中的元素只增多不减少的情景，就可以维护一个变量来记录决策集合的当前消息，只需要两重循环即可求解。

#### 模板：

```c++
for (int i=1;i<=n;++i)
{
    int val=0;//val是决策集合S(i,j)中f[i-1][k]的最大值 
    for(int j=1;j<=m;++j)
    {
        //原来的k循环+判断+状态转移 
        if (a[i]==b[j]) 
            f[i][j]=val+1;
        else 
            f[i][j]=f[i-1][j];
        if (b[j]<a[i]) 
            val=max(val,f[i-1][j]);
        //j即将增大为j+1,检查j能否进入新的决策集合 
    }

}
```

## 字符串编辑距离问题：

#### 【概述】

> [字符串](https://so.csdn.net/so/search?q=字符串&spm=1001.2101.3001.7020)编辑距离，即 Levenshtein 距离，是俄国科学家 Vladimir Levenshtein 提出的概念，是指从一个字符串修改到另一个字符串时，编辑单个字符所需的最少次数，编辑单个字符允许的操作有：替换、插入、删除。
>
> Levenshtein 距离一般用来衡量两个字符串的相似度，一般来说，两个字符串的编辑距离越小，相似度越大。
>
> 举例来说，从 "set" 改到 "sitting" 需要 5 次单字符编辑操作：
>
> - e 修改为 i：sit
> - 添加 t：sitt
> - 添加 i：sitti
> - 添加 n：sittin
> - 添加 g：sitting
>
> 因此，set 与 sitting 的编辑距离为：3

#### 【**Levenshtein 算法**】

Levenshtein 算法又称编辑距离（Edit Distance）算法，用于求两个长度分别为 n、m的字符串 a、b 的 Levenshtein 距离，其是一个线性[动态规划](https://so.csdn.net/so/search?q=动态规划&spm=1001.2101.3001.7020)的算法，时空复杂度均为 O(nm)。

#### 1. 状态转移方程

对于两个字符串 a、b，其长度为 |a|、|b|，他们间的编辑距离定义为：

![lev_{a,b}(|a|,|b|)=\left\{\begin{matrix}max(i,j) & min(i,j)=0 \\ min\left\{\begin{matrix} lev_{a,b}(i-1,j)+1 \\ lev_{a,b}(i,j-1)+1 \\ lev_{a,b}(i-1,j-1)+(a_i \neq b_j?1:0) \end{matrix}\right. & otherwise \end{matrix}\right.](https://private.codecogs.com/gif.latex?lev_%7Ba%2Cb%7D%28%7Ca%7C%2C%7Cb%7C%29%3D%5Cleft%5C%7B%5Cbegin%7Bmatrix%7Dmax%28i%2Cj%29%20%26%20min%28i%2Cj%29%3D0%20%5C%5C%20min%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D%20lev_%7Ba%2Cb%7D%28i-1%2Cj%29&plus;1%20%5C%5C%20lev_%7Ba%2Cb%7D%28i%2Cj-1%29&plus;1%20%5C%5C%20lev_%7Ba%2Cb%7D%28i-1%2Cj-1%29&plus;%28a_i%20%5Cneq%20b_j%3F1%3A0%29%20%5Cend%7Bmatrix%7D%5Cright.%20%26%20otherwise%20%5Cend%7Bmatrix%7D%5Cright.)

其中，![lev_{a,b}(i,j)](https://private.codecogs.com/gif.latex?lev_%7Ba%2Cb%7D%28i%2Cj%29) 是指字符串 a 的前 i 个字符和字符串 b 的前 j 个字符的编辑距离。

在有了编辑距离后，字符串 a、b 的相似度定义为：![sim_{a,b}=1-\frac{lev_{a,b}(|a|,|b|)}{max(|a|,|b|)}](https://private.codecogs.com/gif.latex?sim_%7Ba%2Cb%7D%3D1-%5Cfrac%7Blev_%7Ba%2Cb%7D%28%7Ca%7C%2C%7Cb%7C%29%7D%7Bmax%28%7Ca%7C%2C%7Cb%7C%29%7D)

#### 2.算法原理

对于 a、b 两个字符串来说，我们先考虑极端的情况，即 a 或 b 的长度为 0 时，那么要编辑的次数就是另一个字符串的长度。

之后，我们考虑一般情况，在 k 个操作中有：

- 删除操作：将 a[1],a[2],...,a[i-1] 转换为 b[1],b[2],...,b[j]
- 插入操作：将 a[1],a[2],...,a[i] 转换为 b[1],b[2],...,b[j-1]
- 替换操作：将 a[1],a[2],...,a[i-1] 转换为 b[1],b[2],...,b[j-1]

对于删除操作，只需将 a[i] 从 a 中移除，即可完成转换，此时编辑次数为 k+1

对于插入操作，只需在 a[i] 后加上 b[j]，即可完成转换，此时编辑次数为 k+1

对于替换操作，只需将 a[i] 转换为 b[j]，即可完成转换，需要注意的是，如果 a[i] 与 b[j] 相同，那么此时编辑次数为 k，如果 a[i] 与 b[j] 不同，那么此时编辑次数为 k+1

而为了保证将 a[1],a[2],...,a[i] 转换为 b[1],b[2],...,b[j] 的操作次数是最少的，因此要在三种情况中取最小值，故而只需要按此逻辑进行迭代，保证每一步操作都是最小即可。

#### 3.实例

我们以字符串 a：abroad 与字符串 b：aboard 为例，并在计算过程中将每一步的操作数放入 i+1 行 j+1 列的二维数组 dp 中，此时 dp[i][j] 即为将 a[1],a[2],...,a[i] 转换为 b[1],b[2],...,b[j] 所需的最小操作数。

首先考虑极端情况，即 a 为空字符串或 b 为空字符串时，需要的操作此时为另一字符串的长度，即：dp[i][0]=i，dp[0][j]=j

之后我们考虑一般情况，从头到尾遍历这个二维数组，从第一行到最后一行，根据定义来计算 dp[i][j] 的值，即 dp[i][j] 的值由 dp[i][j] 的上方元素 dp[i-1][j]、左方元素 dp[i][j-1]、左上方元素 dp[i-1][j-1] 的值来计算得出

最后 dp[aLen][bLen] 即为字符串 a 转换到 b 的 Levenshtein 距离。

如下图，最终 "abroad" 与 "aboard" 的 Levenshtein 距离 ![lev_{a,b}(6,6)=2](https://private.codecogs.com/gif.latex?lev_%7Ba%2Cb%7D%286%2C6%29%3D2)，相似度 ![sim_{a,b}=1-\frac{lev_{a,b}(6,6)}{max(6,6)}=1-\frac{2}{6}=\frac{2}{3}](https://private.codecogs.com/gif.latex?sim_%7Ba%2Cb%7D%3D1-%5Cfrac%7Blev_%7Ba%2Cb%7D%286%2C6%29%7D%7Bmax%286%2C6%29%7D%3D1-%5Cfrac%7B2%7D%7B6%7D%3D%5Cfrac%7B2%7D%7B3%7D)

![img](https://img-blog.csdnimg.cn/20200302103639614.gif)

#### 4.实现

```cpp
char a[N], b[N];
int dp[N][N];
int main() {
    scanf("%s%s", a, b);
    int aLen = strlen(a);
    int bLen = strlen(b);
    //极端情况
    for (int i = 1; i <= aLen; i++) //以i+1来考虑第i个字符的情况
        dp[i][0] = i;
    for (int j = 1; j <= bLen; j++) //以j+1来考虑第j个字符的情况
        dp[j][0] = j;
 
    for (int i = 1; i <= aLen; i++) { //以i+1来考虑第i个字符的情况
        for (int j = 1; j <= bLen; j++) { //以j+1来考虑第j个字符的情况
            if (a[i - 1] == b[j - 1]) //相同时距离不变
                dp[i][j] = dp[i - 1][j - 1];
            else //不同时取三个位置的最小值再+1
                dp[i][j] = min(dp[i - 1][j - 1],min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }
    printf("%d\n", dp[aLen][bLen]);
    return 0;
}
```

## 【最大子序列和】

问题定义：对于给定序列 a1,a2,a3……an 寻找它的**连续的最大和子数组**。

用数组 dp[i] 来保存当前最大的连续子数组，循环遍历每个数，然后每次检验 dp[i-1] 是否大于零，只要大于零就令 dp[i] = dp[i-1]+a[i] ,如果 dp[i-1]<0 ，那么直接令 dp[i]=a[i]

#### 模板：

```cpp
for(int i=2;i<=n;i++)
{
    if(dp[i-1]>=0)
        dp[i]=dp[i-1]+a[i];
    else
        dp[i]=a[i];
}
```

#### 【最大子矩阵和】

问题定义：给定一个 n 行 m 列的整数矩阵 A，现在要求 A 的一个子矩阵，使其各元素之和为最大。

最后子矩阵一定是在某两行之间的，假设子矩阵在第 i 行和第 j 行之间，那么我们可以枚举所有1<=i<=j<=m,表示最终子矩阵选取的行范围。

将每一列第 i 行到第 j 行之间的和求出来，形成一个数组 c，于是一个第 i 行到第 j 行之间的最大子矩阵和对应于这个和数组 c 的最大子段和。

模板：

```cpp
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        int temp;
        scanf("%d",&temp);
        a[i][j]=a[i-1][j]+t;
    }
}
int ans=-INF;
for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){
        int sum=0;
        for(int k=1;k<=m;k++){
            sum=sum+(a[j][k]-a[i-1][k]);
            if(sum<0) 
                sum=0;
            if(sum>ans) 
                ans=sum;
        }
    }
}
```

#### 【数字三角形】

数字三角形问题一般为：给出一个如下形式的数字三角形，现在要从左上角走到第 i 行第 j 列，每一步只能走到相邻的结点，求经过的结点的最大数字和

例如：

   **7
  3 8
 8 1 0 
 2 7 4 4
4 5 2 6 5**

用 F[i][j] 表示第 i 行第 j 列的最大和，则有状态转移方程：F[i][j]=a[i][j]+max(F[i−1][j],F[i−1][j−1])

#### 模板：

```cpp
for (int i=n-1;i>=1;--i)
    for (int j=1;j<=i;++j)
        a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
printf("%d\n",a[1][1]);
```

