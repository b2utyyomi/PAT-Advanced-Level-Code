/**********************
author: yomi
date: 18.8.23
ps: 整个一模板题 17分钟搞定
**********************/
#include <iostream>

using namespace std;
const int INF = 0x3fffffff;
int g[550][550], d[501], c[501], cost[550][550], pre[501];
bool vis[501];
int n, m, s, dd, u, v, w, cc;
void dijk()
{
    d[s] = 0;
    c[s] = 0;
    for(int i=0; i<n; i++){
        int u=-1, Min=INF;
        for(int j=0; j<n; j++){
            if(!vis[j] && d[j]<Min){
                Min = d[j];
                u = j;
            }
        }
        if(u == -1)
            return;
        vis[u] = true;
        for(int v=0; v<n; v++){
            if(vis[v] || g[u][v]==INF)
                continue;
            if(d[u]+g[u][v] < d[v]){
                d[v] = d[u]+g[u][v];
                c[v] = c[u]+cost[u][v];
                pre[v] = u;
            }
            else if(d[u]+g[u][v] == d[v] && c[u]+cost[u][v]<c[v]){
                c[v] = c[u]+cost[u][v];
                pre[v] = u;
            }
        }
    }
}
void dfs(int v)
{
    if(v == s)
    {
        cout << s << ' ';
        return;
    }
    dfs(pre[v]);
    cout << v << ' ';
}
int main()
{
    fill(d, d+501, INF);
    fill(g[0], g[0]+550*550, INF);
    cin >> n >> m >> s >> dd;
    for(int i=0; i<m; i++){
        cin >> u >> v >> w >> cc;
        g[u][v] = g[v][u] = w;
        cost[u][v] = cost[v][u] = cc;
    }
    dijk();
    dfs(dd);
    cout << d[dd] << ' ' << c[dd];
    return 0;
}
/**
Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output
0 2 3 3 40
**/
