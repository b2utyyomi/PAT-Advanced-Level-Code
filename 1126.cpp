/******************************
author:yomi
date:18.9.1
ps: 完了完了完了 一看题解恍然大悟 不该不该 可怜了我的一百分 最终只有九十五 连通图判断找dfs啊这怎么瞎用上入度了 完全没法判断的好吗
可惜可惜

******************************/
#include <cstring>
#include<iostream>
using namespace std;

const int maxn = 510;
int g[maxn][maxn];
int deg[maxn];
bool vis[maxn];
int n, m, u, v;
void dfs(int index)
{
    if(index == n+1 || vis[index]){
        return;
    }
    vis[index] = true;
    for(int i=1; i<=n; i++){
        if(g[index][i] == 1){
            dfs(i);
        }
    }
}
int main()
{

    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        deg[v]++;
        deg[u]++;
        g[u][v] = g[v][u] = 1;
    }
    int oddnum = 0;
    int flag = 0;
    for(int i=1; i<n; i++){
        cout << deg[i] << ' ';
        if(deg[i] == 0){
            flag = 1;
        }
        if(deg[i]%2)
            oddnum++;
    }
    cout << deg[n] << endl;
    if(deg[n]%2){
        oddnum++;
    }
    memset(vis, false, sizeof(vis));
    dfs(1);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            flag = 1;
        }
    }
    if(flag == 1){
        cout << "Non-Eulerian";
    }
    else{
        if(oddnum == 0){
            cout << "Eulerian";
        }
        else if(oddnum == 2){
            cout << "Semi-Eulerian";
        }
        else{
            cout << "Non-Eulerian";
        }

    }


    return 0;
}
/**
7 12
5 7
1 2
1 3
2 3
2 4
3 4
5 2
7 6
6 3
4 5
6 4
5 6

**/
