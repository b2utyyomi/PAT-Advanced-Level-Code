/**********************
author: yomi
date: 18.8.19
ps:
**********************/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1010;
vector<int>g[maxn];
int no[maxn], n;
bool vis[maxn];

void dfs(int index)
{
    if(index == n+1)
        return;
    if(!vis[index]){
        vis[index] = true;
        for(int i=0; i<g[index].size(); i++){
            dfs(g[index][i]);
        }
    }
}
int main()
{
    int m, k, u, v, d, cnt = 0;
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=m; i++){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=k; i++){
        cnt = 0;
        memset(vis, 0, sizeof(vis));
        scanf("%d", &d);
        vis[d] = true;
        for(int j=1; j<=n; j++){
            if(vis[j]){
                continue;
            }
            dfs(j);
            cnt++;
        }
        cout << cnt-1 << endl;
    }

    return 0;
}
/**
Sample Input
3 2 3
1 2
1 3
1 2 3
Sample Output
1
0
0
**/
