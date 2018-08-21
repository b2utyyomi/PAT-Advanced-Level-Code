/**********************
author: yomi
date: 18.2.26
ps:测试点0  WA    我猜与0有关系
猜对了呢 系数为0时不用输出 所以项数要相应的减少 因为没考虑到又WA了一次
**********************/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

struct data
{
    int exp;
    double coef;
}d1[1010], d2[1010];

int main()
{
    int n, m;
    map<int,double, greater<int> >mmap;
    bool vis[1010];
    memset(vis, false, sizeof(vis));
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> d1[i].exp >> d1[i].coef;
    }
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> d2[i].exp >> d2[i].coef;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int e = d1[i].exp+d2[j].exp;
            double c = d1[i].coef*d2[j].coef;
            if(!vis[e]){
                mmap[e] = c;
                vis[e] = true;
            }
            else{
                mmap[e] += c;
            }

        }
    }
    int cnt = mmap.size();
    for(map<int, double>::iterator iter=mmap.begin(); iter!=mmap.end(); ++iter){
        if(iter->second == 0)
            cnt--;
    }
    cout << cnt;
    for(map<int, double>::iterator iter=mmap.begin(); iter!=mmap.end(); ++iter){
        if(iter->second == 0)
            continue;
        cout << ' ';
        printf("%d %.1f", iter->first, iter->second);
    }
    return 0;
}

/**
2 1 2.4 0 3.2
2 2 1.5 1 0.5

2 1 2 0 0
2 2 1.5 1 0.5

**/









