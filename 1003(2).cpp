/**********************
author: yomi
date: 18.3.13
ps: 就只过了样例好几次 原来是dijkstra写错了 大错不少 小错也不断 真得多刷几遍
**********************/
#include <iostream>
#include <cstring>

using namespace std;

int weight[501], e[501][501], dis[501], num[501], w[501];
bool vis[501];
const int inf = 9999999;
int main()
{

    int n, m, c1, c2, a, b, d;
    memset(vis, false, sizeof(vis));
    memset(dis, inf, sizeof(dis));
    memset(e, inf, sizeof(e));
////    memset(num, 0, sizeof(num));
////    memset(w, 0, sizeof(w));
    cin >> n >> m >> c1 >> c2;
    for(int i=0; i<n; i++){
        cin >> weight[i];
    }
    for(int i=0; i<m; i++){
        cin >> a >> b >> d;
        e[a][b] = e[b][a] = d;
    }
    num[c1] = 1;
    dis[c1] = 0;
    w[c1] = weight[c1];
    for(int i=0; i<n; i++){
        int u = -1, min_ = inf;
        for(int j=0; j<n; j++){
            if(!vis[j] && dis[j] < min_){
                min_ = dis[j];
                u = j;
            }
        }


        if(u==-1){
            break;
        }
        vis[u] = true;
        for(int v=0; v<n; v++){
            if(!vis[v] && dis[u]+e[u][v] < dis[v]){
                dis[v] = dis[u] + e[u][v];
                num[v] = num[u];
                //if(w[u] + weight[v] > w[v]){怎么能加这个判断呢 需要无条件选最短路径呀
                    w[v] = w[u]+weight[v];  //营救队数量必须随之更新
                //}
            }
            else if(!vis[v] && dis[u] + e[u][v] == dis[v]){
                //num[v] = num[u]+1; 这又错了呀
                num[v] += num[u];
                if(w[u] + weight[v] > w[v]){
                    w[v] = w[u]+weight[v];
                }
            }
        }
    }
    cout << num[c2] << ' ' << w[c2];
    //cout << dis[c2] << endl;
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
