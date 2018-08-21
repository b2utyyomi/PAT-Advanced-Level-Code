/**********************
author: yomi
date: 18.5.12
ps:
**********************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int cnt[1000], a[100010];
int main()
{
    int m, n;
    int flag = 1;
    memset(cnt, 0, sizeof(cnt));
    scanf("%d%d", &m, &n);
    for(int i=0; i<m; i++){
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    sort(a, a+m);
    for(int i=0; i<m; i++){
        if(a[i]>n){
            break;
        }
        if(cnt[a[i]] > 0){
            cnt[a[i]]--;
            if(cnt[n-a[i]]>0){
                printf("%d %d", a[i], n-a[i]);
                flag = 0;
                break;
            }
        }
    }
    if(flag)
        printf("No Solution");
    return 0;
}
/**
8 15
1 2 8 7 2 4 11 15
4 11

8 4
2 1 5 7 1 4 11 15
No Solution

8 4
2 1 5 2 1 4 11 15
2 2

8 4
3 1 5 7 1 4 11 15
1 3


7 14
1 8 7 2 4 11 15
No Solution
**/
