/**********************
author: yomi
date: 18.8.19
ps:
**********************/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int a[maxn], pos[maxn], n, cnt, m=0, left;
bool isnot()
{
    for(; m<n; m++){
        if(m != a[m])
            return true;
    }
    return false;
}
int main()
{
    scanf("%d", &n);
    return 0;
}
/**
Sample Input:
10 3 5 7 2 6 4 9 0 8 1
Sample Output:
9
**/
