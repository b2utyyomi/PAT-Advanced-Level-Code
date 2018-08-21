/**********************
author: yomi
date: 18.5.19
ps: the first line contains 2 positive integers N (<=1000),
the number of different kinds of mooncakes, and D (<=500 thousand tons)
是正数，没说是正整数啊 按照样例想当然的把质量当成了整数 WA了
**********************/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct mooncake
{
    double quantity;///int 测试点2 WA
    double total;
    double per;
}cake[1010];
int cmp(mooncake a, mooncake b)
{
    return a.per > b.per;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> cake[i].quantity;
    }
    for(int i=0; i<n; i++){
        cin >> cake[i].total;
        cake[i].per = cake[i].total/cake[i].quantity;
    }
    sort(cake, cake+n, cmp);
    double ans = 0;
    for(int i=0; i<n; i++){
        if(m >= cake[i].quantity){
            ans += cake[i].total;
            m -= cake[i].quantity;
        }
        else{
            ans += cake[i].per*m;
            break;
        }
    }
    printf("%.2f", ans);
    return 0;
}

/**
3 200
180 150 100
7.5 7.2 4.5
**/
