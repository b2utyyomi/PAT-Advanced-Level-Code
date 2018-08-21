/**********************
author: yomi
date: 18.8.2
ps: 使用algorithm下的count函数会超时 得用set下的count
**********************/
#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
set<int>s[60];
int main()
{
    int n, k, m, t;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &m);
        for(int j=0; j<m; j++){
            scanf("%d", &t);
            s[i].insert(t);
        }
    }
    scanf("%d", &k);
    int a, b;
    for(int i=0; i<k; i++){
        scanf("%d%d", &a, &b);
        int c = 0, d = 0;
        set<int>::iterator iter;
        for(iter=s[a-1].begin(); iter!=s[a-1].end(); ++iter){
            if(s[b-1].count(*iter)){
                c++;
            }
        }

        int nc = c;
        int nt = s[a-1].size()+s[b-1].size()-c;
        double ans = nc*1.0/nt*100;
        printf("%.1f%%\n", ans);
    }
    return 0;
}
/**
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
**/




