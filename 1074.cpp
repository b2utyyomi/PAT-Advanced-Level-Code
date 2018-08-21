/**********************
author: yomi
date: 18.8.1
ps: 榆木脑袋终于开窍 竟然一次ac 老泪纵横啊
**********************/
#include <iostream>
#include <cstdio>
using namespace std;
struct Node
{
    int addr;
    int data;
    int next;
}a[100010], b[100010], c[100010];
int main()
{
    int cnt = 0, cnt1=0;
    int first, n, k, add, d, next_;
    scanf("%d%d%d", &first, &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d%d%d", &add, &d, &next_);
        a[add].data = d;
        a[add].addr = add;
        a[add].next = next_;
    }
    while(first!=-1){
        c[cnt1++] = a[first];
        first = a[first].next;
    }
    for(int i=0; i<cnt1; i+=k){
        if(i+k-1>cnt1-1){
            for(int j=i; j<cnt1; j++){
                b[cnt++] = c[j];
            }
            break;
        }
        for(int j=i+k-1; j>=i; j--){
            b[cnt++] = c[j];
        }
    }
    for(int i=0; i<cnt-1; i++){
        printf("%05d %d %05d\n", b[i].addr, b[i].data, b[i+1].addr);
    }
    printf("%05d %d -1", b[cnt-1].addr, b[cnt-1].data);
    return 0;
}
/**
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
**/
