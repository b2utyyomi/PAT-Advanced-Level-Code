/**********************
author: yomi
date: 18.6.15
ps: 内部错误 搞得我头大啊
应该是服务器有问题没错了
**********************/
#include <cstdio>

const int inf=0x7fffffff;
///--- O(logn) ---
const int maxn = 1000010;
int a[maxn], b[maxn];

int main()
{
    int n, m, cnt = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d", &b[i]);
    }
    a[n] = b[m] = inf;
    int midPos = (m+n-1)/2; /// 12345
    int i=0, j=0;
    while(cnt < midPos){
        if(a[i] < b[j]){
            i++;
        }
        else{
            j++;
        }
        cnt++;
    }
    if(a[i] < b[j])
        printf("%d\n", a[i]);
    else
        printf("%d\n", b[j]);
    return 0;
}

/**
4 11 12 13 14
5 9 10 15 16 17
13
**/

