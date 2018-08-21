/**********************
author: yomi
date: 18.8.6
ps:
**********************/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
struct Node
{
    int addr;
    int data;
    int next;
}node[100010],a[100010], b[100010];

bool vis[10010];
int main()
{
    memset(vis, false, sizeof(vis));
    int first, n, address, cnt1 = 0, cnt2 = 0;
    scanf("%d%d", &first, &n);
    for(int i=0; i<n; i++){
        scanf("%d", &address);
        node[address].addr = address;
        scanf("%d%d",&node[address].data, &node[address].next);
    }
    while(first!=-1){
        int v = abs(node[first].data);
        if(!vis[v]){
            vis[v] = true;
            a[cnt1++] = node[first];
        }
        else{
            b[cnt2++] = node[first];
        }
        first = node[first].next;
    }
    if(cnt1){
        for(int i=0; i<cnt1-1; i++){
            printf("%05d %d %05d\n", a[i].addr, a[i].data, a[i+1].addr);
        }
        printf("%05d %d -1", a[cnt1-1].addr, a[cnt1-1].data);
    }
    if(cnt2){
        printf("\n");
        for(int i=0; i<cnt2-1; i++){
            printf("%05d %d %05d\n", b[i].addr, b[i].data, b[i+1].addr);
        }
        printf("%05d %d -1", b[cnt2-1].addr, b[cnt2-1].data);

    }

    return 0;
}
/**
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
**/
