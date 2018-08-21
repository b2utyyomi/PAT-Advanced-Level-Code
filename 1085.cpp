/**********************
author: yomi
date: 18.5.28
ps: 注意每个数不超过10^9 10^9*10^9 = 10^18 得用长整型
本题可使用二分查找以及two pointers
**********************/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long int a[100010];
int main()
{
    int n, ans = 0, res = 1;
    long long int p;
    scanf("%lld%lld", &n, &p);
    for(int i=0; i<n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a, a+n);
    for(int i=0; i<n; i++){
        int j = upper_bound(a+i+1, a+n, a[i]*p)-a;
        res = max(res, j-i);
    }
//    int mid = n/2; 暴力超时
//    for(int i=0; i<mid+1; i++){
//        for(int j=n-1; j>=mid; j--){
//            if(a[j] <= a[i]*p){
//                ans = j-i+1;
//                res = max(res, ans);
//                break;
//            }
//
//        }
//    }
    printf("%d", res);
    return 0;
}

/**
10 8
2 3 20 4 5 1 6 7 8 9
**/
