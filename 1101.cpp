/**********************
author: yomi
date: 18.6.19
ps: 并不是相对位置没变就一定是主元，写错算法的我感到一丝丝悲伤
比如：
5
5 2 3 4 1
0 1 2 3 4

1 2 3 4 5
4 1 2 3 0
修改之后：
思路仿A1093, 这样把之前扫描的结果存起来真的很实用
竟然 测试点2格式错误
还是书上写的格式处理比较好理解吧 但是我写的也过了
书上的代码才是真的仿1093，我这个创新了
以下AC
**********************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100010;
int b[maxn], c[maxn];
bool flag[maxn];
int main()
{
    int n, cnt = 0, Min=0x7fffffff, Max = -2;
    memset(flag, true, sizeof(flag));
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%lld", &b[i]);
        if(Max > b[i]){
            flag[i] = false;
        }
        Max = max(b[i], Max);
    }
    for(int i=n-1; i>=0; i--){
        if(Min < b[i]){
            flag[i] = false;
        }
        Min = min(b[i], Min);
    }
    for(int i=0; i<n; i++){
        if(flag[i]){
            c[cnt++] = b[i];
        }
    }
    printf("%d\n", cnt);///调了又调
    if(cnt){
        for(int i=0; i<cnt-1; i++){
            printf("%d ", c[i]);
        }
        printf("%d", c[cnt-1]);
    }
    else{
        printf("\n");
    }
    return 0;
}

/**
5
1 3 2 4 5
**/
