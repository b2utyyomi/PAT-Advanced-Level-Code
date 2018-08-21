/**********************
author: yomi
date: 18.6.13
ps:完全套开篇的模板啦
测试点1----> WA
**********************/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int i=0, j=n-1, flag = 0;
    while(i<n && j>=0){
        if(j<=i)
            break;
        if(a[i]+a[j] == m){
            if(a[i] <= a[j])
                printf("%d %d", a[i], a[j]);
            else
                printf("%d %d", a[j], a[i]);
            flag = 1;
            //i++,j--;
            break;
        }///为什么这样呢？归根到底还是因为这是一个递增的序列。
        else if(a[i]+a[j] < m){ ///此时a[i]+a[j]比m小，应该让它增加
            i++;
        }
        else{///此时a[i]+a[j]比m大，应该让它减少
            j--;
        }
    }
    if(!flag)
        printf("No Solution");
    return 0;
}
/**
4 4
1 2 4 8
2 2
**/
/**
1 2 8 7 2 4 11 15
1 2 2 4 7 8 11 15
**/
/**
8 15
1 2 8 7 2 4 11 15

4 11
**/







