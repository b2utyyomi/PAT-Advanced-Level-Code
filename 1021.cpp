/**********************
author: yomi
date: 18.8.20
ps:
**********************/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 10010;

vector<int>g[maxn];
bool vis[maxn];
int ans[maxn];
int depth = 1, n, now;
void dfs(int index)
{
    if(vis[index] == true)
        return;
    vis[index] = true;
    for(int i=0; i<g[index].size(); i++){
        if(!vis[g[index][i]]){
            depth++;
            ans[now] = max(ans[now], depth);
            dfs(g[index][i]);
            depth--;
        }
    }
}

int main()
{
    int u, v, cnt=1;
    memset(ans, 0, sizeof(ans));
    memset(vis, 0, sizeof(vis));
    cin >> n;
    for(int i=0; i<n-1; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=n; i++){

        if(!vis[i]){
            dfs(i);
            cnt++;
        }
    }
    if(cnt-1>1){
        cout << "Error: " << cnt-1 << " components";
    }
    else{
        for(int i=1; i<=n; i++){
            memset(vis, 0, sizeof(vis));
            now = i;
            dfs(i);
        }
        int Max = 0;
        for(int i=1; i<=n; i++){
            Max = max(Max, ans[i]);
        }
        for(int i=1; i<=n; i++){
            if(Max == ans[i])
                cout << i << endl;
        }
    }

    return 0;
}
/**
Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components
**/
