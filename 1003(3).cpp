/**********************
author: yomi
date: 18.8.21
ps: INF要大写 不然编译错误 maxn不要太大 不然内存超限
**********************/
#include <iostream>
#include <cstdio>
using namespace std;
const int INF = 0x3fffffff;
const int maxn = 501;

int n, m, c1, c2;
int d[maxn], weight[maxn], w[maxn], num[maxn], g[maxn][maxn];
bool vis[maxn];
void Dijkstra()
{
    d[c1] = 0;
    num[c1] = 1;
    w[c1] = weight[c1];
    for(int i=0; i<n; i++){
        int u = -1, Min = INF;
        for(int j=0; j<n; j++){
            if(!vis[j] && d[j]<Min){
                u = j;
                Min = d[j];
            }
        }
        if(u == -1)
            return;
        vis[u] = true;
        for(int v=0; v<n; v++){
            if(vis[v] || g[u][v]==INF)
                continue;
            if(d[u]+g[u][v]<d[v]){
                d[v] = d[u]+g[u][v];
                num[v] = num[u];
                w[v] = w[u]+weight[v];
            }
            else if(d[u]+g[u][v]==d[v]){
                num[v] += num[u];
                if(w[u]+weight[v]>w[v])
                    w[v] = w[u]+weight[v];
            }
        }
    }

}
int main()
{
    cin >> n >> m >> c1 >> c2;
    int u, v, ww;
    fill(d, d+maxn, INF);
    fill(g[0], g[0]+maxn*maxn, INF);
    for(int i=0; i<n; i++){
        cin >> weight[i];
    }
    for(int i=0; i<m; i++){
        cin >> u >> v >> ww;
        g[u][v] = g[v][u] = ww;
    }
    Dijkstra();
    cout << num[c2] << ' ' << w[c2];
    return 0;
}
/**
Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
**/
