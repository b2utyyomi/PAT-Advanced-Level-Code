/**********************
author: yomi
date: 18.2.26
ps:
**********************/
#include <iostream>
#include <cstring>
using namespace std;
const int inf = 9999999;
int weight[501], e[501][501], dis[501], w[501], num[501];
bool vis[501];
int main()
{
    int n, m, c1, c2, a, b, d;
    memset(e, inf, sizeof(e));
    memset(dis, inf, sizeof(dis));
    memset(vis, false, sizeof(vis));
    cin >> n >> m >> c1 >> c2;
    for(int i=0; i<n; i++){
        cin >> weight[i];
    }
    for(int i=0; i<m; i++){
        cin >> a >> b >> d;
        e[a][b] = d;
        e[b][a] = d;
    }
    num[c1] = 1;
    dis[c1] = 0;
    w[c1] = weight[c1];
    for(int i=0; i<n; i++){
        int u = -1, v, min_ = inf;
        for(int j=0; j<n; j++){
            if(!vis[j] && dis[j] < min_){
                u = j;
                min_ = dis[j];
            }
        }
        if(u == -1)
            break;
        vis[u] = true;
        for(v=0; v<n; v++){
            if(!vis[v] && e[u][v]+dis[u] < dis[v]){
                dis[v] = e[u][v]+dis[u];
                num[v] = num[u];//
                w[v] = weight[v]+w[u];
            }
            else if(!vis[v] && e[u][v]+dis[u] == dis[v]){
                num[v] = num[u]+num[v];
                if(w[u]+weight[v] > w[v]){
                    w[v] = w[u]+weight[v];
                }
            }
        }
    }
    cout << num[c2] << ' ' << w[c2];
    return 0;
}

/**
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
**/
