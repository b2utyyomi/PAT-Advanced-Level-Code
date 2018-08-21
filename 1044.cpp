/**********************
author: yomi
date: 18.6.10
ps: sum 递增
本题的巧妙之处就在于已知数列并不递增，让人想不到二分
但是题目的条件Di+...+Dj>M 却给了暗示，仔细思考， 不难发现，序列和是递增的
那就可以用二分了。
1 2 3  4  5  6  7   8   9
3 2 1  5  4  6  8   7   16  10 15 11 9 12 14 13
3 5 6 11 15  21 29  36  52
像这样。
那么i~j                                    j      i-1
下标4~6的序列和就是5+4+6 == 15， 也就是sum[6]-sum[3]
不难想象，进行二分的序列肯定是sum[]
通过上面的分析，可以知道m == sum[j]-sum[i-1]
所以 sum[j] == m+sum[i-1], 我们需要让bs()返回的就是j
所以需要查找的数就是m+sum[i-1].
接下来找到>=m的最小数nearm
然后在遍历一次，找到所有满足==nearm的i~j的sum
**********************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long int sum[100010];


int bs(long long int l, long long int r, long long int s)
{
    int mid;
    while(l < r){
        mid = (l+r)/2;
        if(sum[mid] >= s){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    return l;
}
int main()
{
    long long int n, m, nearm = 0, diff = 100000010;
    memset(sum, 0, sizeof(sum));
    scanf("%lld%lld", &n, &m);
    for(long long int i=1; i<=n; i++){
        scanf("%lld", &sum[i]);
        sum[i] += sum[i-1]; // sum[] 求和
    }
    for(long long int i=1; i<=n; i++){
        long long int j = bs(i, n+1, m+sum[i-1]);///二分下界是i而不是i+1，因为可能有一个数恰好为m
        long long int tmp = sum[j]-sum[i-1];
        if(tmp - m < diff && tmp >= m){
            diff = tmp-m;
            nearm = tmp;
        }
    }
    for(long long int i=1; i<=n; i++){
        long long int j = bs(i, n+1, sum[i-1]+nearm);
        if(sum[j]-sum[i-1] == nearm){
            printf("%lld-%lld\n", i, j);
        }
    }
    return 0;
}

/**
16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13

1-5
4-6
7-8
11-11
**/
