/**********************
author: yomi
date: 18.8.2
ps:
**********************/
#include <iostream>
#include <cstdio>
using namespace std;

struct Node
{
    int address;
    char data;
    int next;
}a[100010], b[100010], c[100010];
int main()
{
    int first1, first2, n, cnt1 = 0, cnt2 = 0, addr, next_;
    char d;
    scanf("%d%d%d", &first1, &first2, &n);
    for(int i=0; i<n; i++){
        scanf("%d", &addr);
        getchar();
        scanf("%c", &d);
        scanf("%d", &next_);
        //cin >> addr >> d >> next_;
        a[addr].address = addr;
        a[addr].data = d;
        a[addr].next = next_;
    }
    while(first1!=-1){
        b[cnt1++] = a[first1];
        first1 = a[first1].next;
    }
    while(first2!=-1){
        c[cnt2++] = a[first2];
        first2 = a[first2].next;
    }
    int j=cnt1-1, k = cnt2-1, flag = 0;
    while(j>=0 && k>=0){
        if(b[j].address != c[k].address){
            break;
        }
        j--;
        k--;
    }
    if(b[cnt1-1].address!=c[cnt2-1].address){
        printf("-1");
    }
    else{
        if(j!=-1)
            printf("%05d", b[j].next);
        else{
            printf("%05d", b[0].address);
        }
    }

    return 0;
}
/**
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
**/
