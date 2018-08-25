/**********************
author: yomi
date: 18.8.24
ps:
**********************/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 510;
int g[maxn][maxn], d[maxn], num=0, weight[maxn], w=0;
int n, m, c1, c2;
bool vis[maxn];
const int INF = 0x3fffffff;
vector<int>path, temppath;
vector<int>pre[maxn];
void dijk()
{
    d[c1] = 0;
    for(int i=0; i<n; i++){
        int u=-1, Min = INF;
        for(int j=0; j<n; j++){
            if(!vis[j] && d[j] < Min){
                Min = d[j];
                u = j;
            }
        }
        if(u == -1)
            return;
        vis[u] = true;
        for(int v=0; v<n; v++){
            if(vis[v] || g[u][v]==INF){
                continue;
            }
            if(d[u]+g[u][v] < d[v]){
                d[v] = d[u]+g[u][v];
                pre[v].clear();
                pre[v].push_back(u);
            }
            else if(d[u]+g[u][v] == d[v]){
                pre[v].push_back(u);
            }
        }
    }
}
void dfs(int v)
{
    if(v == c1){
        temppath.push_back(c1);
        int value = 0;
        for(int i=temppath.size()-1; i>=0; i--){
            ///value += weight[i]; 弱智错误 ---> temppath里面存的才是真正的编号
            value += weight[temppath[i]];
        }
        if(value > w){
            w = value;
            path = temppath;
        }
        num++;
        temppath.pop_back();
        return;
    }
    temppath.push_back(v);
    for(int i=0; i<pre[v].size(); i++){
        dfs(pre[v][i]);
    }
    temppath.pop_back();

}
int main()
{
    int u, v, ww;
    fill(d, d+maxn, INF);
    fill(g[0], g[0]+maxn*maxn, INF);
    cin >> n >> m >> c1 >> c2;
    for(int i=0; i<n; i++){
        cin >> weight[i];
    }
    for(int i=0; i<m; i++){
        cin >> u >> v >> ww;
        g[u][v] = g[v][u] = ww;
    }
    dijk();
    dfs(c2);
    cout << num << ' ' << w;
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
