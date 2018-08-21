/**********************
author: yomi
date: 18.6.10
ps: sum ����
���������֮����������֪���в��������������벻������
������Ŀ������Di+...+Dj>M ȴ���˰�ʾ����ϸ˼���� ���ѷ��֣����к��ǵ�����
�ǾͿ����ö����ˡ�
1 2 3  4  5  6  7   8   9
3 2 1  5  4  6  8   7   16  10 15 11 9 12 14 13
3 5 6 11 15  21 29  36  52
��������
��ôi~j                                    j      i-1
�±�4~6�����к;���5+4+6 == 15�� Ҳ����sum[6]-sum[3]
�������󣬽��ж��ֵ����п϶���sum[]
ͨ������ķ���������֪��m == sum[j]-sum[i-1]
���� sum[j] == m+sum[i-1], ������Ҫ��bs()���صľ���j
������Ҫ���ҵ�������m+sum[i-1].
�������ҵ�>=m����С��nearm
Ȼ���ڱ���һ�Σ��ҵ���������==nearm��i~j��sum
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
        sum[i] += sum[i-1]; // sum[] ���
    }
    for(long long int i=1; i<=n; i++){
        long long int j = bs(i, n+1, m+sum[i-1]);///�����½���i������i+1����Ϊ������һ����ǡ��Ϊm
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
