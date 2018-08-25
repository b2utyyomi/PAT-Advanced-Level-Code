/**********************
author: yomi
date: 18.8.25
ps: 我的能力的确有了大幅提高 我明显感觉到了
然而 今天居然栽在一个小阴沟里 mindis #^#
一直找不到BUG也与surface抖屏有关系 这屏抖的 我的天哪
太邪乎了
还有两周就要考试了 这是搞什么嘛 不管了 送修了
旧电脑凑合用吧
**********************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int INF = 0x3fffffff;
const int maxn = 1110;
int d[maxn], g[maxn][maxn];
char a[50], b[50];
int n, m, k, ds;
int u, v, w;
bool vis[maxn];
int convert()
{
    char ch;
    u = 0, v = 0;
    if(a[0] == 'G'){
        a[0] = '0';
        sscanf(a, "%d", &u);
        //cout << a << ' ' << ch << endl;
        u+=n;
    }
    else{
        sscanf(a, "%d", &u);
    }
    if(b[0] == 'G'){
        b[0] = '0';
        sscanf(b, "%d", &v);
        v+=n;

    }
    else{
        sscanf(b, "%d", &v);
    }
}
void dijk(int s)
{
    fill(d, d+maxn, INF);
    fill(vis, vis+maxn, false);

    d[s] = 0;
    for(int i=1; i<=n+m; i++){
        int u=-1, Min = INF;
        for(int j=1; j<=n+m; j++){
            if(!vis[j] && d[j]<Min){
                Min = d[j];
                u = j;
            }
        }
        if(u == -1)
            return;
        vis[u] = true;
        for(int v=1; v<=n+m; v++){
            if(vis[v] || g[u][v] == INF)
                continue;
            if(d[u]+g[u][v] < d[v]){
                d[v] = d[u]+g[u][v];
            }
        }
    }
}
int main()
{
    fill(g[0], g[0]+maxn*maxn, INF);

    cin >> n >> m >> k >> ds;
    for(int i=0; i<k; i++){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        scanf("%s%s", a, b);
        cin >> w;
        convert();
        g[u][v] = g[v][u] = w;
    }
//    for(int i=0; i<maxn; i++){
//        for(int j=0; j<maxn; j++){
//            if(g[i][j]!=INF){
//                cout << i << ' ' << j << ' ' << g[i][j] <<endl;
//            }
//        }
//    }
    double mindis = INF, ans=0, realans=INF, realmindis = 0, maxdis=0;
    int id = -1;
    for(int i=1; i<=m; i++){/// house : 1~n  G: n+1~n+m
        dijk(n+i);
        ans = 0;
        mindis = INF;///死这了
        for(int j=1; j<=n; j++){
            if(d[j] < mindis){
                mindis = d[j]*1.0;
            }
            if(d[j] > ds){
                mindis = -1;
                break;
            }
            ans += d[j]*1.0;
        }
        if(mindis == -1)
            continue;
        ans = ans/n/1.0;
        //cout << mindis << endl;
        if(realmindis<mindis){
            id = i;
            realmindis = mindis;
            realans = ans;
        }
        else if(realmindis==mindis && realans>ans){
            id = i;
            realans = ans;
        }
    }
    if(id == -1){
        cout << "No Solution";
    }
    else{
        printf("G%d\n%.1f %.1f", id, realmindis, (int)(10.0 * realans + 0.5) / 10.0);
        ///3.25 ---> 3.3

    }
    return 0;
}
/**
Sample Input 1:
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
Sample Output 1:
G1
2.0 3.3
**/
