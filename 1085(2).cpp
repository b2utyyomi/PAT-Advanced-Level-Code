/**********************
author: yomi
date: 18.6.12
ps: two pointers 依然超时嘞
挣扎于样例4的TLE与WA
ans初值设为0，这是不对的，序列长至少为1，然而仍然WA
似乎我的答案已经无法从TLE的边缘拯救回来了
额
我的近一页红已经编程一页绿了。。。
**********************/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long int a[100010];
int main()
{
    int n, p, ans = 0;///
    scanf("%d%d", &n, &p);
    for(int i=0; i<n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a, a+n);
    int i = 0, j = 0;
    while(i<n){
        while(j<n && a[j]<=a[i]*p){
            ans  = max(ans, j-i+1);
            j++;
        }
        i++;
    }
    printf("%d", ans);
    return 0;
}
/**
10 8
2 3 20 4 5 1 6 7 8 9
**/




