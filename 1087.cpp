/**********************
author: yomi
date: 18.8.26
ps: 整整35分钟 敲敲敲 一次过 呵哈哈哈
**********************/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
const int maxn = 210;
int n, m, num;
const int INF = 0x3fffffff;
int d[maxn], g[maxn][maxn], weight[maxn], ww;
double avgww;
bool vis[maxn];
vector<int>temppath, path;
vector<int>pre[maxn];
map<string, int>mmap1;
map<int, string>mmap2;
int toInt(string s)
{
    int id = mmap1.size();
    if(mmap1.find(s) == mmap1.end()){
        mmap1[s] = id;
        return id;
    }
    else{
        return mmap1[s];
    }
}
string toString(int id)
{
    return mmap2[id];
}
void dijk()
{
    fill(d, d+maxn, INF);
    fill(vis, vis+maxn, false);
    d[0] = 0;
    for(int i=0; i<n; i++){
        int u =-1, Min = INF;
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
            if(vis[v] || g[u][v] == INF){
                continue;
            }
            if(d[u]+g[u][v] < d[v]){
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
        temppath.push_back(0);
        int value = 0;
        double avg = 0;
        for(int i=temppath.size()-1; i>=0; i--)
        {
            value += weight[temppath[i]];
        }
        //cout << temppath.size() << endl;
        avg = value*1.0/(temppath.size()-1);
        if(value > ww){
            ww = value;
            path = temppath;
            avgww = avg;
        }
        else if(value == ww && avgww < avg){
            ww = value;
            path = temppath;
            avgww = avg;
        }
        temppath.pop_back();
        num++;
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
    fill(g[0], g[0]+maxn*maxn, INF);
    string place;
    cin >> n >> m >> place;
    int id = toInt(place), rome;
    mmap2[id] = place;
    weight[id] = 0;
    for(int i=0; i<n-1; i++){
        cin >> place;
        id = toInt(place);
        mmap2[id] = place;
        cin >> weight[id];
        if(place == "ROM"){
            rome = id;
        }
    }
    string uu, vv;
    int u, v, w;
    for(int i=0; i<m; i++){
        cin >> uu >> vv >> w;
        u = toInt(uu);
        v = toInt(vv);
        g[u][v] = g[v][u] = w;
    }
//    for(int i=0; i<n; i++){
//        for(int j=0; j<n; j++){
//            if(g[i][j]!=INF){
//                cout << i << ' ' << j << ' ' << g[i][j] << endl;
//            }
//        }
//    }
    dijk();
    dfs(rome);
    cout << num << ' ' << d[rome] << ' ' << ww << ' ' << (int)avgww << endl;
    for(int i=path.size()-1; i>0; i--){
        cout << toString(path[i]) << "->";
    }
    cout << toString(path[0]);
    return 0;
}
/**
Sample Input:
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
Sample Output:
3 3 195 97
HZH->PRS->ROM
**/
