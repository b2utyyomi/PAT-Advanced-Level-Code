/**********************
author: yomi
date: 18.6.12
ps: two pointers ��Ȼ��ʱ��
����������4��TLE��WA
ans��ֵ��Ϊ0�����ǲ��Եģ����г�����Ϊ1��Ȼ����ȻWA
�ƺ��ҵĴ��Ѿ��޷���TLE�ı�Ե���Ȼ�����
��
�ҵĽ�һҳ���Ѿ����һҳ���ˡ�����
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




