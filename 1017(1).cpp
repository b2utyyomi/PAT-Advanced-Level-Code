/**********************
author: yomi
date: 18.8.25
ps: 啊 重新好好捋了思路 一气呵成 一次就过 爽
**********************/
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
struct people
{
    int comeTime;
    int serveTime;
}peo[10010];
vector<people>p;
int convertTime(int h, int m, int s)
{
    return h*3600+m*60+s;
}
int cmp(people a, people b)
{
    return a.comeTime < b.comeTime;
}
int main()
{
    int n, k, h, m, s, total=0, window[110], st, endTime=convertTime(17, 0, 0);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        scanf("%d:%d:%d", &h, &m, &s);
        peo[i].comeTime = convertTime(h, m, s);
        scanf("%d", &st);
        if(st > 60){
            st = 60;
        }
        peo[i].serveTime = convertTime(0, st, 0);
    }
    sort(peo, peo+n, cmp);
    for(int i=0; i<n; i++){
        if(peo[i].comeTime <= endTime){
            p.push_back(peo[i]);
        }
    }
    for(int i=0; i<k; i++){
        window[i] = convertTime(8, 0, 0);
    }
    for(int i=0; i<p.size(); i++){
        people now = p[i];
        sort(window, window+k);
        if(now.comeTime < window[0]){
            total += window[0]-now.comeTime;
            window[0] += now.serveTime;
        }
        else{
            window[0] = now.comeTime+now.serveTime;
        }
    }
    printf("%.1f", total*1.0/60/p.size());
    return 0;
}
/**
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
Sample Output:
8.2
**/
