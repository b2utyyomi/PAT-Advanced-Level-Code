/**********************
author: yomi
date: 18.8.5
ps: 需要特判数据全部无效的情况 我就错这里了 愿九月份出链表的题
**********************/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Node
{
    int addr;
    int next;
    int data;
}node[100010], a[100010];
int cmp(Node a , Node b)
{
    return a.data < b.data;
}
int main()
{
    int n, first, address;
    scanf("%d%d", &n, &first);
    for(int i=0; i<n; i++){
        scanf("%d", &address);
        node[address].addr = address;
        scanf("%d%d", &node[address].data, &node[address].next);
    }
    int cnt = 0;
    while(first!=-1){
        a[cnt++] = node[first];
        first = node[first].next;
    }
    sort(a, a+cnt, cmp);
    if(cnt == 0){
        printf("0 -1");
    }
    else{
       printf("%d %05d\n",cnt, a[0].addr);
        for(int i=0; i<cnt-1; i++){
            printf("%05d %d %05d\n", a[i].addr, a[i].data, a[i+1].addr);
        }
        printf("%05d %d -1", a[cnt-1].addr, a[cnt-1].data);

    }
    return 0;
}
/**
Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 0 11111
12345 -1 33333
22222 1000 12345
Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
**/
