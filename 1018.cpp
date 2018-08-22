/**********************
author: yomi
date: 18.8.22
ps: 思路非常清晰 只会简单dijksta的我 不得不停止做题 去学dijkstra+DFS的模板啊
然后还四hin悲催 本题下标为0~n 我写成0~n-1 找BUG15分钟
然而还是很开心 因为我以前都是照着题解找BUG
25分 T^T
这个这个这个。掉进了陷阱里。
如果最短路径有多个，求能带的最少的自行车数目的那条。
如果还是有很多条不同的路，那么就找一个从车站带回的自行车数目最少的。
带回的时候是不调整的。
看了题解。。。 我的错误之处就是dfs的核心部分 这部分代码和以前做过的加油站的题挺像
**********************/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 501;
const int INF = 0x3fffffff;
int g[maxn][maxn], d[maxn], weight[maxn], minNeed=INF, minRemain=INF;
vector<int>pre[maxn];
vector<int>path, temppath;
int c, n, p, m, optvalue, ans;
bool vis[maxn];
void dijk()
{
    d[0] = 0;
    for(int i=0; i<=n; i++){
        int u=-1, Min=INF;
        for(int j=0; j<=n; j++){
            if(!vis[j] && d[j]<Min){
                Min = d[j];
                u = j;
            }
        }
        if(u == -1)
            return;
        vis[u] = true;
        for(int v=0; v<=n; v++){
            if(vis[v]|| g[u][v]==INF){
                continue;
            }
            if(d[u]+g[u][v]<d[v]){
                d[v] = d[u]+g[u][v];
                pre[v].clear();
                pre[v].push_back(u);
            }
            else if(d[v] == d[u]+g[u][v]){
                pre[v].push_back(u);
            }
        }
    }
}
void dfs(int v)
{
    if(v == 0){
        temppath.push_back(v);
        int need=0, remain=0;
        for(int i=temppath.size()-1; i>=0; i--){
            int id = temppath[i];
            if(weight[id] > 0){
                remain += weight[id];
            }
            else{
                if(remain > abs(weight[id])){
                    remain -= abs(weight[id]);
                }
                else{
                    need += abs(weight[id])-remain;
                    remain = 0;
                }
            }
        }
        if(need < minNeed){
            minNeed = need;
            minRemain = remain;
            path = temppath;
        }
        else if(need==minNeed && remain<minRemain){
            minRemain = remain;
            path = temppath;
        }

        temppath.pop_back();
        return;
    }
    temppath.push_back(v);
    int s = pre[v].size();
    for(int i=0; i<s; i++){
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}
int main()
{
    fill(d, d+maxn, INF);
    fill(g[0], g[0]+maxn*maxn, INF);
    fill(weight, weight+maxn, 0);
    cin >> c >> n >> p >> m;
    int da, per=c/2;
    int u, v, w;
    optvalue = INF;
    for(int i=1; i<=n; i++){
        cin >> da;
        weight[i] = da-per;
    }
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }
    dijk();
    dfs(p);
    cout << minNeed << ' ';
    for(int i=path.size()-1; i>0; i--){
        cout << path[i] << "->";
    }
    cout << p << ' ';
    cout << minRemain;

    return 0;
}
/**
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
**/
