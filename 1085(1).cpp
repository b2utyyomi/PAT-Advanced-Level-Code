/**********************
author: yomi
date: 18.6.8
ps: 套模板万事大吉
**********************/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 100010;
int bs(long long int *a, int left, int right, long long int x)
{
    int mid;
    while(left<right){
        mid = (left+right)/2;
        if(a[mid] > x){
            right = mid;
        }
        else{
            left = mid+1;
        }
    }
    return left;
}
int main()
{
    long long int n, p, a[maxn];
    scanf("%lld%lld", &n, &p);
    for(int i=0; i<n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a, a+n);
    int ans = 0;
    for(int i=0; i<n; i++){
       //int j = upper_bound(a+i+1, a+n, a[i]*p)-a;
       int j = bs(a, i+1, n, a[i]*p);
       ans = max(ans, j-i);
    }
    printf("%d", ans);
    return 0;
}
/**
10 8
2 3 20 4 5 1 6 7 8 9
**/
