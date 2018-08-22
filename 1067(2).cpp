/**********************
author: yomi
date: 18.8.22
ps: 0只能和不在本位的交换 所以这里有一个优化 如果不写这个优化就会超时
**********************/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int pos[maxn], cnt;
int main()
{
    int n, d;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
       scanf("%d", &d);
       pos[d] = i;
    }
    int i = 0;
    while(1){
        if(pos[0] == 0){
            for(; i<n; i++){
                if(pos[i]!=i)
                    break;
            }
            if(i == n)
                break;
            swap(pos[0], pos[i]);
            cnt++;
        }
        else{
            swap(pos[0], pos[pos[0]]);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
/**
10
3 5 7 2 6 4 9 0 8 1

9
**/


