/**********************
author: yomi
date: 18.2.8
ps:系数为零的话是不用输出的
**********************/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct polynomial
{
    int n;
    float an;
}a[20],b[20], c[20];

int main()
{
    int m, n;
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> a[i].n >> a[i].an;
    }
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> b[i].n >> b[i].an;
    }
    int cnt = 0;
    int cnt1 =0, cnt2 = 0;
    while(cnt1<m && cnt2<n){
        if(a[cnt1].n>b[cnt2].n){
            if(a[cnt1].an != 0)
                c[cnt++] = a[cnt1];
            cnt1++;
        }
        else if(a[cnt1].n < b[cnt2].n){
            if(b[cnt2].an != 0)
                c[cnt++] = b[cnt2];
            cnt2++;
        }
        else{
            if(a[cnt1].an+b[cnt2].an){
                c[cnt].an = a[cnt1].an+b[cnt2].an;
                c[cnt++].n = a[cnt1].n;
            }
            cnt1++, cnt2++;

        }
    }
    while(cnt1<m){
        if(a[cnt1].an)
            c[cnt++] = a[cnt1++];
    }
    while(cnt2<n){
        if(b[cnt2].an)
            c[cnt++] = b[cnt2++];
    }

    cout << cnt;
    if(cnt)
        cout << " ";
    for(int i=0; i<cnt; i++){
        printf("%d %.1f", c[i].n, c[i].an);
        if(i!=cnt-1)
            printf(" ");
    }
    return 0;
}

/**
2 1 2.4 0 3.2
2 2 1.5 1 0.5
**/

