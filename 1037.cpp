/**********************
author: yomi
date: 18.5.25
ps:
**********************/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int cmp(int a, int b)
{
    return a>b;
}
int main()
{
    long long int n, m, a[maxn], b[maxn];
    long long int ans = 0;
    scanf("%lld", &n);
    for(int i=0; i<n; i++){
        scanf("%lld", &a[i]);
    }
    scanf("%lld", &m);
    for(int i=0; i<m; i++){
        scanf("%lld", &b[i]);
    }
    sort(a, a+n, cmp);
    sort(b, b+m, cmp);
    int len = min(m, n);
    int len1 = max(m, n);
    int pos = 0;
    int flag = 0;
    for(int i=0; i<len; i++){
        if(a[i] > 0 && b[i] > 0){
            ans += a[i]*b[i];
            pos = i;
        }
        else{
            flag = 1;
            break;
        }
    }
    if(flag){
        sort(a, a+n);
        sort(b, b+m);
        for(int i=0; i<len; i++){
            if(a[i] < 0 && b[i] < 0){
                ans += a[i]*b[i];
                pos = i;
            }
            else{
                break;
            }
        }


    }
    printf("%lld\n", ans);
    return 0;
}

/**
4
1 2 4 -1
4
7 6 -2 -3

**/
