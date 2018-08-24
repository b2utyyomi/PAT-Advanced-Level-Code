/**********************
author: yomi
date: 18.8.23
ps:
**********************/
#include <iostream>
#include <vector>
using namespace std;
const int INF = 0x3fffffff;
int g[550][550], d[501], c[501], cost[550][550];
bool vis[501];
int n, m, s, dd, u, v, w, cc, optValue=INF;
vector<int>pre[550];
vector<int>path, temppath;
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
    if(v == s)
    {
        temppath.push_back(s);
        int value = 0;
        //cout << temppath.size() << endl;
        for(int i=temppath.size()-1; i>0; i--){
            int id = temppath[i], next=temppath[i-1];
            value += cost[id][next];
        }
        if(optValue > value){
            optValue = value;
            path = temppath;
        }
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
    //cout << path.size() << endl;
    for(int i=path.size()-1; i>=0; i--){
        cout << path[i] << ' ';
    }
    cout << d[dd] << ' ' << optValue;
    return 0;
}
