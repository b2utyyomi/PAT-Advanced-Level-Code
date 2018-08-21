/**********************
author: yomi
date: 18.6.12
ps: ������һ�δ������������ Ȼ�� �д�֪��������ѽ
bug ��һ��Ҫ�ҵ���~
��Ӵ �㷨���� ԭ����m��n������˳��Ū���� ����
**********************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long int sum[100010];
long long int bs(long long int l,long long int r, long long int x)
{
    long long int mid;
    while(l < r){
        mid = (l+r)/2;
        if(sum[mid] >= x){
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
    long long int m, n;
    memset(sum, 0, sizeof(sum));
    //cin >> m >> n;
    scanf("%lld%lld", &n, &m);
    for(long long int i=1; i<=n; i++){
        //cin >> sum[i];
        scanf("%lld", &sum[i]);
        sum[i] += sum[i-1];
    }
    long long int nearm = 100000010;
    for(long long int i=1; i<=n; i++){
        long long int j = bs(i, n+1, m+sum[i-1]);
        /// sum[j]
        if(sum[j]-sum[i-1] >= m)
            nearm = min(nearm, sum[j]-sum[i-1]);
    }
    //cout <<nearm << endl;
    for(long long int i=1; i<=n; i++){
        long long int j = bs(i, n+1, nearm+sum[i-1]);///all >=
        if(sum[j]-sum[i-1] == nearm){
            //cout << sum[i-1] << ' ' << sum[j] << endl;
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
